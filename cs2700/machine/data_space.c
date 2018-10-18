#include <stdio.h>
#include "envir.h"

void do_data_space (instr)
byte instr;
{
	switch (instr) {
		case GETSW :	/*stack = w_d_addr--w_value*/
			pushw (get_data_word(i2q(popw())));
			break;
		case GETSL :	/*stack = w_d_addr--l_value*/
			pushl (get_data_long(i2q(popw())));
			break;
		case GETSQ :	/*stack = w_d_addr--q_value*/
			pushq (get_data_quad(i2q(popw())));
			break;
		case GETSB :	/*stack = w_d_addr--b_value*/
			pushb (get_data_byte(i2q(popw())));
			break;
		case PUTSW : {	/*stack = w_d_addr\w_value--*/
				word	value = popw();
				put_data_word (i2q(popw()), value);
			}
			break;
		case PUTSL : {	/*stack = w_d_addr\l_value--*/
				lword	value = popl();
				put_data_long (i2q(popw()), value);
			}
			break;
		case PUTSQ : {	/*stack = w_d_addr\q_value--*/
				Quad	value; value = popq(); 
				put_data_quad (i2q(popw()), value);
			}
			break;
		case PUTSB : {	/*stack = w_d_addr\b_value--*/
				byte	value = popb(); 
				put_data_byte (i2q(popw()), value);
			}
			break;
		case GETFW :	/*stack = q_d_addr--w_value*/
			pushw (get_data_word(popq()));
			break;
		case GETFL :	/*stack = q_d_addr--l_value*/
			pushl (get_data_long(popq()));
			break;
		case GETFQ :	/*stack = q_d_addr--q_value*/
			pushq (get_data_quad(popq()));
			break;
		case GETFB :	/*stack = q_d_addr--b_value*/
			pushb (get_data_byte(popq()));
			break;
		case PUTFW : {	/*stack = q_d_addr\w_value--*/
				word	value = popw();
				put_data_word (popq(), value);
			}
			break;
		case PUTFL : {	/*stack = q_d_addr\l_value--*/
				lword	value = popl();
				put_data_long (popq(), value);
			}
			break;
		case PUTFQ : {	/*stack = q_d_addr\q_value--*/
				Quad	value;
				value = popq(); 
				put_data_quad (popq(), value);
			}
			break;
		case PUTFB : {	/*stack = q_d_addr\b_value--*/
				byte	value = popb();
				put_data_byte (popq(), value);
			}
			break;
	}
}
