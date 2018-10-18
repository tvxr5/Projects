#include <stdio.h>
#include "envir.h"

void do_stack_manip (instr)
byte instr;
{
	switch (instr) {
		case DUPW : {	/*stack = w_value--w_value\w_value*/
				word top = popw();
				pushw (top); pushw (top);
			}
			break;
		case DUPL : {	/*stack = l_value--l_value\l_value*/
				lword top = popl();
				pushl (top); pushl (top);
			}
			break;
		case DUPQ :	{	/*stack = q_value--q_value\q_value*/
				Quad top; top = popq();
				pushq (top); pushq (top);
			}
			break;
		case DUPO :	{	/*stack = o_value--o_value\o_value*/
				Quad top, sec; 
				top = popq(); sec = popq();
				pushq (sec); pushq (top);
				pushq (sec); pushq (top);
			}
			break;
		case SWAPW : {	/*stack = word1\word2--word2\word1*/
				word top = popw(); word sec = popw();
				pushw (top); pushw (sec);
			}
			break;
		case SWAPL : {	/*stack = long1\long2--long2\long1*/
				lword top = popl(); lword sec = popl();
				pushl (top); pushl (sec);
			}
			break;
		case SWAPQ : {	/*stack = quad1\quad2--quad2\quad1*/
				Quad top, sec; 
				top = popq(); sec = popq();
				pushq (top); pushq (sec);
			}
			break;
		case SWAPO : {	/*stack = octa1\octa2--octa2\octa1*/
				Quad top1, top2, sec1, sec2; 
				top1 = popq(); top2 = popq(); 
				sec1 = popq(); sec2 = popq();
				pushq (top2); pushq (top1);
				pushq (sec2); pushq (sec1);
			}
			break;
		case CHSPS : {	/*stack = w_value*/
				Quad amt;
				amt = i2q (popw());
				SP = qadd (SP, amt);
			}
			break;
		case CHSPF :	/*stack = q_value*/
			SP = qadd (SP, popq());
			break;
		case NEWFR : {	/*arg = w_frame; stack = --q_ofp <set fp>*/
				word arg = get_code_word (PC); PC = qadd (PC, q2);
				pushq (FP[arg]);
				FP[arg] = SP;
			}
			break;
		case RESFR : {	/*arg = w_frame; stack = stuff\q_ofp\local--stuff*/
				word arg = get_code_word (PC); PC = qadd (PC, q2);
				SP = FP[arg];
				FP[arg] = popq();
			}
			break;
		default:
				fprintf (stderr, "Illegal Instruction %d\n", instr); break;
		break;
	}
}
