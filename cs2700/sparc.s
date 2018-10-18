	.file	"sample.c"
gcc2_compiled.:
.section	".rodata"
	.align 8
.LLC0:
	.asciz	"%d\n"
.section	".text"
	.align 4
	.global main
	.type	 main,#function
	.proc	04
main:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
	!#PROLOGUE# 1
	mov	4, %o0
	call	fact, 0
	 nop
	mov	%o0, %o1
	sethi	%hi(.LLC0), %o2
	or	%o2, %lo(.LLC0), %o0
	call	printf, 0
	 nop
.LL2:
	ret
	restore
.LLfe1:
	.size	 main,.LLfe1-main
	.global .umul
	.align 4
	.global fact
	.type	 fact,#function
	.proc	04
fact:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %o0
	cmp	%o0, 0
	bne	.LL4
	nop
	mov	1, %i0
	b	.LL3
	 nop
.LL4:
	ld	[%fp+68], %o0
	add	%o0, -1, %o1
	mov	%o1, %o0
	call	fact, 0
	 nop
	mov	%o0, %o1
	mov	%o1, %o0
	ld	[%fp+68], %o1
	call	.umul, 0
	 nop
	mov	%o0, %i0
	b	.LL3
	 nop
.LL3:
	ret
	restore
.LLfe2:
	.size	 fact,.LLfe2-fact
	.ident	"GCC: (GNU) 2.95.2 19991024 (release)"
