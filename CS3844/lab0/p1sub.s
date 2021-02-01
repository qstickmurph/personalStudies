	.file	"p1sub.c"
	.text
.globl sub
	.type	sub, @function
sub:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	subl	12(%ebp), %eax
	popl	%ebp
	ret
	.size	sub, .-sub
	.ident	"GCC: (Ubuntu 4.3.3-5ubuntu4) 4.3.3"
	.section	.note.GNU-stack,"",@progbits
