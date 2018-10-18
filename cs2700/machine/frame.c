#include "envir.h"

void do_frame_instr (instr)
byte instr;
{
	switch (instr) {
		case LGETSW : {	/*stack = w_frame\w_offset--w_value*/
				word offset = popw();
				word frame = popw();
				pushw (get_frame_word (frame, i2q(offset)));
			}
			break;
		case LGETSL : {	/*stack = w_frame\w_offset--l_value*/
				word offset = popw();
				word frame = popw();
				pushl (get_frame_long (frame, i2q(offset)));
			}
			break;
		case LGETSQ : {	/*stack = w_frame\w_offset--q_value*/
				word offset = popw();
				word frame = popw();
				pushq (get_frame_quad (frame, i2q(offset)));
			}
			break;
		case LGETSB : {	/*stack = w_frame\w_offset--b_value*/
				word offset = popw();
				word frame = popw();
				pushb (get_frame_byte (frame, i2q(offset)));
			}
			break;
		case LPUTSW : {	/*stack = w_frame\w_offset\w_value--*/
				word value = popw();
				word offset = popw();
				word frame = popw();
				put_frame_word (frame, i2q(offset), value);
			}
			break;
		case LPUTSL : {	/*stack = w_frame\w_offset\l_value--*/
				lword value = popl();
				word offset = popw();
				word frame = popw();
				put_frame_long (frame, i2q(offset), value);
			}
			break;
		case LPUTSQ : {	/*stack = w_frame\w_offset\q_value--*/
				Quad value;
				word offset;
				word frame; 
				value = popq(); offset = popw(); frame = popw();
				put_frame_quad (frame, i2q(offset), value);
			}
			break;
		case LPUTSB : {	/*stack = w_frame\w_offset\b_value--*/
				byte value = popb();
				word offset = popw();
				word frame = popw();
				put_frame_byte (frame, i2q(offset), value);
			}
			break;
		case LGETFW : {	/*stack = w_frame\q_offset--w_value*/
				Quad offset;
				word frame; 
				offset = popq(); frame = popw();
				pushw (get_frame_word (frame, offset));
			}
			break;
		case LGETFL : {	/*stack = w_frame\q_offset--l_value*/
				Quad offset;
				word frame; 
				offset = popq(); frame = popw();
				pushl (get_frame_long (frame, offset));
			}
			break;
		case LGETFQ : {	/*stack = w_frame\q_offset--q_value*/
				Quad offset;
				word frame; 
				offset = popq(); frame = popw();
				pushq (get_frame_quad (frame, offset));
			}
			break;
		case LGETFB : {	/*stack = w_frame\q_offset--b_value*/
				Quad offset;
				word frame; 
				offset = popq(); frame = popw();
				pushb (get_frame_byte (frame, offset));
			}
			break;
		case LPUTFW : {	/*stack = w_frame\q_offset\w_value--*/
				word value;
				Quad offset;
				word frame; 
				value = popw(); offset = popq(); frame = popw();
				put_frame_word (frame, offset, value);
			}
			break;
		case LPUTFL : {	/*stack = w_frame\q_offset\l_value--*/
				lword value;
				Quad offset;
				word frame; 
				value = popl(); offset = popq(); frame = popw();
				put_frame_long (frame, offset, value);
			}
			break;
		case LPUTFQ : {	/*stack = w_frame\q_offset\q_value--*/
				Quad value;
				Quad offset;
				word frame; 
				value = popq(); offset = popq(); frame = popw();
				put_frame_quad (frame, offset, value);
			}
			break;
		case LPUTFB : {	/*stack = w_frame\q_offset\b_value--*/
				byte value;
				Quad offset;
				word frame; 
				value = popb(); offset = popq(); frame = popw();
				put_frame_byte (frame, offset, value);
			}
			break;
	}
}
