#include "envir.h"

void do_pc_relative (instr)
byte instr;
{
	switch (instr) {
		case RGETW:	{ /*arg = w_PC_offset; stack = --w_value*/
				short	offset = get_code_word(PC); PC = qadd (PC, q2);
				pushw (get_code_word(qadd (PC, i2q(offset))));
			}
			break;
		case RGETL:	{ /*arg = w_PC_offset; stack = --l_value*/
				word	offset = get_code_word(PC); PC = qadd (PC, q2);
				pushl (get_code_long(qadd (PC, i2q(offset))));
			}
			break;
		case RGETQ:	{ /*arg = w_PC_offset; stack = --q_value*/
				word	offset = get_code_word(PC); PC = qadd (PC, q2);
				pushq (get_code_quad (qadd (PC, i2q(offset))));
			}
			break;
		case RGETB:	{ /*arg = w_PC_offset; stack = --b_value*/
				word	offset = get_code_word(PC); PC = qadd (PC, q2);
				pushb (get_code_byte(qadd (PC, i2q(offset))));
			}
			break;
		case RPUTW:	{ /*arg = w_PC_offset; stack = w_value--*/
				word	offset = get_code_word(PC); PC = qadd (PC, q2);
				put_code_word (qadd (PC, i2q(offset)), popw());
			}
			break;
		case RPUTL:	{ /*arg = w_PC_offset; stack = l_value--*/
				word	offset = get_code_word(PC); PC = qadd (PC, q2);
				put_code_long (qadd (PC, i2q(offset)), popl());
			}
			break;
		case RPUTQ:	{ /*arg = w_PC_offset; stack = q_value--*/
				word	offset = get_code_word(PC); PC = qadd (PC, q2);
				put_code_quad (qadd (PC, i2q(offset)), popq());
			}
			break;
		case RPUTB:	{ /*arg = w_PC_offset; stack = b_value--*/
				word	offset = get_code_word(PC); PC = qadd (PC, q2);
				put_code_byte (qadd (PC, i2q(offset)), popb());
			}
			break;
		case RGOTO:	{ /*arg = w_PC_offset*/
				word	offset = get_code_word(PC); PC = qadd (PC, q2);
				PC = qadd (PC, i2q(offset));
			}
			break;
		case RGOSUB: {	/*arg = w_PC_offset; stack = --q_ret_addr*/
				word	offset = get_code_word(PC); PC = qadd (PC, q2);
				pushq (PC); PC = qadd (PC, i2q(offset));
			}
			break;
		case RGOZ:	{ /*arg = w_PC_offset; stack = w_flag--*/
				word	offset = get_code_word(PC); PC = qadd (PC, q2);
				if (popw() == 0) PC = qadd (PC, i2q(offset));
			}
			break;
		case RPUSHA: {	/*arg = w_PC_offset; stack = --q_c_addr*/
				word	offset = get_code_word(PC); PC = qadd (PC, q2);
				pushq (qadd (PC, i2q(offset)));
			}
			break;
		case PUSHW:	{	/*arg = w_value; stack = --w_value*/
				word	value = get_code_word(PC); PC = qadd (PC, q2);
				pushw (value);
			}
			break;
		case PUSHL:	{ /*arg = l_value; stack = --l_value*/
				lword	value = get_code_long(PC); PC = qadd (PC, q4);
				pushl (value);
			}
			break;
		case PUSHQ:	{ /*arg = q_value; stack = --q-value*/
				Quad	value; value = get_code_quad (PC); PC = qadd (PC, q8);
				pushq (value);
			}
			break;
		case PUSHB:	{/*arg = b_value; stack = --b_value*/
				byte	value = get_code_byte(PC); PC = qadd (PC, q1);
				pushb (value);
			}
			break;
	}
}
