	.file	"sample.c"
gcc2_compiled.:
___gnu_compiled_c:
.text
LC0:
	.ascii "%d\12\0"
	.p2align 2
.globl _main
_main:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	addl $-8,%esp
	addl $-12,%esp
	pushl $4
	call _fact
	addl $16,%esp
	movl %eax,%eax
	pushl %eax
	pushl $LC0
	call _printf
	addl $16,%esp
L2:
	movl %ebp,%esp
	popl %ebp
	ret
	.p2align 2
.globl _fact
_fact:
	pushl %ebp
	movl %esp,%ebp
	subl $8,%esp
	cmpl $0,8(%ebp)
	jne L4
	movl $1,%eax
	jmp L3
	.p2align 4,,7
L4:
	addl $-12,%esp
	movl 8(%ebp),%eax
	decl %eax
	pushl %eax
	call _fact
	addl $16,%esp
	movl %eax,%eax
	movl %eax,%edx
	imull 8(%ebp),%edx
	movl %edx,%eax
	jmp L3
	.p2align 4,,7
L3:
	movl %ebp,%esp
	popl %ebp
	ret
