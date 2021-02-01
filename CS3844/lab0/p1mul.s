	.file	"p1mul.c"
	.text
.globl mul
	.type	mul, @function
mul:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	imull	8(%ebp), %eax
	popl	%ebp
	ret
	.size	mul, .-mul
	.ident	"GCC: (Ubuntu 4.3.3-5ubuntu4) 4.3.3"
	.section	.note.GNU-stack,"",@progbits
