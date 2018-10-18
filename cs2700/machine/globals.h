#include <stdlib.h>

#define MAX_CODE_SPACE	2000
#define MAX_DATA_SPACE	2000
#define MAX_STACK_SPACE 2000
#define FALSE	0
#define TRUE	-1

typedef unsigned char	byte;
typedef unsigned short	word;
typedef unsigned long	lword;
typedef struct {lword top, bot;}	Quad;
#define	Q0	{0,0}
#define	Q1	{0,1}
#define	Q2	{0,2}
#define	Q4	{0,4}
#define	Q8	{0,8}

/* Exception Values */
#define	TRA_EX	1
#define	DIV_EX	2
#define	MT_STACK	3

struct brkpt {
	Quad	point;
	struct brkpt	*next;
};
