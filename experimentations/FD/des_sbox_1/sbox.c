/* This code was generated by Usuba.
   See https://github.com/DadaIsCrazy/usuba. */


/* Do NOT change the order of those define/include */
#define NO_RUNTIME
#ifndef BITS_PER_REG
#define BITS_PER_REG 64
#endif
/* including the architecture specific .h */
#include "STD.h"

/* auxiliary functions */


/* main function */
void f__ (/*inputs*/ DATATYPE a0__,DATATYPE a1__,DATATYPE a2__,DATATYPE a3__,DATATYPE a4__,DATATYPE a5__, /*outputs*/ DATATYPE* out0__,DATATYPE* out1__,DATATYPE* out2__,DATATYPE* out3__) {
  
  // Variables declaration
  DATATYPE x1;
  DATATYPE x10;
  DATATYPE x11;
  DATATYPE x12;
  DATATYPE x13;
  DATATYPE x14;
  DATATYPE x15;
  DATATYPE x16;
  DATATYPE x17;
  DATATYPE x18;
  DATATYPE x19;
  DATATYPE x2;
  DATATYPE x20;
  DATATYPE x21;
  DATATYPE x22;
  DATATYPE x23;
  DATATYPE x24;
  DATATYPE x25;
  DATATYPE x26;
  DATATYPE x27;
  DATATYPE x28;
  DATATYPE x29;
  DATATYPE x3;
  DATATYPE x30;
  DATATYPE x31;
  DATATYPE x32;
  DATATYPE x33;
  DATATYPE x34;
  DATATYPE x35;
  DATATYPE x36;
  DATATYPE x37;
  DATATYPE x38;
  DATATYPE x39;
  DATATYPE x4;
  DATATYPE x40;
  DATATYPE x41;
  DATATYPE x42;
  DATATYPE x43;
  DATATYPE x44;
  DATATYPE x45;
  DATATYPE x46;
  DATATYPE x47;
  DATATYPE x48;
  DATATYPE x49;
  DATATYPE x5;
  DATATYPE x50;
  DATATYPE x51;
  DATATYPE x52;
  DATATYPE x53;
  DATATYPE x54;
  DATATYPE x55;
  DATATYPE x56;
  DATATYPE x57;
  DATATYPE x58;
  DATATYPE x59;
  DATATYPE x6;
  DATATYPE x60;
  DATATYPE x61;
  DATATYPE x62;
  DATATYPE x63;
  DATATYPE x7;
  DATATYPE x8;
  DATATYPE x9;


  // Instructions (body)
  x1 = NOT(a3__);
  x2 = NOT(a0__);
  x3 = XOR(a3__,a2__);
  x4 = XOR(x3,x2);
  x5 = OR(a2__,x2);
  x6 = AND(x5,x1);
  x7 = OR(a5__,x6);
  x8 = XOR(x4,x7);
  x9 = OR(x1,x2);
  x10 = AND(a5__,x9);
  x11 = XOR(x7,x10);
  x12 = OR(a1__,x11);
  x13 = XOR(x8,x12);
  x14 = XOR(x9,x13);
  x15 = OR(a5__,x14);
  x16 = XOR(x1,x15);
  x17 = NOT(x14);
  x18 = AND(x17,x3);
  x19 = OR(a1__,x18);
  x20 = XOR(x16,x19);
  x21 = OR(a4__,x20);
  x22 = XOR(x13,x21);
  *out3__ = x22;
  x23 = OR(a2__,x4);
  x24 = NOT(x23);
  x25 = OR(a5__,x24);
  x26 = XOR(x6,x25);
  x27 = AND(x1,x8);
  x28 = OR(a1__,x27);
  x29 = XOR(x26,x28);
  x30 = OR(x1,x8);
  x31 = XOR(x30,x6);
  x32 = AND(x5,x14);
  x33 = XOR(x32,x8);
  x34 = AND(a1__,x33);
  x35 = XOR(x31,x34);
  x36 = OR(a4__,x35);
  x37 = XOR(x29,x36);
  *out0__ = x37;
  x38 = AND(a2__,x10);
  x39 = OR(x38,x4);
  x40 = AND(a2__,x33);
  x41 = XOR(x40,x25);
  x42 = OR(a1__,x41);
  x43 = XOR(x39,x42);
  x44 = OR(a2__,x26);
  x45 = XOR(x44,x14);
  x46 = OR(a0__,x8);
  x47 = XOR(x46,x20);
  x48 = OR(a1__,x47);
  x49 = XOR(x45,x48);
  x50 = AND(a4__,x49);
  x51 = XOR(x43,x50);
  *out1__ = x51;
  x52 = XOR(x8,x40);
  x53 = XOR(a2__,x11);
  x54 = AND(x53,x5);
  x55 = OR(a1__,x54);
  x56 = XOR(x52,x55);
  x57 = OR(a5__,x4);
  x58 = XOR(x57,x38);
  x59 = AND(x13,x56);
  x60 = AND(a1__,x59);
  x61 = XOR(x58,x60);
  x62 = AND(a4__,x61);
  x63 = XOR(x56,x62);
  *out2__ = x63;

}
 