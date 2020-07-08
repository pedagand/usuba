/* This code was generated by Usuba.
   See https://github.com/DadaIsCrazy/usuba.
   From the file "samples/usuba/aes_generic.ua" (included below). */

#include <stdint.h>

/* Do NOT change the order of those define/include */

#ifndef BITS_PER_REG
#define BITS_PER_REG 16
#endif
/* including the architecture specific .h */
#include "MASKED_UA.h"

/* auxiliary functions */
void SubBytes__V16 (/*inputs*/ DATATYPE U0__[MASKING_ORDER],DATATYPE U1__[MASKING_ORDER],DATATYPE U2__[MASKING_ORDER],DATATYPE U3__[MASKING_ORDER],DATATYPE U4__[MASKING_ORDER],DATATYPE U5__[MASKING_ORDER],DATATYPE U6__[MASKING_ORDER],DATATYPE U7__[MASKING_ORDER], /*outputs*/ DATATYPE S0__[MASKING_ORDER],DATATYPE S1__[MASKING_ORDER],DATATYPE S2__[MASKING_ORDER],DATATYPE S3__[MASKING_ORDER],DATATYPE S4__[MASKING_ORDER],DATATYPE S5__[MASKING_ORDER],DATATYPE S6__[MASKING_ORDER],DATATYPE S7__[MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp1_[MASKING_ORDER];
  DATATYPE _tmp2_[MASKING_ORDER];
  DATATYPE _tmp3_[MASKING_ORDER];
  DATATYPE _tmp4_[MASKING_ORDER];
  DATATYPE t0__;
  DATATYPE t1__;
  DATATYPE t10__[MASKING_ORDER];
  DATATYPE t11__;
  DATATYPE t12__[MASKING_ORDER];
  DATATYPE t13__[MASKING_ORDER];
  DATATYPE t14__;
  DATATYPE t15__[MASKING_ORDER];
  DATATYPE t16__;
  DATATYPE t17__[MASKING_ORDER];
  DATATYPE t18__;
  DATATYPE t19__;
  DATATYPE t2__[MASKING_ORDER];
  DATATYPE t20__;
  DATATYPE t21__[MASKING_ORDER];
  DATATYPE t22__[MASKING_ORDER];
  DATATYPE t23__[MASKING_ORDER];
  DATATYPE t24__[MASKING_ORDER];
  DATATYPE t25__[MASKING_ORDER];
  DATATYPE t26__[MASKING_ORDER];
  DATATYPE t27__[MASKING_ORDER];
  DATATYPE t28__[MASKING_ORDER];
  DATATYPE t29__[MASKING_ORDER];
  DATATYPE t3__[MASKING_ORDER];
  DATATYPE t30__[MASKING_ORDER];
  DATATYPE t31__[MASKING_ORDER];
  DATATYPE t32__[MASKING_ORDER];
  DATATYPE t33__[MASKING_ORDER];
  DATATYPE t34__[MASKING_ORDER];
  DATATYPE t35__[MASKING_ORDER];
  DATATYPE t36__[MASKING_ORDER];
  DATATYPE t37__[MASKING_ORDER];
  DATATYPE t38__[MASKING_ORDER];
  DATATYPE t39__[MASKING_ORDER];
  DATATYPE t4__;
  DATATYPE t40__[MASKING_ORDER];
  DATATYPE t41__[MASKING_ORDER];
  DATATYPE t42__[MASKING_ORDER];
  DATATYPE t43__[MASKING_ORDER];
  DATATYPE t44__[MASKING_ORDER];
  DATATYPE t45__[MASKING_ORDER];
  DATATYPE t5__[MASKING_ORDER];
  DATATYPE t6__[MASKING_ORDER];
  DATATYPE t7__[MASKING_ORDER];
  DATATYPE t8__[MASKING_ORDER];
  DATATYPE t9__;
  DATATYPE tc1__;
  DATATYPE tc10__;
  DATATYPE tc11__;
  DATATYPE tc12__;
  DATATYPE tc13__;
  DATATYPE tc14__;
  DATATYPE tc16__;
  DATATYPE tc17__;
  DATATYPE tc18__;
  DATATYPE tc2__;
  DATATYPE tc20__;
  DATATYPE tc21__;
  DATATYPE tc26__;
  DATATYPE tc3__;
  DATATYPE tc4__[MASKING_ORDER];
  DATATYPE tc5__[MASKING_ORDER];
  DATATYPE tc6__;
  DATATYPE tc7__;
  DATATYPE tc8__;
  DATATYPE tc9__;
  DATATYPE y1__[MASKING_ORDER];
  DATATYPE y10__[MASKING_ORDER];
  DATATYPE y11__[MASKING_ORDER];
  DATATYPE y12__[MASKING_ORDER];
  DATATYPE y13__[MASKING_ORDER];
  DATATYPE y14__[MASKING_ORDER];
  DATATYPE y15__[MASKING_ORDER];
  DATATYPE y16__[MASKING_ORDER];
  DATATYPE y17__[MASKING_ORDER];
  DATATYPE y18__[MASKING_ORDER];
  DATATYPE y19__[MASKING_ORDER];
  DATATYPE y2__[MASKING_ORDER];
  DATATYPE y20__[MASKING_ORDER];
  DATATYPE y21__[MASKING_ORDER];
  DATATYPE y3__[MASKING_ORDER];
  DATATYPE y4__[MASKING_ORDER];
  DATATYPE y5__[MASKING_ORDER];
  DATATYPE y6__[MASKING_ORDER];
  DATATYPE y7__[MASKING_ORDER];
  DATATYPE y8__[MASKING_ORDER];
  DATATYPE y9__[MASKING_ORDER];
  DATATYPE z0__[MASKING_ORDER];
  DATATYPE z1__[MASKING_ORDER];
  DATATYPE z10__[MASKING_ORDER];
  DATATYPE z11__[MASKING_ORDER];
  DATATYPE z12__[MASKING_ORDER];
  DATATYPE z13__[MASKING_ORDER];
  DATATYPE z14__[MASKING_ORDER];
  DATATYPE z15__[MASKING_ORDER];
  DATATYPE z16__[MASKING_ORDER];
  DATATYPE z17__[MASKING_ORDER];
  DATATYPE z2__[MASKING_ORDER];
  DATATYPE z3__[MASKING_ORDER];
  DATATYPE z4__[MASKING_ORDER];
  DATATYPE z5__[MASKING_ORDER];
  DATATYPE z6__[MASKING_ORDER];
  DATATYPE z7__[MASKING_ORDER];
  DATATYPE z8__[MASKING_ORDER];
  DATATYPE z9__[MASKING_ORDER];

  // Instructions (body)
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    y14__[_mask_idx] = XOR(U3__[_mask_idx],U5__[_mask_idx]);
    y13__[_mask_idx] = XOR(U0__[_mask_idx],U6__[_mask_idx]);
    y9__[_mask_idx] = XOR(U0__[_mask_idx],U3__[_mask_idx]);
    y8__[_mask_idx] = XOR(U0__[_mask_idx],U5__[_mask_idx]);
    t0__ = XOR(U1__[_mask_idx],U2__[_mask_idx]);
    y12__[_mask_idx] = XOR(y13__[_mask_idx],y14__[_mask_idx]);
    y1__[_mask_idx] = XOR(t0__,U7__[_mask_idx]);
    t1__ = XOR(U4__[_mask_idx],y12__[_mask_idx]);
    y4__[_mask_idx] = XOR(y1__[_mask_idx],U3__[_mask_idx]);
    y2__[_mask_idx] = XOR(y1__[_mask_idx],U0__[_mask_idx]);
    y5__[_mask_idx] = XOR(y1__[_mask_idx],U6__[_mask_idx]);
    y15__[_mask_idx] = XOR(t1__,U5__[_mask_idx]);
    y20__[_mask_idx] = XOR(t1__,U1__[_mask_idx]);
    y3__[_mask_idx] = XOR(y5__[_mask_idx],y8__[_mask_idx]);
    y6__[_mask_idx] = XOR(y15__[_mask_idx],U7__[_mask_idx]);
    y10__[_mask_idx] = XOR(y15__[_mask_idx],t0__);
    y11__[_mask_idx] = XOR(y20__[_mask_idx],y9__[_mask_idx]);
    y19__[_mask_idx] = XOR(y10__[_mask_idx],y8__[_mask_idx]);
    y7__[_mask_idx] = XOR(U7__[_mask_idx],y11__[_mask_idx]);
    y17__[_mask_idx] = XOR(y10__[_mask_idx],y11__[_mask_idx]);
    y16__[_mask_idx] = XOR(t0__,y11__[_mask_idx]);
    y21__[_mask_idx] = XOR(y13__[_mask_idx],y16__[_mask_idx]);
    y18__[_mask_idx] = XOR(U0__[_mask_idx],y16__[_mask_idx]);
  }
  MASKED_AND(t5__,y4__,U7__);
  MASKED_AND(t8__,y5__,y1__);
  MASKED_AND(t2__,y12__,y15__);
  MASKED_AND(t3__,y3__,y6__);
  MASKED_AND(t15__,y8__,y10__);
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    t6__[_mask_idx] = XOR(t5__[_mask_idx],t2__[_mask_idx]);
    t4__ = XOR(t3__[_mask_idx],t2__[_mask_idx]);
    t17__[_mask_idx] = XOR(t4__,y20__[_mask_idx]);
  }
  MASKED_AND(t12__,y9__,y11__);
  MASKED_AND(t10__,y2__,y7__);
  MASKED_AND(t13__,y14__,y17__);
  MASKED_AND(t7__,y13__,y16__);
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    t16__ = XOR(t15__[_mask_idx],t12__[_mask_idx]);
    t14__ = XOR(t13__[_mask_idx],t12__[_mask_idx]);
    t9__ = XOR(t8__[_mask_idx],t7__[_mask_idx]);
    t11__ = XOR(t10__[_mask_idx],t7__[_mask_idx]);
    t18__ = XOR(t6__[_mask_idx],t16__);
    t21__[_mask_idx] = XOR(t17__[_mask_idx],t14__);
    t19__ = XOR(t9__,t14__);
    t20__ = XOR(t11__,t16__);
    t22__[_mask_idx] = XOR(t18__,y19__[_mask_idx]);
    t23__[_mask_idx] = XOR(t19__,y21__[_mask_idx]);
    t24__[_mask_idx] = XOR(t20__,y18__[_mask_idx]);
    t25__[_mask_idx] = XOR(t21__[_mask_idx],t22__[_mask_idx]);
    t30__[_mask_idx] = XOR(t23__[_mask_idx],t24__[_mask_idx]);
  }
  MASKED_AND(t26__,t21__,t23__);
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    t27__[_mask_idx] = XOR(t24__[_mask_idx],t26__[_mask_idx]);
    t31__[_mask_idx] = XOR(t22__[_mask_idx],t26__[_mask_idx]);
  }
  MASKED_AND(t28__,t25__,t27__);
  MASKED_AND(t32__,t31__,t30__);
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    t29__[_mask_idx] = XOR(t28__[_mask_idx],t22__[_mask_idx]);
    t33__[_mask_idx] = XOR(t32__[_mask_idx],t24__[_mask_idx]);
    t34__[_mask_idx] = XOR(t23__[_mask_idx],t33__[_mask_idx]);
    t35__[_mask_idx] = XOR(t27__[_mask_idx],t33__[_mask_idx]);
    t42__[_mask_idx] = XOR(t29__[_mask_idx],t33__[_mask_idx]);
  }
  MASKED_AND(z5__,t29__,y7__);
  MASKED_AND(z14__,t29__,y2__);
  MASKED_AND(z2__,t33__,U7__);
  MASKED_AND(z11__,t33__,y4__);
  MASKED_AND(t36__,t24__,t35__);
  MASKED_AND(z6__,t42__,y11__);
  MASKED_AND(z15__,t42__,y9__);
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    t37__[_mask_idx] = XOR(t36__[_mask_idx],t34__[_mask_idx]);
    t38__[_mask_idx] = XOR(t27__[_mask_idx],t36__[_mask_idx]);
    t44__[_mask_idx] = XOR(t33__[_mask_idx],t37__[_mask_idx]);
  }
  MASKED_AND(z1__,t37__,y6__);
  MASKED_AND(z10__,t37__,y3__);
  MASKED_AND(t39__,t29__,t38__);
  MASKED_AND(z0__,t44__,y15__);
  MASKED_AND(z9__,t44__,y12__);
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    t40__[_mask_idx] = XOR(t25__[_mask_idx],t39__[_mask_idx]);
    tc4__[_mask_idx] = XOR(z0__[_mask_idx],z2__[_mask_idx]);
    tc5__[_mask_idx] = XOR(z1__[_mask_idx],z0__[_mask_idx]);
    t41__[_mask_idx] = XOR(t40__[_mask_idx],t37__[_mask_idx]);
    t43__[_mask_idx] = XOR(t29__[_mask_idx],t40__[_mask_idx]);
    t45__[_mask_idx] = XOR(t42__[_mask_idx],t41__[_mask_idx]);
  }
  MASKED_AND(z4__,t40__,y1__);
  MASKED_AND(z13__,t40__,y5__);
  MASKED_AND(z8__,t41__,y10__);
  MASKED_AND(z17__,t41__,y8__);
  MASKED_AND(z3__,t43__,y16__);
  MASKED_AND(z12__,t43__,y13__);
  MASKED_AND(z7__,t45__,y17__);
  MASKED_AND(z16__,t45__,y14__);
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    tc6__ = XOR(z3__[_mask_idx],z4__[_mask_idx]);
    tc12__ = XOR(z3__[_mask_idx],z5__[_mask_idx]);
    tc7__ = XOR(z12__[_mask_idx],tc4__[_mask_idx]);
    tc1__ = XOR(z15__[_mask_idx],z16__[_mask_idx]);
    tc8__ = XOR(z7__[_mask_idx],tc6__);
    tc11__ = XOR(tc6__,tc5__[_mask_idx]);
    tc14__ = XOR(tc4__[_mask_idx],tc12__);
    tc9__ = XOR(z8__[_mask_idx],tc7__);
    tc2__ = XOR(z10__[_mask_idx],tc1__);
    tc13__ = XOR(z13__[_mask_idx],tc1__);
    tc16__ = XOR(z6__[_mask_idx],tc8__);
    tc10__ = XOR(tc8__,tc9__);
    tc3__ = XOR(z9__[_mask_idx],tc2__);
    tc21__ = XOR(tc2__,z11__[_mask_idx]);
    tc18__ = XOR(tc13__,tc14__);
    tc20__ = XOR(z15__[_mask_idx],tc16__);
    tc17__ = XOR(z14__[_mask_idx],tc10__);
    S3__[_mask_idx] = XOR(tc3__,tc11__);
    S0__[_mask_idx] = XOR(tc3__,tc16__);
    _tmp1_[_mask_idx] = XOR(z12__[_mask_idx],tc18__);
    _tmp2_[_mask_idx] = XOR(tc10__,tc18__);
    tc26__ = XOR(tc17__,tc20__);
    S5__[_mask_idx] = XOR(tc21__,tc17__);
    S4__[_mask_idx] = XOR(tc14__,S3__[_mask_idx]);
    _tmp3_[_mask_idx] = XOR(S3__[_mask_idx],tc16__);
    _tmp4_[_mask_idx] = XOR(tc26__,z17__[_mask_idx]);
  }
  S7__[0] = NOT(_tmp1_[0]);
  for (int _mask_idx = 1; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    S7__[_mask_idx] = _tmp1_[_mask_idx];
    S6__[_mask_idx] = _tmp2_[_mask_idx];
    S1__[_mask_idx] = _tmp3_[_mask_idx];
    S2__[_mask_idx] = _tmp4_[_mask_idx];
  }
  S6__[0] = NOT(_tmp2_[0]);
  S1__[0] = NOT(_tmp3_[0]);
  S2__[0] = NOT(_tmp4_[0]);

}

