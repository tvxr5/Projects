#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "envir.h"

#define QUIT	0
#define LOAD	1
#define RUN		2
#define STEP	3
#define SHOW_STATE	4
#define CHG_STATE		5
#define SHOW_CODE		6
#define CHG_CODE		7
#define SHOW_DATA		8
#define CHG_DATA		9
#define SHOW_FRAME	10
#define CHG_FRAME		11
#define SHOW_STACK	12
#define CHG_STACK		13
#define SHOW_SYMBS	14
#define SET_BREAK		15
#define SHOW_BREAK	16
#define CLR_BREAK		17
#define ZERO_BREAK	18
#define SILENT			20
#define VERBOSE		21
#define CLR_PROG		22

Quad	entry;
byte	verbose = TRUE;
static byte loaded = FALSE, run_it = FALSE;

static void set_break(), show_break(), clear_break(), zero_break();
static void show_code(), change_code(), show_data(), change_data();
static void show_frame(), change_frame(), show_stack(), change_stack();

void show_menu()
{
	printf ("Your choices are [type the indicated letter or letters]:\n");
	printf ("\tQ  : quit               L  : load a program\n");
	printf ("\tST : step               R  : run until the end\n");
	printf ("\tZP : clear the program  \n");
/*	printf ("\tSL : silent mode        V  : verbose mode\n");
	printf ("\t__ :                    __ : \n");
*/ printf ("\tSH : show menu          CH : change menu\n");	
	printf ("\tBK : breakpoint menu    \n");
}
void show_show_menu()
{
	printf ("\tSI : show instruction   SC : show code space\n");
	printf ("\tSD : show data space    SF : show frame\n");
	printf ("\tSS : show stack         SY : show symbol table\n");
}
void show_change_menu ()
{
	printf ("\tCI : change instruction  CC : change code space\n");
	printf ("\tCD : change data space   CF : change a frame\n");
   printf ("\tCS : change stack\n");
}
void show_breakpoint_menu()
{
	printf ("\tBT : set a breakpoint    BC : change a breakpoint\n");
	printf ("\tBS : show breakpoints    BZ : remove all breakpoints\n");
}

int get_choice ()
{
	char	choice[80];
top:
	scanf ("%s", choice);
	if (feof(stdin) ||
		 strcmp (choice, "Q" ) == 0 ||
		 strcmp (choice, "q" ) == 0 ) return QUIT;
	if (strcmp (choice, "M" ) == 0 ||
		 strcmp (choice, "m" ) == 0 ) { show_menu(); goto top; }
	if (strcmp (choice, "SL") == 0 ||
		 strcmp (choice, "sl") == 0 ) return SILENT;
	if (strcmp (choice, "V") == 0 ||
		 strcmp (choice, "v") == 0 )  return VERBOSE;
	if (strcmp (choice, "ZP") == 0 ||
		 strcmp (choice, "zp") == 0 ) return CLR_PROG;
	if (strcmp (choice, "L" ) == 0 ||
		 strcmp (choice, "l" ) == 0 ) return LOAD;
	if (strcmp (choice, "ST") == 0 ||
		 strcmp (choice, "st") == 0 ) return STEP;
	if (strcmp (choice, "R" ) == 0 ||
		 strcmp (choice, "r" ) == 0 ) return RUN;
	if (strcmp (choice, "SH") == 0 ||
		 strcmp (choice, "sh") == 0 ) { show_show_menu(); goto top; }
	if (strcmp (choice, "SI") == 0 ||
		 strcmp (choice, "si") == 0 ) return SHOW_STATE;
	if (strcmp (choice, "SC") == 0 ||
		 strcmp (choice, "sc") == 0 ) return SHOW_CODE;
	if (strcmp (choice, "SD") == 0 ||
		 strcmp (choice, "sd") == 0 ) return SHOW_DATA;
	if (strcmp (choice, "SF") == 0 ||
		 strcmp (choice, "sf") == 0 ) return SHOW_FRAME;
	if (strcmp (choice, "SS") == 0 ||
		 strcmp (choice, "ss") == 0 ) return SHOW_STACK;
	if (strcmp (choice, "SY") == 0 ||
		 strcmp (choice, "sy") == 0 ) return SHOW_SYMBS;
	if (strcmp (choice, "CH") == 0 ||
		 strcmp (choice, "ch") == 0 ) { show_change_menu(); goto top; }
	if (strcmp (choice, "CI") == 0 ||
		 strcmp (choice, "ci") == 0 ) return CHG_STATE;
	if (strcmp (choice, "CC") == 0 ||
		 strcmp (choice, "cc") == 0 ) return CHG_CODE;
	if (strcmp (choice, "CD") == 0 ||
		 strcmp (choice, "cd") == 0 ) return CHG_DATA;
	if (strcmp (choice, "CF") == 0 ||
		 strcmp (choice, "cf") == 0 ) return CHG_FRAME;
	if (strcmp (choice, "CS") == 0 ||
		 strcmp (choice, "cs") == 0 ) return CHG_STACK;
	if (strcmp (choice, "BK") == 0 ||
		 strcmp (choice, "bk") == 0 ) { show_breakpoint_menu(); goto top; }
	if (strcmp (choice, "BT") == 0 ||
		 strcmp (choice, "bt") == 0 ) return SET_BREAK;
	if (strcmp (choice, "BS") == 0 ||
		 strcmp (choice, "bs") == 0 ) return SHOW_BREAK;
	if (strcmp (choice, "BC") == 0 ||
		 strcmp (choice, "bc") == 0 ) return CLR_BREAK;
	if (strcmp (choice, "BZ") == 0 ||
		 strcmp (choice, "bz") == 0 ) return ZERO_BREAK;
	printf ("Bad Choice: %s\n", choice);
	if (verbose) show_menu();
	goto top;
}

