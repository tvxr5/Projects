#include "envir.h"

void do_logical_instr (instr)
byte instr;
{
	switch (instr) {
		case ANDW : {	/*stack = word1\word2--word1_bit_and_word2*/
				word top = popw();
				word sec = popw();
				pushw (sec & top);
			}
			break;
		case ANDL : {	/*stack = long1\long2--long1_bit_and_long2*/
				lword top = popl();
				lword sec = popl();
				pushl (sec & top);
			}
			break;
		case ANDQ : {	/*stack = quad1\quad2--quad1_bit_and_quad2*/
				Quad top, sec, val; 
				top = popq(); sec = popq();
				val.bot = top.bot & sec.bot; val.top = top.top & sec.top;
				pushq (val);
			}
			break;
		case ANDB : {	/*stack = byte1\byte2--byte1_bit_and_byte2*/
				byte top = popb();
				byte sec = popb();
				pushb (sec & top);
			}
			break;
		case ORW  : {	/*stack = word1\word2--word1_bit_or_word2*/
				word top = popw();
				word sec = popw();
				pushw (sec | top);
			}
			break;
		case ORL	 : {	/*stack = long1\long2--long1_bit_or_long2*/
				lword top = popl();
				lword sec = popl();
				pushl (sec | top);
			}
			break;
		case ORQ	 : {	/*stack = quad1\quad2--quad1_bit_or_quad2*/
				Quad top, sec, val; 
				top = popq(); sec = popq();
				val.bot = top.bot | sec.bot; val.top = top.top | sec.top;
				pushq (val);
			}
			break;
		case ORB	 : {	/*stack = byte1\byte2--byte1_bit_or_byte2*/
				byte top = popb();
				byte sec = popb();
				pushb (sec | top);
			}
			break;
		case XORW : {	/*stack = word1\word2--word1_bit_xor_word2*/
				word top = popw();
				word sec = popw();
				pushw (sec ^ top);
			}
			break;
		case XORL : {	/*stack = long1\long2--long1_bit_xor_long2*/
				lword top = popl();
				lword sec = popl();
				pushl (sec ^ top);
			}
			break;
		case XORQ : {	/*stack = quad1\quad2--quad1_bit_xor_quad2*/
				Quad top, sec, val; 
				top = popq(); sec = popq();
				val.bot = top.bot ^ sec.bot; val.top = top.top ^ sec.top;
				pushq (val);
			}
			break;
		case XORB : {	/*stack = byte1\byte2--byte1_bit_xor_byte2*/
				byte top = popb();
				byte sec = popb();
				pushb (sec ^ top);
			}
			break;
		case NOTW : {	/*stack = word--bit_not_of_word*/
				word top = popw();
				pushw (~ top);
			}
			break;
		case NOTL : {	/*stack = long--bit_not_of_long*/
				lword top = popl();
				pushl (~ top);
			}
			break;
		case NOTQ : {	/*stack = quad--bit_not_of_quad*/
				Quad top, val;
				top = popq();
				val.top = ~top.top; val.bot = ~top.bot;
				pushq (val);
			}
			break;
		case NOTB : {	/*stack = byte--bit_not_of_byte*/
				byte top = popb();
				pushb (~ top);
			}
			break;
	}
}