void MixColumn__V16 (/*inputs*/ DATATYPE a__[8][MASKING_ORDER], /*outputs*/ DATATYPE b__[8][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE _tmp11_;
  DATATYPE _tmp12_;
  DATATYPE _tmp17_;
  DATATYPE _tmp18_;
  DATATYPE _tmp19_;
  DATATYPE _tmp21_;
  DATATYPE _tmp22_;
  DATATYPE _tmp25_;
  DATATYPE _tmp26_;
  DATATYPE _tmp28_;
  DATATYPE _tmp29_;
  DATATYPE _tmp34_;
  DATATYPE _tmp35_;
  DATATYPE _tmp36_;
  DATATYPE _tmp38_;
  DATATYPE _tmp39_;
  DATATYPE _tmp44_;
  DATATYPE _tmp45_;
  DATATYPE _tmp46_;
  DATATYPE _tmp48_;
  DATATYPE _tmp49_;
  DATATYPE _tmp52_;
  DATATYPE _tmp53_;
  DATATYPE _tmp55_;
  DATATYPE _tmp56_;
  DATATYPE _tmp59_;
  DATATYPE _tmp60_;
  DATATYPE _tmp62_;
  DATATYPE _tmp63_;
  DATATYPE _tmp67_;
  DATATYPE _tmp6_;
  DATATYPE _tmp70_;
  DATATYPE _tmp7_;
  DATATYPE _tmp8_;
  DATATYPE _tmp9_;

  // Instructions (body)
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    _tmp6_ = L_ROTATE(a__[0][_mask_idx],4,16);
    _tmp8_ = L_ROTATE(a__[7][_mask_idx],4,16);
    _tmp18_ = L_ROTATE(a__[6][_mask_idx],4,16);
    _tmp25_ = L_ROTATE(a__[5][_mask_idx],4,16);
    _tmp35_ = L_ROTATE(a__[4][_mask_idx],4,16);
    _tmp45_ = L_ROTATE(a__[3][_mask_idx],4,16);
    _tmp52_ = L_ROTATE(a__[2][_mask_idx],4,16);
    _tmp59_ = L_ROTATE(a__[1][_mask_idx],4,16);
    _tmp7_ = XOR(a__[0][_mask_idx],_tmp6_);
    _tmp11_ = XOR(a__[7][_mask_idx],_tmp8_);
    _tmp21_ = XOR(a__[6][_mask_idx],_tmp18_);
    _tmp28_ = XOR(a__[5][_mask_idx],_tmp25_);
    _tmp38_ = XOR(a__[4][_mask_idx],_tmp35_);
    _tmp48_ = XOR(a__[3][_mask_idx],_tmp45_);
    _tmp55_ = XOR(a__[2][_mask_idx],_tmp52_);
    _tmp62_ = XOR(a__[1][_mask_idx],_tmp59_);
    _tmp70_ = L_ROTATE(_tmp7_,8,16);
    _tmp9_ = XOR(_tmp7_,_tmp8_);
    _tmp12_ = L_ROTATE(_tmp11_,8,16);
    _tmp17_ = XOR(_tmp11_,_tmp7_);
    _tmp22_ = L_ROTATE(_tmp21_,8,16);
    _tmp29_ = L_ROTATE(_tmp28_,8,16);
    _tmp39_ = L_ROTATE(_tmp38_,8,16);
    _tmp49_ = L_ROTATE(_tmp48_,8,16);
    _tmp56_ = L_ROTATE(_tmp55_,8,16);
    _tmp63_ = L_ROTATE(_tmp62_,8,16);
    _tmp26_ = XOR(_tmp21_,_tmp25_);
    _tmp34_ = XOR(_tmp28_,_tmp7_);
    b__[7][_mask_idx] = XOR(_tmp9_,_tmp12_);
    _tmp19_ = XOR(_tmp17_,_tmp18_);
    _tmp44_ = XOR(_tmp38_,_tmp7_);
    _tmp53_ = XOR(_tmp48_,_tmp52_);
    _tmp60_ = XOR(_tmp55_,_tmp59_);
    _tmp67_ = XOR(_tmp62_,_tmp6_);
    b__[5][_mask_idx] = XOR(_tmp26_,_tmp29_);
    _tmp36_ = XOR(_tmp34_,_tmp35_);
    b__[6][_mask_idx] = XOR(_tmp19_,_tmp22_);
    _tmp46_ = XOR(_tmp44_,_tmp45_);
    b__[2][_mask_idx] = XOR(_tmp53_,_tmp56_);
    b__[1][_mask_idx] = XOR(_tmp60_,_tmp63_);
    b__[0][_mask_idx] = XOR(_tmp67_,_tmp70_);
    b__[4][_mask_idx] = XOR(_tmp36_,_tmp39_);
    b__[3][_mask_idx] = XOR(_tmp46_,_tmp49_);
  }

}

