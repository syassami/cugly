.text

	.globl	Main
factorial:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$4,%esp
	pushl	8(%ebp)
	popl	%eax
	movl	%eax, -4(%ebp)
	pushl	8(%ebp)
	pushl	$0
	popl	%ecx
	popl	%eax
	subl	%eax, %ecx
	jecxz	true_label_2
	shr	$31, %ecx
	jecxz	true_label_2
	movl	$0, %eax
	jmp	done_label_3
true_label_2:
	movl	$1, %eax
done_label_3:
	pushl	%eax
	pushl	$1
	popl	%eax
	movl	%eax, -4(%ebp)
	popl	%ecx
	jecxz	else_label_0
	jmp	done_label_1
else_label_0:
	pushl	8(%ebp)
	pushl	$1
	popl	%ebx
	popl	%eax
	subl	%ebx, %eax
	pushl	%eax
	call	factorial
	movl	%eax, 8(%ebp)
	popl %eax
	pushl	-4(%ebp)
	pushl	8(%ebp)
	popl	%eax
	popl	%ebx
	imull	%ebx, %eax
	pushl	%eax
	popl	%eax
	movl	%eax, -4(%ebp)
done_label_1:
	pushl	-4(%ebp)
	popl	%eax
	movl	%ebp,%esp
	popl	%ebp
	ret
Main:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$4,%esp
	pushl	$5
	call	factorial
	movl	%eax, -4(%ebp)
	popl %eax
	pushl	-4(%ebp)
	pushl	$2
	movl	$1, %eax
	movl	$1, %ebx
	imull	%ebx
	popl	%ebx
	popl	%eax
	idivl	%ebx
	pushl	%eax
	popl	%eax
	movl	%eax, -4(%ebp)
	pushl	-4(%ebp)
	popl	%eax
	movl	%ebp,%esp
	popl	%ebp
	ret
#  +-- Symbol Scope (0 bytes at 822b008)---
# | factorial (offset=0,scope=822b008)
# | Main (offset=0,scope=822b008)
# +-------------
#
# 	 +-- Symbol Scope (4 bytes at 822ff90)---
# 	| i (offset=0,scope=822ff90)
# 	| j (offset=-4,scope=822ff90)
# 	+-------------
#
# 	 +-- Symbol Scope (4 bytes at 8230480)---
# 	| a (offset=-4,scope=8230480)
# 	+-------------
#
