#include <stdio.h>
#include "envir.h"
union U { float f; int i;};

void do_shift_or_test (instr)
byte instr;
{
	switch (instr) {
		case CSFTW	: {	/*stack = w_value\amt--w_value*/
/*				word amt = popw();
				word value = popw();
				pushw ((word)(sec / top));
*/			}
			break;
		case CSFTL	:		/*stack = l_value\amt--l_value*/
		case CSFTQ	:		/*stack = q_value\amt--q_value*/
			printf ("Instruction %s not implemented\n", instrs[instr].name);
			break;
		case CSFTB	: {	/*stack = b_value\amt--b_value*/
/*				word amt = popw();
				word value = popw();
				pushw ((word)(sec / top));
*/			}
			break;
		case ASFTW	: {	/*stack = w_value\amt--w_value*/
/*				word amt = popw();
				word value = popw();
				pushw ((word)(sec / top));
*/			}
			break;
		case ASFTL	:		/*stack = l_value\amt--l_value*/
			printf ("Instruction %s not implemented\n", instrs[instr].name);
			break;
		case ASFTQ	: {	/*stack = q_value\amt--q_value*/
				word amt = popw();
				Quad value, val; 
				union {unsigned int l; struct {unsigned short t, b;}p;} temp;
				value = popq();
				temp.p.t = (value.top & 0xffff);
				temp.p.b = (value.bot >>  16) &0xffff;
				if (amt > 0) {	/* left shift */
					val.top <<= abs(amt);
					val.bot <<= abs(amt);
					temp.l <<= abs(amt);
				}
				else { /* right shift */
					val.top >>= abs(amt);
					val.bot >>= abs(amt);
					temp.l >>= abs(amt);
				}
				val.top |= ((unsigned int)temp.p.t) & 0xffff;
				val.bot |= (((unsigned int)temp.p.b) & 0xffff) << 16;
				pushq (val);
			}
			break;
		case ASFTB	: {	/*stack = b_value\amt--b_value*/
/*				word amt = popw();
				word value = popw();
				pushw ((word)(sec / top));
*/			}
			break;
		case TSTEQI	:		/*stack = word--w_flag*/
			pushw (((short)popw() == 0) ? -1 : 0);
			break;
		case TSTEQL	: {	/*stack = l_word--w_flag*/
/*			pushw (((int)popl() == 0) ? -1 : 0);
*/			Quad temp; temp = popq();
			pushw (((int)temp.top == 0 && (int)temp.bot == 0) ? -1 : 0);
			}
			break;
		case TSTEQF	: {	/*stack = float--w_flag*/
				union U top;
				top.i = popl ();
				pushw (top.f == 0.0 ? -1 : 0);
			}
			break;
		case TSTEQC	:		/*stack = char--w_flag*/
			pushw (((char)popb() == 0) ? -1 : 0);
			break;
		case TSTLTI	:		/*stack = word--w_flag*/
			pushw (((short)popw() < 0) ? -1 : 0);
			break;
		case TSTLTL	: {	/*stack = l_word--w_flag*/
/*			pushw (((int)popl() < 0) ? -1 : 0);
*/			Quad temp; temp = popq();
			pushw (((int)temp.top < 0 ) ? -1 : 0);
			}
			break;
		case TSTLTF	: { 	/*stack = float--w_flag*/
				union U top;
				top.i = popl ();
				pushw (top.f < 0.0 ? -1 : 0);
			}
			break;
		case TSTLTC	:		/*stack = char--w_flag*/
			pushw (((char)popb() < 0) ? -1 : 0);
			break;
	}
}