/* main function */
void AES__ (/*inputs*/ DATATYPE plain__[8][MASKING_ORDER],DATATYPE key__[11][8][MASKING_ORDER], /*outputs*/ DATATYPE cipher__[8][MASKING_ORDER]) {

  // Variables declaration
  DATATYPE ShiftRows__V16_1__tmp100_;
  DATATYPE ShiftRows__V16_1__tmp101_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp102_;
  DATATYPE ShiftRows__V16_1__tmp103_;
  DATATYPE ShiftRows__V16_1__tmp104_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp105_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp106_;
  DATATYPE ShiftRows__V16_1__tmp107_;
  DATATYPE ShiftRows__V16_1__tmp108_;
  DATATYPE ShiftRows__V16_1__tmp109_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp110_;
  DATATYPE ShiftRows__V16_1__tmp111_;
  DATATYPE ShiftRows__V16_1__tmp112_;
  DATATYPE ShiftRows__V16_1__tmp113_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp114_;
  DATATYPE ShiftRows__V16_1__tmp115_;
  DATATYPE ShiftRows__V16_1__tmp116_;
  DATATYPE ShiftRows__V16_1__tmp117_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp118_;
  DATATYPE ShiftRows__V16_1__tmp119_;
  DATATYPE ShiftRows__V16_1__tmp120_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp121_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp122_;
  DATATYPE ShiftRows__V16_1__tmp123_;
  DATATYPE ShiftRows__V16_1__tmp124_;
  DATATYPE ShiftRows__V16_1__tmp125_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp126_;
  DATATYPE ShiftRows__V16_1__tmp127_;
  DATATYPE ShiftRows__V16_1__tmp128_;
  DATATYPE ShiftRows__V16_1__tmp129_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp130_;
  DATATYPE ShiftRows__V16_1__tmp131_;
  DATATYPE ShiftRows__V16_1__tmp132_;
  DATATYPE ShiftRows__V16_1__tmp133_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp134_;
  DATATYPE ShiftRows__V16_1__tmp135_;
  DATATYPE ShiftRows__V16_1__tmp5_;
  DATATYPE ShiftRows__V16_1__tmp76_;
  DATATYPE ShiftRows__V16_1__tmp77_;
  DATATYPE ShiftRows__V16_1__tmp78_;
  DATATYPE ShiftRows__V16_1__tmp79_;
  DATATYPE ShiftRows__V16_1__tmp80_;
  DATATYPE ShiftRows__V16_1__tmp81_;
  DATATYPE ShiftRows__V16_1__tmp82_;
  DATATYPE ShiftRows__V16_1__tmp83_;
  DATATYPE ShiftRows__V16_1__tmp84_;
  DATATYPE ShiftRows__V16_1__tmp85_;
  DATATYPE ShiftRows__V16_1__tmp86_;
  DATATYPE ShiftRows__V16_1__tmp87_;
  DATATYPE ShiftRows__V16_1__tmp88_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp89_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp90_;
  DATATYPE ShiftRows__V16_1__tmp91_;
  DATATYPE ShiftRows__V16_1__tmp92_;
  DATATYPE ShiftRows__V16_1__tmp93_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp94_;
  DATATYPE ShiftRows__V16_1__tmp95_;
  DATATYPE ShiftRows__V16_1__tmp96_;
  DATATYPE ShiftRows__V16_1__tmp97_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_1__tmp98_;
  DATATYPE ShiftRows__V16_1__tmp99_;
  DATATYPE ShiftRows__V16_2__tmp100_;
  DATATYPE ShiftRows__V16_2__tmp101_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp102_;
  DATATYPE ShiftRows__V16_2__tmp103_;
  DATATYPE ShiftRows__V16_2__tmp104_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp105_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp106_;
  DATATYPE ShiftRows__V16_2__tmp107_;
  DATATYPE ShiftRows__V16_2__tmp108_;
  DATATYPE ShiftRows__V16_2__tmp109_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp110_;
  DATATYPE ShiftRows__V16_2__tmp111_;
  DATATYPE ShiftRows__V16_2__tmp112_;
  DATATYPE ShiftRows__V16_2__tmp113_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp114_;
  DATATYPE ShiftRows__V16_2__tmp115_;
  DATATYPE ShiftRows__V16_2__tmp116_;
  DATATYPE ShiftRows__V16_2__tmp117_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp118_;
  DATATYPE ShiftRows__V16_2__tmp119_;
  DATATYPE ShiftRows__V16_2__tmp120_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp121_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp122_;
  DATATYPE ShiftRows__V16_2__tmp123_;
  DATATYPE ShiftRows__V16_2__tmp124_;
  DATATYPE ShiftRows__V16_2__tmp125_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp126_;
  DATATYPE ShiftRows__V16_2__tmp127_;
  DATATYPE ShiftRows__V16_2__tmp128_;
  DATATYPE ShiftRows__V16_2__tmp129_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp130_;
  DATATYPE ShiftRows__V16_2__tmp131_;
  DATATYPE ShiftRows__V16_2__tmp132_;
  DATATYPE ShiftRows__V16_2__tmp133_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp134_;
  DATATYPE ShiftRows__V16_2__tmp135_;
  DATATYPE ShiftRows__V16_2__tmp5_;
  DATATYPE ShiftRows__V16_2__tmp76_;
  DATATYPE ShiftRows__V16_2__tmp77_;
  DATATYPE ShiftRows__V16_2__tmp78_;
  DATATYPE ShiftRows__V16_2__tmp79_;
  DATATYPE ShiftRows__V16_2__tmp80_;
  DATATYPE ShiftRows__V16_2__tmp81_;
  DATATYPE ShiftRows__V16_2__tmp82_;
  DATATYPE ShiftRows__V16_2__tmp83_;
  DATATYPE ShiftRows__V16_2__tmp84_;
  DATATYPE ShiftRows__V16_2__tmp85_;
  DATATYPE ShiftRows__V16_2__tmp86_;
  DATATYPE ShiftRows__V16_2__tmp87_;
  DATATYPE ShiftRows__V16_2__tmp88_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp89_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp90_;
  DATATYPE ShiftRows__V16_2__tmp91_;
  DATATYPE ShiftRows__V16_2__tmp92_;
  DATATYPE ShiftRows__V16_2__tmp93_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp94_;
  DATATYPE ShiftRows__V16_2__tmp95_;
  DATATYPE ShiftRows__V16_2__tmp96_;
  DATATYPE ShiftRows__V16_2__tmp97_[MASKING_ORDER];
  DATATYPE ShiftRows__V16_2__tmp98_;
  DATATYPE ShiftRows__V16_2__tmp99_;
  DATATYPE _tmp71_[8][MASKING_ORDER];
  DATATYPE _tmp72_[8][MASKING_ORDER];
  DATATYPE _tmp73_[8][MASKING_ORDER];
  DATATYPE _tmp74_[8][MASKING_ORDER];
  DATATYPE _tmp75_[8][MASKING_ORDER];
  DATATYPE tmp__[8][MASKING_ORDER];

  // Instructions (body)
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    tmp__[0][_mask_idx] = XOR(plain__[0][_mask_idx],key__[0][0][_mask_idx]);
    tmp__[1][_mask_idx] = XOR(plain__[1][_mask_idx],key__[0][1][_mask_idx]);
    tmp__[2][_mask_idx] = XOR(plain__[2][_mask_idx],key__[0][2][_mask_idx]);
    tmp__[3][_mask_idx] = XOR(plain__[3][_mask_idx],key__[0][3][_mask_idx]);
    tmp__[4][_mask_idx] = XOR(plain__[4][_mask_idx],key__[0][4][_mask_idx]);
    tmp__[5][_mask_idx] = XOR(plain__[5][_mask_idx],key__[0][5][_mask_idx]);
    tmp__[6][_mask_idx] = XOR(plain__[6][_mask_idx],key__[0][6][_mask_idx]);
    tmp__[7][_mask_idx] = XOR(plain__[7][_mask_idx],key__[0][7][_mask_idx]);
  }
  for (int i__ = 1; i__ <= 9; i__++) {
    SubBytes__V16(tmp__[0],tmp__[1],tmp__[2],tmp__[3],tmp__[4],tmp__[5],tmp__[6],tmp__[7],_tmp71_[0],_tmp71_[1],_tmp71_[2],_tmp71_[3],_tmp71_[4],_tmp71_[5],_tmp71_[6],_tmp71_[7]);
    for (int i__1 = 0; i__1 <= 7; i__1++) {
      ShiftRows__V16_1__tmp78_ = LIFT_16(32768);
      ShiftRows__V16_1__tmp80_ = LIFT_16(16384);
      ShiftRows__V16_1__tmp83_ = LIFT_16(8192);
      ShiftRows__V16_1__tmp86_ = LIFT_16(4096);
      for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
        ShiftRows__V16_1__tmp89_[_mask_idx] = L_SHIFT(_tmp71_[i__1][_mask_idx],1,16);
        ShiftRows__V16_1__tmp101_[_mask_idx] = R_SHIFT(_tmp71_[i__1][_mask_idx],3,16);
        ShiftRows__V16_1__tmp79_ = AND(_tmp71_[i__1][_mask_idx],ShiftRows__V16_1__tmp78_);
        ShiftRows__V16_1__tmp81_ = AND(_tmp71_[i__1][_mask_idx],ShiftRows__V16_1__tmp80_);
        ShiftRows__V16_1__tmp84_ = AND(_tmp71_[i__1][_mask_idx],ShiftRows__V16_1__tmp83_);
        ShiftRows__V16_1__tmp87_ = AND(_tmp71_[i__1][_mask_idx],ShiftRows__V16_1__tmp86_);
        ShiftRows__V16_1__tmp93_[_mask_idx] = ShiftRows__V16_1__tmp89_[_mask_idx];
        ShiftRows__V16_1__tmp105_[_mask_idx] = L_SHIFT(_tmp71_[i__1][_mask_idx],2,16);
        ShiftRows__V16_1__tmp113_[_mask_idx] = R_SHIFT(_tmp71_[i__1][_mask_idx],2,16);
        ShiftRows__V16_1__tmp82_ = XOR(ShiftRows__V16_1__tmp79_,ShiftRows__V16_1__tmp81_);
        ShiftRows__V16_1__tmp97_[_mask_idx] = ShiftRows__V16_1__tmp93_[_mask_idx];
        ShiftRows__V16_1__tmp109_[_mask_idx] = ShiftRows__V16_1__tmp105_[_mask_idx];
        ShiftRows__V16_1__tmp121_[_mask_idx] = L_SHIFT(_tmp71_[i__1][_mask_idx],3,16);
        ShiftRows__V16_1__tmp117_[_mask_idx] = ShiftRows__V16_1__tmp113_[_mask_idx];
        ShiftRows__V16_1__tmp85_ = XOR(ShiftRows__V16_1__tmp82_,ShiftRows__V16_1__tmp84_);
        ShiftRows__V16_1__tmp125_[_mask_idx] = R_SHIFT(_tmp71_[i__1][_mask_idx],1,16);
        ShiftRows__V16_1__tmp88_[_mask_idx] = XOR(ShiftRows__V16_1__tmp85_,ShiftRows__V16_1__tmp87_);
        ShiftRows__V16_1__tmp129_[_mask_idx] = ShiftRows__V16_1__tmp125_[_mask_idx];
        ShiftRows__V16_1__tmp133_[_mask_idx] = ShiftRows__V16_1__tmp129_[_mask_idx];
      }
      ShiftRows__V16_1__tmp90_ = LIFT_16(2048);
      ShiftRows__V16_1__tmp94_ = LIFT_16(1024);
      ShiftRows__V16_1__tmp98_ = LIFT_16(512);
      ShiftRows__V16_1__tmp102_ = LIFT_16(256);
      for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
        ShiftRows__V16_1__tmp91_ = AND(ShiftRows__V16_1__tmp89_[_mask_idx],ShiftRows__V16_1__tmp90_);
        ShiftRows__V16_1__tmp103_ = AND(ShiftRows__V16_1__tmp101_[_mask_idx],ShiftRows__V16_1__tmp102_);
        ShiftRows__V16_1__tmp95_ = AND(ShiftRows__V16_1__tmp93_[_mask_idx],ShiftRows__V16_1__tmp94_);
        ShiftRows__V16_1__tmp99_ = AND(ShiftRows__V16_1__tmp97_[_mask_idx],ShiftRows__V16_1__tmp98_);
        ShiftRows__V16_1__tmp92_ = XOR(ShiftRows__V16_1__tmp88_[_mask_idx],ShiftRows__V16_1__tmp91_);
        ShiftRows__V16_1__tmp96_ = XOR(ShiftRows__V16_1__tmp92_,ShiftRows__V16_1__tmp95_);
        ShiftRows__V16_1__tmp100_ = XOR(ShiftRows__V16_1__tmp96_,ShiftRows__V16_1__tmp99_);
        ShiftRows__V16_1__tmp104_[_mask_idx] = XOR(ShiftRows__V16_1__tmp100_,ShiftRows__V16_1__tmp103_);
      }
      ShiftRows__V16_1__tmp106_ = LIFT_16(128);
      ShiftRows__V16_1__tmp110_ = LIFT_16(64);
      ShiftRows__V16_1__tmp114_ = LIFT_16(32);
      ShiftRows__V16_1__tmp118_ = LIFT_16(16);
      for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
        ShiftRows__V16_1__tmp107_ = AND(ShiftRows__V16_1__tmp105_[_mask_idx],ShiftRows__V16_1__tmp106_);
        ShiftRows__V16_1__tmp115_ = AND(ShiftRows__V16_1__tmp113_[_mask_idx],ShiftRows__V16_1__tmp114_);
        ShiftRows__V16_1__tmp111_ = AND(ShiftRows__V16_1__tmp109_[_mask_idx],ShiftRows__V16_1__tmp110_);
        ShiftRows__V16_1__tmp119_ = AND(ShiftRows__V16_1__tmp117_[_mask_idx],ShiftRows__V16_1__tmp118_);
        ShiftRows__V16_1__tmp108_ = XOR(ShiftRows__V16_1__tmp104_[_mask_idx],ShiftRows__V16_1__tmp107_);
        ShiftRows__V16_1__tmp112_ = XOR(ShiftRows__V16_1__tmp108_,ShiftRows__V16_1__tmp111_);
        ShiftRows__V16_1__tmp116_ = XOR(ShiftRows__V16_1__tmp112_,ShiftRows__V16_1__tmp115_);
        ShiftRows__V16_1__tmp120_[_mask_idx] = XOR(ShiftRows__V16_1__tmp116_,ShiftRows__V16_1__tmp119_);
      }
      ShiftRows__V16_1__tmp122_ = LIFT_16(8);
      ShiftRows__V16_1__tmp126_ = LIFT_16(4);
      ShiftRows__V16_1__tmp130_ = LIFT_16(2);
      ShiftRows__V16_1__tmp134_ = LIFT_16(1);
      for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
        ShiftRows__V16_1__tmp123_ = AND(ShiftRows__V16_1__tmp121_[_mask_idx],ShiftRows__V16_1__tmp122_);
        ShiftRows__V16_1__tmp127_ = AND(ShiftRows__V16_1__tmp125_[_mask_idx],ShiftRows__V16_1__tmp126_);
        ShiftRows__V16_1__tmp131_ = AND(ShiftRows__V16_1__tmp129_[_mask_idx],ShiftRows__V16_1__tmp130_);
        ShiftRows__V16_1__tmp135_ = AND(ShiftRows__V16_1__tmp133_[_mask_idx],ShiftRows__V16_1__tmp134_);
        ShiftRows__V16_1__tmp124_ = XOR(ShiftRows__V16_1__tmp120_[_mask_idx],ShiftRows__V16_1__tmp123_);
        ShiftRows__V16_1__tmp128_ = XOR(ShiftRows__V16_1__tmp124_,ShiftRows__V16_1__tmp127_);
        ShiftRows__V16_1__tmp132_ = XOR(ShiftRows__V16_1__tmp128_,ShiftRows__V16_1__tmp131_);
        ShiftRows__V16_1__tmp77_ = XOR(ShiftRows__V16_1__tmp132_,ShiftRows__V16_1__tmp135_);
        ShiftRows__V16_1__tmp76_ = ShiftRows__V16_1__tmp77_;
        ShiftRows__V16_1__tmp5_ = ShiftRows__V16_1__tmp76_;
        _tmp72_[i__1][_mask_idx] = ShiftRows__V16_1__tmp5_;
      }
    }
    MixColumn__V16(_tmp72_,_tmp73_);
    for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
      tmp__[0][_mask_idx] = XOR(_tmp73_[0][_mask_idx],key__[i__][0][_mask_idx]);
      tmp__[1][_mask_idx] = XOR(_tmp73_[1][_mask_idx],key__[i__][1][_mask_idx]);
      tmp__[2][_mask_idx] = XOR(_tmp73_[2][_mask_idx],key__[i__][2][_mask_idx]);
      tmp__[3][_mask_idx] = XOR(_tmp73_[3][_mask_idx],key__[i__][3][_mask_idx]);
      tmp__[4][_mask_idx] = XOR(_tmp73_[4][_mask_idx],key__[i__][4][_mask_idx]);
      tmp__[5][_mask_idx] = XOR(_tmp73_[5][_mask_idx],key__[i__][5][_mask_idx]);
      tmp__[6][_mask_idx] = XOR(_tmp73_[6][_mask_idx],key__[i__][6][_mask_idx]);
      tmp__[7][_mask_idx] = XOR(_tmp73_[7][_mask_idx],key__[i__][7][_mask_idx]);
    }
  }
  SubBytes__V16(tmp__[0],tmp__[1],tmp__[2],tmp__[3],tmp__[4],tmp__[5],tmp__[6],tmp__[7],_tmp74_[0],_tmp74_[1],_tmp74_[2],_tmp74_[3],_tmp74_[4],_tmp74_[5],_tmp74_[6],_tmp74_[7]);
  for (int i__2 = 0; i__2 <= 7; i__2++) {
    ShiftRows__V16_2__tmp78_ = LIFT_16(32768);
    ShiftRows__V16_2__tmp80_ = LIFT_16(16384);
    ShiftRows__V16_2__tmp83_ = LIFT_16(8192);
    ShiftRows__V16_2__tmp86_ = LIFT_16(4096);
    for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
      ShiftRows__V16_2__tmp89_[_mask_idx] = L_SHIFT(_tmp74_[i__2][_mask_idx],1,16);
      ShiftRows__V16_2__tmp101_[_mask_idx] = R_SHIFT(_tmp74_[i__2][_mask_idx],3,16);
      ShiftRows__V16_2__tmp79_ = AND(_tmp74_[i__2][_mask_idx],ShiftRows__V16_2__tmp78_);
      ShiftRows__V16_2__tmp81_ = AND(_tmp74_[i__2][_mask_idx],ShiftRows__V16_2__tmp80_);
      ShiftRows__V16_2__tmp84_ = AND(_tmp74_[i__2][_mask_idx],ShiftRows__V16_2__tmp83_);
      ShiftRows__V16_2__tmp87_ = AND(_tmp74_[i__2][_mask_idx],ShiftRows__V16_2__tmp86_);
      ShiftRows__V16_2__tmp93_[_mask_idx] = ShiftRows__V16_2__tmp89_[_mask_idx];
      ShiftRows__V16_2__tmp105_[_mask_idx] = L_SHIFT(_tmp74_[i__2][_mask_idx],2,16);
      ShiftRows__V16_2__tmp113_[_mask_idx] = R_SHIFT(_tmp74_[i__2][_mask_idx],2,16);
      ShiftRows__V16_2__tmp82_ = XOR(ShiftRows__V16_2__tmp79_,ShiftRows__V16_2__tmp81_);
      ShiftRows__V16_2__tmp97_[_mask_idx] = ShiftRows__V16_2__tmp93_[_mask_idx];
      ShiftRows__V16_2__tmp109_[_mask_idx] = ShiftRows__V16_2__tmp105_[_mask_idx];
      ShiftRows__V16_2__tmp121_[_mask_idx] = L_SHIFT(_tmp74_[i__2][_mask_idx],3,16);
      ShiftRows__V16_2__tmp117_[_mask_idx] = ShiftRows__V16_2__tmp113_[_mask_idx];
      ShiftRows__V16_2__tmp85_ = XOR(ShiftRows__V16_2__tmp82_,ShiftRows__V16_2__tmp84_);
      ShiftRows__V16_2__tmp125_[_mask_idx] = R_SHIFT(_tmp74_[i__2][_mask_idx],1,16);
      ShiftRows__V16_2__tmp88_[_mask_idx] = XOR(ShiftRows__V16_2__tmp85_,ShiftRows__V16_2__tmp87_);
      ShiftRows__V16_2__tmp129_[_mask_idx] = ShiftRows__V16_2__tmp125_[_mask_idx];
      ShiftRows__V16_2__tmp133_[_mask_idx] = ShiftRows__V16_2__tmp129_[_mask_idx];
    }
    ShiftRows__V16_2__tmp90_ = LIFT_16(2048);
    ShiftRows__V16_2__tmp94_ = LIFT_16(1024);
    ShiftRows__V16_2__tmp98_ = LIFT_16(512);
    ShiftRows__V16_2__tmp102_ = LIFT_16(256);
    for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
      ShiftRows__V16_2__tmp91_ = AND(ShiftRows__V16_2__tmp89_[_mask_idx],ShiftRows__V16_2__tmp90_);
      ShiftRows__V16_2__tmp103_ = AND(ShiftRows__V16_2__tmp101_[_mask_idx],ShiftRows__V16_2__tmp102_);
      ShiftRows__V16_2__tmp95_ = AND(ShiftRows__V16_2__tmp93_[_mask_idx],ShiftRows__V16_2__tmp94_);
      ShiftRows__V16_2__tmp99_ = AND(ShiftRows__V16_2__tmp97_[_mask_idx],ShiftRows__V16_2__tmp98_);
      ShiftRows__V16_2__tmp92_ = XOR(ShiftRows__V16_2__tmp88_[_mask_idx],ShiftRows__V16_2__tmp91_);
      ShiftRows__V16_2__tmp96_ = XOR(ShiftRows__V16_2__tmp92_,ShiftRows__V16_2__tmp95_);
      ShiftRows__V16_2__tmp100_ = XOR(ShiftRows__V16_2__tmp96_,ShiftRows__V16_2__tmp99_);
      ShiftRows__V16_2__tmp104_[_mask_idx] = XOR(ShiftRows__V16_2__tmp100_,ShiftRows__V16_2__tmp103_);
    }
    ShiftRows__V16_2__tmp106_ = LIFT_16(128);
    ShiftRows__V16_2__tmp110_ = LIFT_16(64);
    ShiftRows__V16_2__tmp114_ = LIFT_16(32);
    ShiftRows__V16_2__tmp118_ = LIFT_16(16);
    for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
      ShiftRows__V16_2__tmp107_ = AND(ShiftRows__V16_2__tmp105_[_mask_idx],ShiftRows__V16_2__tmp106_);
      ShiftRows__V16_2__tmp115_ = AND(ShiftRows__V16_2__tmp113_[_mask_idx],ShiftRows__V16_2__tmp114_);
      ShiftRows__V16_2__tmp111_ = AND(ShiftRows__V16_2__tmp109_[_mask_idx],ShiftRows__V16_2__tmp110_);
      ShiftRows__V16_2__tmp119_ = AND(ShiftRows__V16_2__tmp117_[_mask_idx],ShiftRows__V16_2__tmp118_);
      ShiftRows__V16_2__tmp108_ = XOR(ShiftRows__V16_2__tmp104_[_mask_idx],ShiftRows__V16_2__tmp107_);
      ShiftRows__V16_2__tmp112_ = XOR(ShiftRows__V16_2__tmp108_,ShiftRows__V16_2__tmp111_);
      ShiftRows__V16_2__tmp116_ = XOR(ShiftRows__V16_2__tmp112_,ShiftRows__V16_2__tmp115_);
      ShiftRows__V16_2__tmp120_[_mask_idx] = XOR(ShiftRows__V16_2__tmp116_,ShiftRows__V16_2__tmp119_);
    }
    ShiftRows__V16_2__tmp122_ = LIFT_16(8);
    ShiftRows__V16_2__tmp126_ = LIFT_16(4);
    ShiftRows__V16_2__tmp130_ = LIFT_16(2);
    ShiftRows__V16_2__tmp134_ = LIFT_16(1);
    for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
      ShiftRows__V16_2__tmp123_ = AND(ShiftRows__V16_2__tmp121_[_mask_idx],ShiftRows__V16_2__tmp122_);
      ShiftRows__V16_2__tmp127_ = AND(ShiftRows__V16_2__tmp125_[_mask_idx],ShiftRows__V16_2__tmp126_);
      ShiftRows__V16_2__tmp131_ = AND(ShiftRows__V16_2__tmp129_[_mask_idx],ShiftRows__V16_2__tmp130_);
      ShiftRows__V16_2__tmp135_ = AND(ShiftRows__V16_2__tmp133_[_mask_idx],ShiftRows__V16_2__tmp134_);
      ShiftRows__V16_2__tmp124_ = XOR(ShiftRows__V16_2__tmp120_[_mask_idx],ShiftRows__V16_2__tmp123_);
      ShiftRows__V16_2__tmp128_ = XOR(ShiftRows__V16_2__tmp124_,ShiftRows__V16_2__tmp127_);
      ShiftRows__V16_2__tmp132_ = XOR(ShiftRows__V16_2__tmp128_,ShiftRows__V16_2__tmp131_);
      ShiftRows__V16_2__tmp77_ = XOR(ShiftRows__V16_2__tmp132_,ShiftRows__V16_2__tmp135_);
      ShiftRows__V16_2__tmp76_ = ShiftRows__V16_2__tmp77_;
      ShiftRows__V16_2__tmp5_ = ShiftRows__V16_2__tmp76_;
      _tmp75_[i__2][_mask_idx] = ShiftRows__V16_2__tmp5_;
    }
  }
  for (int _mask_idx = 0; _mask_idx <= (MASKING_ORDER - 1); _mask_idx++) {
    cipher__[0][_mask_idx] = XOR(_tmp75_[0][_mask_idx],key__[10][0][_mask_idx]);
    cipher__[1][_mask_idx] = XOR(_tmp75_[1][_mask_idx],key__[10][1][_mask_idx]);
    cipher__[2][_mask_idx] = XOR(_tmp75_[2][_mask_idx],key__[10][2][_mask_idx]);
    cipher__[3][_mask_idx] = XOR(_tmp75_[3][_mask_idx],key__[10][3][_mask_idx]);
    cipher__[4][_mask_idx] = XOR(_tmp75_[4][_mask_idx],key__[10][4][_mask_idx]);
    cipher__[5][_mask_idx] = XOR(_tmp75_[5][_mask_idx],key__[10][5][_mask_idx]);
    cipher__[6][_mask_idx] = XOR(_tmp75_[6][_mask_idx],key__[10][6][_mask_idx]);
    cipher__[7][_mask_idx] = XOR(_tmp75_[7][_mask_idx],key__[10][7][_mask_idx]);
  }

}

