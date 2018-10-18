#include "envir.h"
#include <stdio.h>
static void syscall ();

void do_super (instr)
byte instr;
{	/* supervisor instructions */
	switch (instr) {
		case HALT: /* never encountered */
		case SYSCALL: syscall(popw()); break;
		case SYSRET: /*never encountered; requires system process */
		case TRACE : rais (TRA_EX);
		default:
				fprintf (stderr, "Illegal Instruction %d\n", instr); break;
	}
}

static void syscall (class)
word	class;
{
	switch (class) {
		case READ_INT : { 
				int	val; printf ("Val=> "); 
				scanf ("%d", &val); pushw ((word)val); 
			}
			break;
		case PRINT_INT :  printf ("%d\n", popw()); break;
		case READ_CHAR : { 
				byte	val; 
				rewind  (stdin); printf ("Val=> "); 
				scanf ("%c", &val); pushb ((byte)val); 
			}
			break;
		case PRINT_CHAR : printf ("%c\n", popb()); break;
/*		case READ_LONG : { 
				long	val; printf ("Val=> "); 
				scanf ("%ld", &val); pushl ((lword)val); 
			}
			break;
		case PRINT_LONG : printf ("%ld\n", popl()); break;
*/		case READ_FLOAT : { float fn;
				union {float f; int i;} u; printf ("Val=> "); 
				scanf ("%f", &fn);
				u.f = fn; pushl (u.i);
			}
			break;
		case PRINT_FLOAT : {
				union {float f; int i;} u; u.i = popl();
				printf ("%f\n", u.f); 
			}
			break;
	}
}
