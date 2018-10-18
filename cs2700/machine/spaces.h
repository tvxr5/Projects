byte	get_code_byte();
word	get_code_word();
lword	get_code_long();
Quad	get_code_quad();

void	put_code_byte();
void	put_code_word();
void	put_code_long();
void	put_code_quad();

byte	get_data_byte();
word	get_data_word();
lword	get_data_long();
Quad	get_data_quad();

void	put_data_byte();
void	put_data_word();
void	put_data_long();
void	put_data_quad();

byte	get_frame_byte();
word	get_frame_word();
lword	get_frame_long();
Quad	get_frame_quad();

void	put_frame_byte();
void	put_frame_word();
void	put_frame_long();
void	put_frame_quad();

void	pushb ();
void	pushw ();
void	pushl ();
void	pushq ();

byte	popb ();
word	popw ();
lword	popl ();
Quad	popq ();

Quad i2q ();
Quad qadd ();
Quad qsub ();
Quad qmult ();
Quad qdiv ();
Quad Strtoq();
