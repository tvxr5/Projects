#include "envir.h"

void do_code_space (instr)
byte instr;
{
	switch (instr) {
		case CGETW:	 /*stack = q_c_addr--w_value*/
				pushw (get_code_word (popq())); break;
		case CGETL:  /*stack = q_c_addr--l_value*/
				pushl (get_code_long (popq())); break;
		case CGETQ:  /*stack = q_c_addr--q_value*/
				pushq (get_code_quad (popq())); break;
		case CGETB:  /*stack = q_c_addr--b_value*/
				pushb (get_code_byte (popq())); break;
		case CPUTW: { /*stack = q_c_addr\w_value--*/
				word value = popw();
				Quad adr; adr  = popq();
				put_code_word (adr, value);
			}
			break;
		case CPUTL: { /*stack = q_c_addr\l_value--*/
				lword value = popl();
				Quad adr; adr  = popq();
				put_code_long (adr, value);
			}
			break;
		case CPUTQ: { /*stack = q_c_addr\q_value--*/
				Quad value;
				Quad adr; 
				value = popq(); adr  = popq(); 
				put_code_quad (adr, value);
			}
			break;
		case CPUTB: { /*stack = q_c_addr\b_value--*/
				byte value = popb();
				Quad adr; adr  = popq();
				put_code_byte (adr, value);
			}
			break;
		case GOTO: 	/*stack = q_c_addr--*/ /* also RET instr*/ 
			PC = popq(); 
			break;
		case GOSUB: { /*stack = q_c_addr--q_ret_addr*/
				Quad adr; adr = popq();
				pushq (PC);
				PC = adr;
			}
			break;
		case GOZ: 	{ /*stack = q_c_addr\w_flag--*/
				word flag = popw(); 
				Quad adr; adr = popq();
				if (flag == 0) PC = adr;
			}
			break;
	}
}
