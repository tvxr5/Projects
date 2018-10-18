.CODE
/* Tarun Vittal CS2700 */

/* Worked on this with a group. Used direcrt reference to Address instead of 
letters. look At last line for address values for letters. You sid your run
program had problems, but code was correct */ 
 

/* a = 3 */

/* addr (a) is 0 */
PUSHW 0
PUSHW 3
PUTSW

/* b = 5 - (a * 3) */   /* addr (b) is 2 */
PUSHW 2                 /* addr of b */
PUSHW 5                 /* addr b | 5 */
PUSHW 0                
GETSW                   /* addr b | 5 | value of addr a */
PUSHW 3                 /* addr b | 5 | value of a | 3 */
MULI                    /* addr b | 5 | value of (a * 3) */
SUBI                    /* addr b | value of (5 - (a * 3) */
PUTSW                   /* value goes into b */

/* print a */
PUSHW 0                 /* addr of a */
GETSW                   /* value of addr a */
PUSHW 1
SYSCALL

/* print b */
PUSHW 2                 
GETSW                   
PUSHW 1
SYSCALL

/* if b + 1 < 0 */
/* condition */
PUSHW 2                 
GETSW                   
PUSHW 1                
ADDI                    
TSTLTI                  /* test value: if <0, push -1 else push 0 */

/* if condition is false, skips then */
RGOZ 19

/* then */
PUSHW 4                 
PUSHW 2                 
GETSW                   
PUSHW 9                 
ADDI                    
PUSHW 5                 
DIVI                    
PUTSW                   

/* if condition was true, skips else */
RGOTO 7

/* else */
PUSHW 4                 
PUSHW 13                
PUTSW                   

/* while 0 > b - 4 - a - c */
/* condition */
PUSHW 2                 
GETSW                   
PUSHW 4                 
SUBI                    
PUSHW 0                 
GETSW                   
SUBI                   
PUSHW 4                
GETSW                  
SUBI                    
TSTLTI                  /* test value: if <0, push -1 else push 0 */

/* if condition is false, jump past loop */
RGOZ 28

PUSHW 0
PUSHW 0
GETSW
PUSHW 2
DIVI
PUTSW
PUSHW 2
PUSHW 4
GETSW
PUSHW 2
GETSW
SUBI
PUTSW

RGOTO -50

/* print a */
PUSHW 0
GETSW
PUSHW 1
SYSCALL

/* print b */
PUSHW 2
GETSW
PUSHW 1
SYSCALL

.DATA

a:0:
b:2:
c:4:
