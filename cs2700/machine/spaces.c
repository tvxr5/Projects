#include <stdio.h>
#include "globals.h"
#include "spaces.h"
#define CODE_SIZE 0x400
#define DATA_SIZE 0x400
#define STACK_SIZE 0x400

byte	code[CODE_SIZE], data[DATA_SIZE];
word	stack[STACK_SIZE];
Quad	FP[20];
Quad	PC = Q0, SP = Q0;
Quad  q0 = Q0, q1 = Q1, q2 = Q2, q4 = Q4, q8 = Q8;

	/* access routines for the memory arrays */
byte get_code_byte(pos)
Quad	pos;
{	return (byte)(code[pos.bot]); }

byte get_data_byte(pos)
Quad	pos;
{	return (byte)(data[pos.bot]); }

word get_code_word(pos)
Quad	pos;
{
	return ((word)code[pos.bot+1]<<8) | code[pos.bot]; }

word get_data_word(pos)
Quad	pos;
{	return ((word)data[pos.bot+1]<<8) | data[pos.bot]; }

lword get_code_long(pos)
Quad	pos;
{	return (((lword)code[pos.bot+3]<<8 | code[pos.bot+2])<<8 |
			 code[pos.bot+1])<<8 | code[pos.bot];
}

lword get_data_long(pos)
Quad	pos;
{	return (((lword)data[pos.bot+3]<<8 | data[pos.bot+2])<<8 |
			 data[pos.bot+1])<<8 | data[pos.bot];
}

Quad get_code_quad(pos)
Quad pos;
{	Quad val;
	val.top = get_code_long (qadd (pos, q4));
	val.bot = get_code_long (pos);
	return val;
}

Quad get_data_quad(pos)
Quad pos;
{	Quad val;
	val.top = get_data_long (qadd (pos, q4));
	val.bot = get_data_long (pos);
	return val;
}

void put_code_byte(pos, val)
Quad		pos;
byte		val;
{	code[pos.bot] = (byte)val; }

void put_data_byte(pos, val)
Quad		pos;
byte	val;
{	data[pos.bot] = (byte)val; }

void put_code_word(pos, val)
Quad		pos;
word		val;
{	code[pos.bot] = val & 0x0ff; code[pos.bot+1] = (val>>8) & 0x0ff; }

void put_data_word(pos, val)
Quad		pos;
word		val;
{	data[pos.bot] = val & 0x0ff; data[pos.bot+1] = (val>>8) & 0x0ff; }

void put_code_long(pos, val)
Quad		pos;
lword		val;
{	code[pos.bot]   = val      & 0x0ff; code[pos.bot+1] = (val>>=8)& 0x0ff;
	code[pos.bot+2] = (val>>=8)& 0x0ff; code[pos.bot+3] = (val>>=8)& 0x0ff;
}

void put_data_long(pos, val)
Quad		pos;
lword		val;
{	data[pos.bot]   = val      & 0x0ff; data[pos.bot+1] = (val>>=8)& 0x0ff;
	data[pos.bot+2] = (val>>=8)& 0x0ff; data[pos.bot+3] = (val>>=8)& 0x0ff;
}

void put_code_quad(pos, val)
Quad		pos;
Quad		val;
{	put_code_long (qadd (pos, q4), val.top);
	put_code_long (pos, val.bot);
}

void put_data_quad(pos, val)
Quad		pos;
Quad		val;
{	put_data_long (qadd (pos, q4), val.top);
	put_data_long (pos, val.bot);
}

	/* access routines for the stack */

byte get_frame_byte (frame, offset)
word	frame;
Quad	offset;
{	return (stack[FP[frame].bot+offset.bot] & 0xff); }

word get_frame_word (frame, offset)
word	frame;
Quad	offset;
{	return (stack[FP[frame].bot+offset.bot]); }

lword get_frame_long (frame, offset)
word	frame;
Quad	offset;
{	return (stack[FP[frame].bot+offset.bot+1]<<16 | stack[FP[frame].bot+offset.bot]); }

Quad get_frame_quad (frame, offset)
word	frame;
Quad	offset;
{	Quad val;
	val.top = get_frame_long (frame, qadd (offset, q2));
	val.bot = get_frame_long (frame, offset);
	return val;
}

void put_frame_byte (frame, offset, value)
word	frame;
Quad	offset;
byte	value;
{	stack[FP[frame].bot+offset.bot] = (word)value; }

void put_frame_word (frame, offset, value)
word	frame;
Quad	offset;
word	value;
{	stack[FP[frame].bot+offset.bot] = value; }

void put_frame_long (frame, offset, value)
word	frame;
Quad	offset;
lword	value;
{	stack[FP[frame].bot+offset.bot] = value & 0xffff;
	stack[FP[frame].bot+offset.bot+1] = value>>16 & 0xffff;
}

void put_frame_quad (frame, offset, value)
word	frame;
Quad	offset;
Quad	value;
{	put_frame_long (frame, qadd (offset, q2), value.top);
	put_frame_long (frame, offset, value.bot);
}

void pushb (value)
byte	value;
{	stack[SP.bot] = value; SP = qadd (SP, q1);}

void pushw (value)
word value;
{	stack[SP.bot] = value; SP = qadd (SP, q1);}

void pushl (value)
lword	value;
{
	stack[SP.bot] = value & 0x0ffff; SP = qadd (SP, q1);
	stack[SP.bot] = (value >> 16) & 0x0ffff; SP = qadd (SP, q1);
}

void pushq (value)
Quad	value;
{	pushl (value.bot); pushl (value.top); }

byte popb ()
{	if (SP.bot == 0) rais (MT_STACK); 
	SP = qsub (SP, q1); return ((byte)(stack[SP.bot])); }

word popw ()
{	if (SP.bot == 0) rais (MT_STACK); 
	SP = qsub (SP, q1); return (stack[SP.bot]); }

lword popl ()
{	word val1;
	if (SP.bot == 0) rais (MT_STACK); 
	SP = qsub (SP, q1); val1 = stack[SP.bot];
	if (SP.bot == 0) rais (MT_STACK); 
	SP = qsub (SP, q1); return ((val1<<16) | stack[SP.bot]);
}

Quad popq ()
{	Quad val; 
	val.top = popl(); val.bot = popl();
	return val;
}

Quad i2q (value)
short	value;
{	Quad val;
	val.top = (value<0) ? -1 : 0; val.bot = value;
	return val;
}
