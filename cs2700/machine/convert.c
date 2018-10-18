#include "envir.h"
union U { float f; int i; };

void do_convert (byte instr)
{
	switch (instr) {
		case ADRD:			/*stack = q_d_addr--q_universal_addr*/
					/* no op */
				break;
		case CVTIL:	{		/*stack = int--long*/
					short top = (short)popw();
					pushw ((word)top);
					if (top < 0) {
						pushw (0xffff); pushw (0xffff); pushw (0xffff);
						}
					else {
						pushw (0); pushw (0); pushw (0);
					}
				}
				break;
		case CVTIF:	{		/*stack = int--float*/
					union U top;
					top.f = (short)popw();
					pushl (top.i);
				}
				break;
		case CVTIC:			/*stack = int--char*/
				pushb((byte)(popw() & 0xff));
				break;
		case CVTLI:			/*stack = long--int*/
				popl(); popw(); /* leave bottom word */
				break;
		case ZEXWQ:			/*stack = w_value--q_value*/
				pushw (0); pushl (0);
				break;
		case CVTLF:	{		/*stack = long--float*/

				}
				break;
		case CVTLC:			/*stack = long--char*/
				popl(); popw();
				pushb ((byte)(popw() & 0xff));
				break;
		case CVTFI:	{		/*stack = float--int*/
					union U top;
					top.i = popl();
					pushw ((short)top.f);
				}
				break;
		case CVTFL:	{		/*stack = float--long*/

				}
				break;
		case ADRC:	{		/*stack = q_c_addr--q_universal_addr*/

				}
				break;
		case CVTFC:	{		/*stack = float--char*/
					union U top;
					top.i = popl();
					pushb ((char)top.f);
				}
				break;
		case CVTCI:	{		/*stack = char--int*/
					signed char top = (signed char)popb();
					pushw ((signed short int)top);
				}
				break;
		case CVTCL:	{		/*stack = char--long*/
					signed char top = (signed char)popb();
					pushw ((signed short int)top);
					if (top < 0) {
						pushw (-1); pushl (-1);
					}
					else {
						pushw (0); pushl (0);
					}
				}
				break;
		case CVTCF:	{		/*stack = char--float*/
					union U top;
					top.f = (signed char)popb();
					pushl (top.i);
				}
				break;
		case ADRF:	{		/*stack = w_frame\q_offset--q_universal_addr*/

				}
				break;
	}
}
