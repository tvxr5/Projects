#include <stdio.h>
#include "envir.h"

static int chval ();

Quad qadd (fst, sec)
Quad	fst, sec;
{
	unsigned int temp1;
	Quad ans;
	temp1 = (fst.bot&0xffff) + (sec.bot&0xffff);
	ans.bot = temp1 & 0xffff;
	temp1 >>= 16;	 /* this is the carry */
	temp1 += ((fst.bot>>16)&0xffff) + ((sec.bot>>16)&0xffff);
	ans.bot |= (temp1 &0xffff) << 16;
	temp1 >>= 16;	 /* this is the carry */
	temp1 += (fst.top&0xffff) + (sec.top&0xffff);
	ans.top = temp1 &0xffff;
	temp1 >>= 16;	 /* this is the carry */
	temp1 += ((fst.top>>16)&0xffff) + ((sec.top>>16)&0xffff);
	ans.top |= (temp1 &0xffff) << 16;
	return ans;
}

Quad qsub (fst, sec)
Quad	fst, sec;
{
	unsigned int temp1;
	Quad ans;
	temp1 = (fst.bot&0xffff) - (sec.bot&0xffff);
	ans.bot = temp1 & 0xffff;
	temp1 >>= 16;	 /* this is the carry */
	temp1 += ((fst.bot>>16)&0xffff) - ((sec.bot>>16)&0xffff);
	ans.bot |= (temp1 &0xffff) << 16;
	temp1 >>= 16;	 /* this is the carry */
	temp1 += (fst.top&0xffff) - (sec.top&0xffff);
	ans.top = temp1 &0xffff;
	temp1 >>= 16;	 /* this is the carry */
	temp1 += ((fst.top>>16)&0xffff) - ((sec.top>>16)&0xffff);
	ans.top |= (temp1 &0xffff) << 16;
	return ans;
}

Quad qmult (fst, sec)
Quad	fst, sec;
{
	unsigned int temp1, tcarry;
	Quad ans;
	temp1 = (fst.bot&0xffff) * (sec.bot&0xffff);
	ans.bot = temp1 & 0xffff;
	temp1 >>= 16;		/* this is the carry */

	temp1 += ((fst.bot>>16)&0xffff) * (sec.bot&0xffff);
	tcarry = (temp1>>16)&0xffff; temp1 &= 0xffff;
	temp1 += (fst.bot&0xffff) * ((sec.bot>>16)&0xffff);
	ans.bot |= (temp1&0xffff)<<16;
	temp1 >>= 16; temp1 += tcarry;

	/* need top longword */
	temp1 += (fst.top&0xffff) * (sec.bot&0xffff);
	tcarry = (temp1>>16)&0xffff; temp1 &= 0xffff;
	temp1 += ((fst.bot>>16)&0xffff) * ((sec.bot>>16)&0xffff);
	tcarry += (temp1>>16)&0xffff; temp1 &= 0xffff;
	temp1 += (fst.bot&0xffff) * (sec.top&0xffff);
	ans.top = temp1 & 0xffff;
	temp1 >>= 16; temp1 += tcarry;

	temp1 += ((fst.top>>16)&0xffff) * (sec.bot&0xffff);
	temp1 &= 0xffff;		/* don't need to worry about carry */
	temp1 += (fst.top&0xffff) * ((sec.bot>>16)&0xffff);
	temp1 &= 0xffff;
	temp1 += ((fst.bot>>16)&0xffff) * (sec.top&0xffff);
	temp1 &= 0xffff;
	temp1 += (fst.bot&0xffff) * ((sec.top>>16)&0xffff);
	ans.top |= (temp1&0xffff)<<16;

	return ans;
}

Quad qdiv (fst, sec)
Quad	fst, sec;
{
	unsigned int temp1;
	Quad ans;
	ans.top = ans.bot = 0;
	return ans;
}

Quad qshftl (val, amt)
Quad	val;
word	amt;
{
	Quad	ans;
	union {unsigned int l; struct {unsigned short t, b;}p;} temp;
	temp.p.t = (val.top & 0xffff);
	temp.p.b = (val.bot >>  16) &0xffff;
	ans.top = val.top << amt;
	ans.bot = val.bot << amt;
	temp.l <<= amt;
	ans.top |= ((unsigned int)temp.p.t) & 0xffff;
	ans.bot |= (((unsigned int)temp.p.b) & 0xffff) << 16;
	return ans;
}

Quad qshftr (val, amt)
Quad	val;
word	amt;
{
	Quad	ans;
	union {unsigned int l; struct {unsigned short t, b;}p;} temp;
	temp.p.t = (val.top & 0xffff);
	temp.p.b = (val.bot >>  16) &0xffff;
	ans.top = val.top >> amt;
	ans.bot = val.bot >> amt;
	temp.l >>= amt;
	ans.top |= ((unsigned int)temp.p.t) & 0xffff;
	ans.bot |= (((unsigned int)temp.p.b) & 0xffff) << 16;
	return ans;
}

Quad Strtoq (str)
char *str;
{
	Quad	ans;
	int base = 10, c, s = 1;
	ans = q0;
	if (str[0] == '-' || str[0] == '+')
		s = *(str++) == '-' ? -1 : 1; 
	if (str[0] == '0')
		if (str[1] == 'x' || str[1] == 'X') {
			base = 16; str = &(str[2]);
		}
	else
		base = 8;
	while (*str != '\0' && (c=chval(*str)) < base) {
		str ++;
		ans = qadd (qshftl (ans, base==16 ? 4 : 3), 
						base==10 ? qshftl (ans, 1): q0);
		ans = qadd (ans, i2q (c));
	}
	if (s == -1) {
		ans.top = ~ans.top; ans.bot = ~ans.bot; 
		ans = qadd (ans, q1); 
	}
	return ans;
}
static int chval (ch)
char	ch;
{	switch (ch) {
		case '0' :				 return 0;
		case '1' :				 return 1;
		case '2' :				 return 2;
		case '3' :				 return 3;
		case '4' :				 return 4;
		case '5' :				 return 5;
		case '6' :				 return 6;
		case '7' :				 return 7;
		case '8' :				 return 8;
		case '9' :				 return 9;
		case 'a' : case 'A' : return 10;
		case 'b' : case 'B' : return 11;
		case 'c' : case 'C' : return 12;
		case 'd' : case 'D' : return 13;
		case 'e' : case 'E' : return 14;
		case 'f' : case 'F' : return 15;
		default : return 1024;
	}
}
