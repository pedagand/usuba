(***************************************************************************** )
                              expand_array.ml                                 

   This module has several main functionalities:
    - Convert arrays of nodes into multiple nodes. 
    - Convert forall into a list of regular instructions.
    - Convert Ranges into multiple Tuples of Fields.
    - Convert Slices into multiple Tuples of Fields.
    - Convert access to arrays (variables) into access to variables
      (for instance, a[0] will become a'0)
    
    After this module has ran, there souldn't be any "Index" variable left, 
    nor any "Multiple" node.

( *****************************************************************************)

open Usuba_AST
open Utils

       
let expand_var_array id size =
  List.map (fun x -> Var (x^"'")) (gen_list_0 id size)



let rec expand_var_range (v:var) : var list =
  
  let rec expand_range id i n acc =
    if i = n then
      List.rev (Var(id ^ (string_of_int i) ^ "'") :: acc)
    else
      expand_range id (i+1) n (Var(id ^ (string_of_int i) ^ "'") :: acc) in
  
  match v with
  | Range(id,Const_e ei,Const_e ef) -> expand_range id ei ef []
  | Slice(id,l) -> List.flatten @@
                     List.map
                     expand_var_range
                     (List.map (fun n -> Field(Var id,n)) l)
  | Field(v',e) -> ( match expand_var_range v' with
                     | x::[] -> [ Field(x,e) ]
                     | l -> List.map (fun x -> Field(x,e)) l )
  | _ -> [ v ]
           
           
let expand_pat_range (pat:var list) : var list =
  List.flatten @@ List.map expand_var_range pat

let rec expand_expr_range (e:expr) : expr =
  Norm_tuples.Simplify_tuples.simpl_tuple
    (match e with
     | Const _ -> e
     | ExpVar v -> Tuple(List.map (fun x -> ExpVar x) (expand_var_range v))
     | Tuple l -> Tuple (List.map expand_expr_range l)
     | Not e -> Not (expand_expr_range e)
     | Shift(op,e,n) -> Shift(op,expand_expr_range e,n)
     | Log(op,x,y) -> Log(op,expand_expr_range x,expand_expr_range y)
     | Arith(op,x,y) -> Arith(op,expand_expr_range x,expand_expr_range y)
     | Intr(op,x,y) -> Intr(op,expand_expr_range x,expand_expr_range y)
     | Fun(f,l) -> Fun(f,List.map expand_expr_range l)
     | Fun_v(f,n,l) -> Fun_v(f,n,List.map expand_expr_range l)
     | Fby(x,y,f) -> Fby(expand_expr_range x,expand_expr_range y,f)
     | Nop -> Nop
     | _ -> raise (Not_implemented (Usuba_print.expr_to_str e)))
          
let rec rewrite_expr loc_env env_var (e:expr) : expr =
  let rec_call = rewrite_expr loc_env env_var in
  match e with
  | Const _ -> e
  | ExpVar(Field(v,e)) -> ExpVar(Field(v,Const_e(eval_arith loc_env e)))
  | ExpVar(Var v) -> ( match env_fetch loc_env v with
                       | Some n -> Const n
                       | None ->
                          match env_fetch env_var v with
                          | Some size -> Tuple(List.map
                                                 (fun x -> ExpVar x)
                                                 (expand_var_array v size))
                          | None -> ExpVar(Var v))
  | ExpVar(Index(v,idx)) -> let n = eval_arith loc_env idx in
                            ExpVar(Var(v ^ (string_of_int n) ^ "'"))
  | ExpVar(Range(v,ei,ef)) ->
     ExpVar(Range(v, Const_e(eval_arith loc_env ei),
                  Const_e(eval_arith loc_env ef)))
  | ExpVar(Slice(v,l)) ->
     ExpVar(Slice(v,List.map (fun n -> Const_e(eval_arith loc_env n)) l))
  | Tuple l -> Tuple (List.map rec_call l)
  | Not e -> Not (rec_call e)
  | Log(op,x,y) -> Log(op,rec_call x,rec_call y)
  | Arith(op,x,y) -> let x' = rec_call x in
                     let y' = rec_call y in
                     ( match x',y' with
                       | Const a, Const b ->
                          (match op with
                           | Add -> Const (a + b)
                           | Mul -> Const (a * b)
                           | Sub -> Const (a - b)
                           | Div -> Const (a / b)
                           | Mod -> Const (a mod b))
                       | _ -> Arith(op,rec_call x,rec_call y) )
  | Shift(op,e,n) -> Shift(op,rec_call e, Const_e(eval_arith loc_env n))
  | Intr(f,x,y) -> Intr(f,rec_call x, rec_call y)
  | Fun(f,l) -> Fun(f,List.map rec_call l)
  | Fun_v(f,e,l) -> let idx = eval_arith loc_env e in
                    let f' = f ^ (string_of_int idx) in
                    rec_call (Fun(f',l))
  | Fby _ -> raise (Not_implemented "FBY")
  | Nop -> Nop
  | _ -> raise (Not_implemented (Usuba_print.expr_to_str e))
             

let rewrite_pat env env_var (pat:var list) : var list =
  let rec aux x = match x with
    | Var v -> (match env_fetch env_var v with
                | Some size -> expand_var_array v size
                | None -> [ Var v ])
    | Field(lasgn,i) -> let i' = eval_arith env i in
                        [ Field(List.nth (aux lasgn) 0,Const_e i') ]
    | Index(id,e) -> let n = eval_arith env e in
                     [ Var(id ^ (string_of_int n) ^ "'") ] 
    | Range(id,ei,ef) -> [ Range(id,Const_e(eval_arith env ei),
                                 Const_e(eval_arith env ef))]
    | Slice(id,l) -> [ Slice(id,List.map (fun n -> Const_e(eval_arith env n)) l) ] in
  List.flatten @@ List.map aux pat
           
let rewrite_rec env_var (iterator:ident) (startr:arith_expr) (endr:arith_expr)
                (pat:var list) (e:expr) : deq list =
  let env = Hashtbl.create 10 in
  let i_init = eval_arith env startr in
  let i_end  = eval_arith env endr in
  let body = ref [] in
  for i = i_init to i_end do
    env_add env iterator i;
    let pat_i  = rewrite_pat env env_var pat in
    let expr_i = rewrite_expr env env_var e in
    body := !body @ [ Norec(pat_i, expr_i) ]
  done;
  !body

let rec rewrite_p p =
  List.flatten @@
    List.map
      (fun ((id,typ),ck) ->
        match typ with
        | Bool -> [ ((id,Bool),ck) ]
        | Int n -> [ ((id, Int n), ck) ]
        | Nat -> [ ((id, Nat), ck) ]
        | Array (typ_in, Const_e size) ->
           List.map (fun x -> ((x^"'",typ_in),ck)) (gen_list_0 id size)
        | _ -> raise (Error "Invalid array size")) p

let make_env p_in p_out vars =
  let env = Hashtbl.create 10 in
  let f = List.iter (fun ((id,typ),ck) ->
               match typ with
               | Array(in_typ,Const_e size) -> env_add env id size
               | _ -> ()) in
  let () = f p_in in
  let () = f p_out in
  let () = f vars in
  env
  
let rewrite_deqs p_in p_out vars (deqs:deq list) : deq list =
  let env_var = make_env p_in p_out vars in
  let rec aux env deq =
    match deq with
    | Norec(vars,e) ->
       [ Norec(rewrite_pat env env_var vars,
               rewrite_expr env env_var e) ]
    | Rec(i,startr,endr,d) ->
       let i_init = eval_arith env startr in
       let i_end  = eval_arith env endr in
       List.flatten @@
         List.map (fun v -> Hashtbl.add env i v;
                            let l = List.flatten @@ List.map (aux env) d in
                            Hashtbl.remove env i;
                            l) (gen_list_bound i_init i_end)
  in
  List.flatten @@
    List.map (fun x -> aux (Hashtbl.create 10) x) deqs
  
(* let rewrite_deqs p_in p_out vars (deqs:deq list) : deq list = *)
(*   let env_var = make_env p_in p_out vars in *)
(*   List.flatten @@ *)
(*     List.map (fun x -> match x with *)
(*                        | Rec(i,startr,endr,d) -> *)
(*                           List.flatten @@ *)
(*                             List.map (fun x -> *)
(*                                       match x with *)
(*                                       | Norec(lhs,e) -> rewrite_rec env_var i startr endr lhs e *)
(*                                       | Rec _ -> raise (Not_implemented "nested forall")) d *)
(*                        | Norec(vars,e) -> *)
(*                           [ Norec(rewrite_pat (Hashtbl.create 1) env_var vars, *)
(*                                   rewrite_expr (Hashtbl.create 1) env_var e) ]) deqs *)

let expand_def (def:def) : def =
  match def.node with
  | Single(vars,body) ->
     { def with p_in = rewrite_p def.p_in;
                p_out = rewrite_p def.p_out;
                node = Single(rewrite_p vars,
                              rewrite_deqs def.p_in def.p_out vars body ) }
  | _ -> def
       
let expand_array (prog: prog) : prog =
  let prog' = (* expansion of the arrays of nodes *)
    List.flatten @@
      List.map (fun x -> match x.node with
                         | Multiple nodes ->
                            List.mapi (fun i (vars,body) ->
                                       { x with id = x.id ^ (string_of_int i);
                                                node = Single(vars,body) }) nodes
                         | _ -> [ x ] ) prog.nodes in
  let expanded =
    List.map (fun def ->
              match def.node with
              | Single(vars,body) ->
                 { def with p_in = rewrite_p def.p_in;
                            p_out = rewrite_p def.p_out;
                            node = Single(rewrite_p vars,
                                          rewrite_deqs def.p_in def.p_out vars body ) }
              | _ -> def) prog' in
  { nodes =
      List.map (fun def ->
                match def.node with
                | Single(vars,body) ->
                   { def with node =  Single(vars,
                                             List.map (fun x -> match x with
                                                                | Norec(pat,e) ->
                                                                   Norec(expand_pat_range pat,
                                                                         expand_expr_range e)
                                                                | _ -> x) body) }
                | _ -> def) expanded }
    
