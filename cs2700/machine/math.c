#include "envir.h"
union U { float f; int i;};

void do_math_instr (instr)
byte instr;
{
	switch (instr) {
/* arithmetic and logical instructions */
		case ADDI : {	/*stack = int1\int2--int1+int2*/
				short top = (short)popw();
				short sec = (short)popw();
				pushw ((word)(sec + top));
			}
			break;
		case ADDL : {	/*stack = l_int1\l_int2--l_int1+l_int2*/
  				Quad top, sec;
				top = (Quad)popq();
				sec = (Quad)popq();
				pushq (qadd (sec, top));
			}
			break;
		case ADDF : {	/*stack = float1\float2--float1+float2*/
				union U top, sec, ans;
				top.i = popl(); sec.i = popl();
				ans.f = sec.f + top.f;
				pushl (ans.i);
			}
			break;
		case ADDC : {	/*stack = char1\char2--char1+char2*/
				char top = (char)popb();
				char sec = (char)popb();
				pushb ((byte)(sec + top));
			}
			break;
		case SUBI : {	/*stack = int1\int2--int1-int2*/
				short top = (short)popw();
				short sec = (short)popw();
				pushw ((word)(sec - top));
			}
			break;
		case SUBL : {	/*stack = l_int1\l_int2--l_int1-l_int2*/
            Quad top, sec;
            top = (Quad)popq();
            sec = (Quad)popq();
				pushq (qsub (sec, top));
			}
			break;
		case SUBF : {	/*stack = float1\float2--float1-float2*/
				union U top, sec, ans;
				top.i = popl(); sec.i = popl();
				ans.f = sec.f - top.f;
				pushl (ans.i);
			}
			break;
		case SUBC : {	/*stack = char1\char2--char1-char2*/
				char top = (char)popb();
				char sec = (char)popb();
				pushb ((byte)(sec - top));
			}
			break;
		case MULI : {	/*stack = int1\int2--int1*int2*/
				short top = (short)popw();
				short sec = (short)popw();
				pushw ((word)(sec * top));
			}
			break;
		case MULL : {	/*stack = l_int1\l_int2--l_int1*l_int2*/
            Quad top, sec;
            top = (Quad)popq();
            sec = (Quad)popq();
				pushq (qmult (sec, top));
			}
			break;
		case MULF : {	/*stack = float1\float2--float1*float2*/
				union U top, sec, ans;
				top.i = popl(); sec.i = popl();
				ans.f = sec.f * top.f;
				pushl (ans.i);
			}
			break;
		case MULC : {	/*stack = char1\char2--char1*char2*/
				char top = (char)popb();
				char sec = (char)popb();
				pushb ((byte)(sec * top));
			}
			break;
		case DIVI : {	/*stack = int1\int2--int1/int2*/
				short top = (short)popw();
				short sec = (short)popw();
				if (top == 0) rais (DIV_EX);
				pushw ((word)(sec / top));
			}
			break;
		case DIVL : {	/*stack = l_int1\l_int2--l_int1/l_int2*/
            Quad top, sec;
            top = (Quad)popq();
            sec = (Quad)popq();
				if (top.top == 0 && top.bot == 0) rais (DIV_EX);
				pushq (qdiv (sec, top));
			}
			break;
		case DIVF : {	/*stack = float1\float2--float1/float2*/
				union U top, sec, ans;
				top.i = popl(); sec.i = popl();
				if (top.f == 0.0) rais (DIV_EX);
				ans.f = sec.f / top.f;
				pushl (ans.i);
			}
			break;
		case DIVC : {	/*stack = char1\char2--char1/char2*/
				char top = (char)popb();
				char sec = (char)popb();
				if (top == 0) rais (DIV_EX);
				pushb ((byte)(sec / top));
			}
			break;
	}
}
