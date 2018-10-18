#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include "envir.h"

jmp_buf	here;
void run_away();
extern byte verbose;

main (argc, argv)
int	argc;
char	*argv[];
{	byte instr;
	unsigned int count;
	byte done = FALSE;

	if (argc == 1) {
		fprintf (stderr, "missing code file arguement for %s\n", argv[0]);
		exit (1);
		}
	load_command_files (argc, argv);
	while ((instr = get_code_byte(PC))!=HALT) {
		PC = qadd (PC, q1);
		switch (instr & 0xf0) {
			case SUPERVISOR:	do_super (instr); break;
			case PC_RELATIVE:	do_pc_relative (instr); break;
			case CODE_STACK:	do_code_space (instr); break;
			case DATA_INSTR:	do_data_space (instr); break;
			case FRAME_INSTR:	do_frame_instr (instr); break;
			case MATH_INSTR:	do_math_instr (instr); break;
			case LOGICAL_INSTR: do_logical_instr (instr); break;
			case SHIFT_TEST:	do_shift_or_test (instr); break;
			case STACK_MANIP: do_stack_manip (instr); break;
			case CONVERT:		do_convert(instr); break;
			default:
					fprintf (stderr, "Illegal Instruction %d\n", instr); break;
			} /* switch */
		} /* while not HALT */
} /* funct main */

void rais (except)
int	except;
{
	Quad loc;
	loc = qsub (PC, q1);
	switch (except) {
		case TRA_EX :
			break;
		case DIV_EX : 
			fprintf (stderr, "Division by zero at %d\n", loc.bot); 
			break;
		case MT_STACK : 
			fprintf (stderr, "Pop attempted on empty stack at %d\n", loc.bot); 
			break;
		default: 
			fprintf (stderr, "Unknown exception--Internal error\n");
	}
	longjmp (here, 1);
}

void run_away (sig)
int	sig;
{
	printf ("\n");
	signal (SIGINT, run_away);
	longjmp (here, 2);
}

// extern struct brkpt *first_brk;
// 
// int no_break (loc)
// Quad loc;
// {
//	struct brkpt *p = first_brk;
//	for ( ; p != 0L; p = p->next)
//		if (p->point.bot == loc.bot) { 
//			printf ("Break at PC = %d\n", loc.bot);
//			return FALSE;
//		}
//	return TRUE;
// }
