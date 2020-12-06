	.file	"part_one.c"
	.text
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"input.txt"
.LC2:
	.string	"%d"
.LC3:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$848, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -824(%rbp)
	movl	$0, -828(%rbp)
	jmp	.L2
.L3:
	movl	-828(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -828(%rbp)
	movl	-840(%rbp), %edx
	cltq
	movl	%edx, -816(%rbp,%rax,4)
.L2:
	leaq	-840(%rbp), %rdx
	movq	-824(%rbp), %rax
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	cmpl	$-1, %eax
	jne	.L3
	movl	$0, -836(%rbp)
	jmp	.L4
.L8:
	movl	-836(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -832(%rbp)
	jmp	.L5
.L7:
	movl	-836(%rbp), %eax
	cltq
	movl	-816(%rbp,%rax,4), %edx
	movl	-832(%rbp), %eax
	cltq
	movl	-816(%rbp,%rax,4), %eax
	addl	%edx, %eax
	cmpl	$2020, %eax
	jne	.L6
	movl	-836(%rbp), %eax
	cltq
	movl	-816(%rbp,%rax,4), %edx
	movl	-832(%rbp), %eax
	cltq
	movl	-816(%rbp,%rax,4), %eax
	imull	%edx, %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L6:
	addl	$1, -832(%rbp)
.L5:
	cmpl	$199, -832(%rbp)
	jle	.L7
	addl	$1, -836(%rbp)
.L4:
	cmpl	$199, -836(%rbp)
	jle	.L8
	movq	-824(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