void do_menu (done, count)
byte	*done;
unsigned int	*count;
{
	char junk;

	*done = FALSE;
	*count = 0;
	do {
		if (verbose) show_menu();
		switch (get_choice()){
			case QUIT: *done = TRUE; break;
			case SILENT: verbose = FALSE; break;
			case VERBOSE: verbose = TRUE; break;
			case CLR_PROG: 
				SP = q0; init_load(); 
				loaded = FALSE; run_it = FALSE; break;
			case LOAD:
				get_load_files(); yylex(); 
				loaded = TRUE; run_it = FALSE; PC = entry; break;
			case STEP:
				if (loaded ==FALSE) 
					fprintf (stderr, "No program loaded\n");
				else {
					scanf ("%d", count);
					*count = (*count <=0 ? 1 : *count);
					run_it = TRUE; 
				}
				break;
			case RUN: 
				if (loaded == FALSE) fprintf (stderr, "No program loaded\n");
				else 						{ *count = 32000; run_it = TRUE; }
				break;

/* show and change choices */
			case SHOW_STATE:	show_state(); break;
			case CHG_STATE:	break;
			case SHOW_CODE:	show_code(); break;
			case CHG_CODE:		change_code(); break;
			case SHOW_DATA:	show_data(); break;
			case CHG_DATA:		change_data(); break;
			case SHOW_FRAME:	show_frame(); break;
			case CHG_FRAME:	change_frame(); break;
			case SHOW_STACK:	show_stack(); break;
			case CHG_STACK:	change_stack(); break;
			case SHOW_SYMBS:	printST(); printf ("\n"); break;
/* breakpoint choices */
			case SET_BREAK:	set_break(); break;
			case SHOW_BREAK:	show_break(); break;
			case CLR_BREAK:	clear_break(); break;
			case ZERO_BREAK:	zero_break(); break;
			default: break;
		}
	}
	while (!(run_it && loaded) && !*done);
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* manipulate the breakpoints */

struct brkpt *first_brk = 0L;
static void set_break ()
{
	char		s[35];
	struct brkpt *p = (struct brkpt*)malloc(sizeof(struct brkpt));
	p->next = first_brk;
	first_brk = p;
	scanf ("%s", s);
	if (isdigit (s[0])) sscanf (s, "%d", &(p->point.bot));
	else if (isalpha (s[0])) p->point = symb_value (s);
	else
      printf ("Bad input\n");
}
static void clear_break ()
{
	struct brkpt *p = first_brk, *q = first_brk;
	Quad val;
	char s[30]; 
	scanf ("%s", s);
	if (isdigit (s[0])) sscanf (s, "%d", &(val.bot));
	else if (isalpha (s[0])) val = symb_value (s);
	else
      printf ("Bad input\n");
	if (first_brk->point.bot == val.bot) {
		first_brk = first_brk->next; free (p); return;
	}
	p = p->next;
	for ( ; p != 0L; q = p, p = p->next)
		if (p->point.bot == val.bot) {
			q->next = p->next; free (p); return;
		}
	printf ("No breakpoint at %s\n", s);
}
static void show_break ()
{
	struct brkpt *p = first_brk;
	for ( ; p != 0L; p = p->next)
		printf ("%d ", p->point.bot);
	printf ("\n");
}
static void zero_break ()
{
	struct brkpt *q;
	while (first_brk != 0L) {
		q = first_brk;  first_brk = first_brk->next;
		free (q);
	}
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/

show_state()
{
	int	i, instr = get_code_byte(PC), offset = 1, size;
	printf ("%x%x:\t%02x  %s", PC.top,PC.bot, instr, instrs[instr].name);
	for (i=1; i<=instrs[instr].no_arg; i++) {
		switch (size = instrs[instr].arg_size[i-1]) {
			case 1: printf (" %02x", get_code_byte (qadd (PC, i2q(offset)))); 
				break;
			case 2: printf (" %04x", get_code_word (qadd (PC, i2q(offset)))); 
				break;
			case 4: printf (" %08lx", get_code_long (qadd (PC, i2q(offset)))); 
				break;
			case 8: {
				Quad q; q = get_code_quad (qadd (PC, i2q(offset))); 
				printf (" %08x%08x", q.top, q.bot); break;
			}
			default: printf ("Internal Error");
		}
		offset += size;
	}
	printf ("\n");
}

void load_command_files (argc, argv)
int	argc;
char	*argv[];
{
	initial_load_files (argc, argv);
	yylex ();
	loaded = TRUE; run_it = FALSE; PC = entry;
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* change values */

static void change_code()
{
	int	beg;  char new[8], str[8];
	char s[30]; 
	scanf ("%s", s);
	if (isdigit (s[0])) sscanf (s, "%d", &beg);
	else if (isalpha (s[0])) beg = (symb_value (s)).bot;
	else {
      printf ("Bad input\n"); return;
	}
	strcpy (str, "0x");
	for (;; beg++) {
		int i = 0;
		printf ("%d: %02x  ", beg, get_code_byte (i2q(beg)));
		scanf ("%s", new); printf ("\000");
		while (isspace(new[i])) i++;
		if (new[i] == '\033') break;
		if (new[i] == 'p') continue;
		strcpy (&str[2], &new[i]);
		put_code_byte (i2q(beg), Strtoq(str).bot);
	}
}

static void change_data()
{
	int	beg;  char str[8];	char s[30]; 
	scanf ("%s", s);
	if (isdigit (s[0])) sscanf (s, "%d", &beg);
	else if (isalpha (s[0])) beg = (symb_value (s)).bot;
	else {
      printf ("Bad input\n"); return;
	}
	strcpy (str, "0x");
	for (;; beg++) {
		int i = 0; char new[8];
		printf ("%d: %02x  ", beg, get_data_byte (i2q(beg)));
		scanf ("%s", new); printf ("\000");
		while (isspace(new[i])) i++;
		if (new[i] == '\033') break;
		if (new[i] == 'p') continue;
		strcpy (&str[2], &new[i]);
		put_data_byte (i2q(beg), Strtoq(str).bot);
	}
}

static void change_stack()
{
	int	beg, sp;	char str[8];
	scanf ("%d", &beg);
	sp = SP.bot + beg;
	strcpy (str, "0x");
	for (;; beg++, sp++){
		int i = 0; char new[8];
		printf ("%d: %04x  ", beg, stack[sp]);
		scanf ("%s", new); printf ("\000");
		while (isspace(new[i])) i++;
		if (new[i] == '\033') break;
		if (new[i] == 'p') continue;
		strcpy (&str[2], &new[i]);
		stack[sp] = Strtoq(str).bot;
	}
	SP.bot = sp;
}

static void change_frame()
{
	int	frame, beg;	char	str[8];	char s[30]; 
	scanf ("%d %d", &frame, &beg);
/*	scanf ("%s", s);
	if (isdigit (s[0])) sscanf (s, "%d", &beg);
	else if (isalpha (s[0])) beg = (symb_value (s)).bot;
	else {
      printf ("Bad input\n"); return;
	}
*/
	strcpy (str, "0x");
	for (;; beg++) {
		int i = 0; char new[8];
		printf ("%d  %d: %04x  ", frame, beg, get_frame_word (frame, i2q(beg)));
		scanf ("%s", new); printf ("\000");
		while (isspace(new[i])) i++;
		if (new[i] == '\033') break;
		if (new[i] == 'p') continue;
		strcpy (&str[2], &new[i]);
		put_frame_word (frame, i2q(beg), Strtoq(str).bot);
	}
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* show values */

static void  show_code()
{
	unsigned int	beg, end, i;
	char	s1[30], s2[30];
	scanf ("%s %s", s1, s2);
	if (isdigit (s1[0])) sscanf (s1, "%d", &beg);
	else if (isalpha (s1[0])) beg = (symb_value (s1)).bot;
	else {
      printf ("Bad input\n"); return;
	}
	if (isdigit (s2[0])) sscanf (s2, "%d", &end);
	else if (isalpha (s2[0])) end = (symb_value (s2)).bot;
	else if (s2[0] == '+') {
		sscanf (&(s2[1]), "%d", &end); end += beg - 1; }
	else {
      printf ("Bad input\n"); return;
	}
	for (i = beg; i <= end; i++){
		printf ("%02x ", get_code_byte(i2q(i)));
		if ((i-beg)%16 == 15) printf ("\n");
	}
	printf ("\n");
}

static void show_data()
{
	unsigned int	beg, end, i;
	char	s1[30], s2[30];
	scanf ("%s %s", s1, s2);
	if (isdigit (s1[0])) sscanf (s1, "%d", &beg);
	else if (isalpha (s1[0])) beg = (symb_value (s1)).bot;
	else {
      printf ("Bad input\n"); return;
	}
	if (isdigit (s2[0])) sscanf (s2, "%d", &end);
	else if (isalpha (s2[0])) end = (symb_value (s2)).bot;
	else if (s2[0] == '+') {
		sscanf (&(s2[1]), "%d", &end); end += beg - 1; }
	else {
      printf ("Bad input\n"); return;
	}
	for (i = beg; i <= end; i++){
		printf ("%02x ", get_data_byte(i2q(i)));
		if ((i-beg)%16 == 15) printf ("\n");
	}
	printf ("\n");
}

static void show_frame()
{
	unsigned int frame, offset;
	scanf ("%d %d", &frame, &offset);
	printf ("%04x\n", get_frame_word (frame, i2q(offset)));
}

static void show_stack()
{
	unsigned int	i = (((int)(SP.bot)-20)<0 ? 0 : (SP.bot)-20);
	for ( ; i < SP.bot; i++) {
		printf ("%04x ", stack[i]);
	}
	printf ("  <-TOS @ %08x\n", SP.bot);
}
