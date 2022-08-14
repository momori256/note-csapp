	.file	"switch.c"
	.text
	.globl	f
	.type	f, @function
f:
.LFB0:
	.cfi_startproc
	subl	$51, %edi
	cmpl	$5, %edi
	ja	.L2
	movl	%edi, %edi
	leaq	.L4(%rip), %rdx
	movslq	(%rdx,%rdi,4), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L8-.L4
	.long	.L9-.L4
	.long	.L6-.L4
	.long	.L10-.L4
	.long	.L11-.L4
	.long	.L11-.L4
	.text
.L6:
	movl	$1, %eax
.L7:
	addl	$3, %eax
.L5:
	addl	$4, %eax
	ret
.L8:
	movl	$2, %eax
	ret
.L9:
	movl	$3, %eax
	jmp	.L7
.L10:
	movl	$1, %eax
	jmp	.L5
.L2:
	movl	$11, %eax
	ret
.L11:
	movl	$6, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	movl	$53, %edi
	call	f
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 12.1.0"
	.section	.note.GNU-stack,"",@progbits
