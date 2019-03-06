.text
main:	add $s0, $0, $0
	addi $s1, $0, 5
	addi $t0, $0, 37
	addi $t1, $0, 9
	add $t2, $0, $0

while:	beq $s1, $t0, done
	slt $t2, $t1, $s1
	bne $t2, $0, if
	j blah
	if: add $s0, $s0, $s1
	blah: addi $s1, $s1, 1
	j while

done:	li $v0, 10
	syscall
