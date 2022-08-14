	.file	"if.c"
	.text
	.globl	f1
	.type	f1, @function
f1:
.LFB11:
	.cfi_startproc
	leal	1(%rdi), %eax
	ret
	.cfi_endproc
.LFE11:
	.size	f1, .-f1
	.globl	f2
	.type	f2, @function
f2:
.LFB12:
	.cfi_startproc
	leal	2(%rdi), %eax
	ret
	.cfi_endproc
.LFE12:
	.size	f2, .-f2
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$2, %edi
	call	f1
	movl	%eax, %ebx
	movl	$3, %edi
	call	f2
	cmpl	%eax, %ebx
	jnb	.L5
	movl	$0, %eax
.L3:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L5:
	.cfi_restore_state
	movl	$1, %eax
	jmp	.L3
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.ident	"GCC: (GNU) 12.1.0"
	.section	.note.GNU-stack,"",@progbits
