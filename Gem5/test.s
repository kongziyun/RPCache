	.file	"test.c"
	.intel_syntax noprefix
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR [rbp-4], 0
	mov	DWORD PTR [rbp-8], 0
	jmp	.L2
.L3:
	mov	eax, DWORD PTR [rbp-8]
	add	DWORD PTR [rbp-4], eax
	add	DWORD PTR [rbp-8], 1
.L2:
	cmp	DWORD PTR [rbp-8], 9
	jle	.L3
	mov	eax, 0
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.7.0"
	.section	.note.GNU-stack,"",@progbits
