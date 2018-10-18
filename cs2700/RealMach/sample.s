	.file	"sample.c"
	.section	".rodata"
	.align 8
.LLC0:
	.asciz	"%d\n"
	.section	".text"
	.align 4
	.global main
	.type	main, #function
	.proc	04
main:
	!#PROLOGUE# 0
	save	%sp, -112, %sp
	!#PROLOGUE# 1
	mov	4, %o0
	call	fact, 0
	 nop
	mov	%o0, %g1
	sethi	%hi(.LLC0), %o5
	or	%o5, %lo(.LLC0), %o0
	mov	%g1, %o1
	call	printf, 0
	 nop
	mov	%g1, %i0
	ret
	restore
	.size	main, .-main
	.global .umul
	.align 4
	.global fact
	.type	fact, #function
	.proc	04
fact:
	!#PROLOGUE# 0
	save	%sp, -120, %sp
	!#PROLOGUE# 1
	st	%i0, [%fp+68]
	ld	[%fp+68], %g1
	cmp	%g1, 0
	bne	.LL3
	nop
	mov	1, %g1
	st	%g1, [%fp-20]
	b	.LL2
	 nop
.LL3:
	ld	[%fp+68], %g1
	add	%g1, -1, %g1
	mov	%g1, %o0
	call	fact, 0
	 nop
	mov	%o0, %g1
	mov	%g1, %o0
	ld	[%fp+68], %o1
	call	.umul, 0
	 nop
	mov	%o0, %g1
	st	%g1, [%fp-20]
.LL2:
	ld	[%fp-20], %i0
	ret
	restore
	.size	fact, .-fact
	.ident	"GCC: (GNU) 3.4.5"