/* Additional functions */
uint32_t bench_speed() {
  /* inputs */
  DATATYPE plain__[8][MASKING_ORDER] = { 0 };
  DATATYPE key__[11][8][MASKING_ORDER] = { 0 };

  /* Preventing inputs from being optimized out */
  asm volatile("" : "+m" (plain__));
  asm volatile("" : "+m" (key__));

  /* outputs */
  DATATYPE cipher__[8][MASKING_ORDER] = { 0 };
  /* Primitive call */
  AES__(plain__, key__,cipher__);

  /* Preventing outputs from being optimized out */
  asm volatile("" : "+m" (cipher__));

  /* Returning the number of encrypted bytes */
  return 16;
}

/* **************************************************************** */
/*                            Usuba source                          */
/*                                                                  */
/*

 table SubBytes(input :  v8)
  returns output :  v8
{
  99, 124, 119, 123, 242, 107, 111, 197, 48, 1, 103, 43, 254, 215, 171, 118, 202, 130, 201, 125, 250, 89, 71, 240, 173, 212, 162, 175, 156, 164, 114, 192, 183, 253, 147, 38, 54, 63, 247, 204, 52, 165, 229, 241, 113, 216, 49, 21, 4, 199, 35, 195, 24, 150, 5, 154, 7, 18, 128, 226, 235, 39, 178, 117, 9, 131, 44, 26, 27, 110, 90, 160, 82, 59, 214, 179, 41, 227, 47, 132, 83, 209, 0, 237, 32, 252, 177, 91, 106, 203, 190, 57, 74, 76, 88, 207, 208, 239, 170, 251, 67, 77, 51, 133, 69, 249, 2, 127, 80, 60, 159, 168, 81, 163, 64, 143, 146, 157, 56, 245, 188, 182, 218, 33, 16, 255, 243, 210, 205, 12, 19, 236, 95, 151, 68, 23, 196, 167, 126, 61, 100, 93, 25, 115, 96, 129, 79, 220, 34, 42, 144, 136, 70, 238, 184, 20, 222, 94, 11, 219, 224, 50, 58, 10, 73, 6, 36, 92, 194, 211, 172, 98, 145, 149, 228, 121, 231, 200, 55, 109, 141, 213, 78, 169, 108, 86, 244, 234, 101, 122, 174, 8, 186, 120, 37, 46, 28, 166, 180, 198, 232, 221, 116, 31, 75, 189, 139, 138, 112, 62, 181, 102, 72, 3, 246, 14, 97, 53, 87, 185, 134, 193, 29, 158, 225, 248, 152, 17, 105, 217, 142, 148, 155, 30, 135, 233, 206, 85, 40, 223, 140, 161, 137, 13, 191, 230, 66, 104, 65, 153, 45, 15, 176, 84, 187, 22
}


 node ShiftRows(inputSR :  u16x8)
  returns out :  u16x8
vars

let
  forall i in [0,7] {
    (out[i]) = Shuffle(inputSR[i],[0,1,2,3,5,6,7,4,10,11,8,9,15,12,13,14])
  }
tel

 node RL32(input :  u16)
  returns out :  u16
vars

let
  (out) = (input <<< 4)
tel

 node RL64(input :  u16)
  returns out :  u16
vars

let
  (out) = (input <<< 8)
tel

 node MixColumn(a :  u16x8)
  returns b :  u16x8
vars

let
  (b[(7 - 0)]) = (((a[(7 - 7)] ^ RL32(a[(7 - 7)])) ^ RL32(a[(7 - 0)])) ^ RL64((a[(7 - 0)] ^ RL32(a[(7 - 0)]))));
  (b[(7 - 1)]) = ((((a[(7 - 0)] ^ RL32(a[(7 - 0)])) ^ (a[(7 - 7)] ^ RL32(a[(7 - 7)]))) ^ RL32(a[(7 - 1)])) ^ RL64((a[(7 - 1)] ^ RL32(a[(7 - 1)]))));
  (b[(7 - 2)]) = (((a[(7 - 1)] ^ RL32(a[(7 - 1)])) ^ RL32(a[(7 - 2)])) ^ RL64((a[(7 - 2)] ^ RL32(a[(7 - 2)]))));
  (b[(7 - 3)]) = ((((a[(7 - 2)] ^ RL32(a[(7 - 2)])) ^ (a[(7 - 7)] ^ RL32(a[(7 - 7)]))) ^ RL32(a[(7 - 3)])) ^ RL64((a[(7 - 3)] ^ RL32(a[(7 - 3)]))));
  (b[(7 - 4)]) = ((((a[(7 - 3)] ^ RL32(a[(7 - 3)])) ^ (a[(7 - 7)] ^ RL32(a[(7 - 7)]))) ^ RL32(a[(7 - 4)])) ^ RL64((a[(7 - 4)] ^ RL32(a[(7 - 4)]))));
  (b[(7 - 5)]) = (((a[(7 - 4)] ^ RL32(a[(7 - 4)])) ^ RL32(a[(7 - 5)])) ^ RL64((a[(7 - 5)] ^ RL32(a[(7 - 5)]))));
  (b[(7 - 6)]) = (((a[(7 - 5)] ^ RL32(a[(7 - 5)])) ^ RL32(a[(7 - 6)])) ^ RL64((a[(7 - 6)] ^ RL32(a[(7 - 6)]))));
  (b[(7 - 7)]) = (((a[(7 - 6)] ^ RL32(a[(7 - 6)])) ^ RL32(a[(7 - 7)])) ^ RL64((a[(7 - 7)] ^ RL32(a[(7 - 7)]))))
tel

 node AES(plain :  u16x8,key :  u16x8[11])
  returns cipher :  u16x8
vars
  tmp :  u16x8[10]
let
  (tmp[0]) = (plain ^ key[0]);
  forall i in [1,9] {
    (tmp[i]) = (MixColumn(ShiftRows(SubBytes(tmp[(i - 1)]))) ^ key[i])
  };
  (cipher) = (ShiftRows(SubBytes(tmp[9])) ^ key[10])
tel

*/
 