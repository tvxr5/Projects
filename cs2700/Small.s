.CODE .ENTRY 0
0:	PUSHW 0 PUSHW 56 PUTSW 
7:	PUSHW 0 GETSW PUSHW 95 SWAPW SUBI TSTLTI NOTW RGOZ 70   
21:	PUSHW 0 GETSW PUSHW 0 GETSW PUSHW 2 DIVI PUSHW 2 MULI SUBI 
	TSTEQI RGOZ 12   
42:	PUSHW 0 PUSHW 2 GETSW PUSHW 2 DIVI PUTSW 
54:	PUSHW 2 GETSW PUSHW 0 GETSW PUSHW 2 DIVI PUSHW 2 MULI SUBI 
	TSTEQI NOTW RGOZ 12   
76:	PUSHW 0 PUSHW 0 GETSW PUSHW 3 ADDI PUTSW 
88:	RGOTO -84 
91:	HALT 
