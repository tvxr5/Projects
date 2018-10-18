.CODE
/* A = 34 */

/* addr (A) is 0 */
PUSHW A
PUSHW 34
PUTSW

/* B = 96 - A */ /* addr (B) is 2 */
PUSHW B  /* addr of B */		/* stack  addr B */
PUSHW 96								/* addr B | 96 */
PUSHW A  /* addr of A */		/* addr B | 96 | addr A */
GETSW									/* addr B | 96 | value of A */
SUBI									/* addr B | value of (96 - A) */
PUTSW									/* -- */  /* value goes into B */

/* PUT B */
PUSHW B
GETSW
PUSHW 1
SYSCALL

.DATA
A:0:
B:2:
