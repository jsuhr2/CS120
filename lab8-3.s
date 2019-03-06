.text
main:	add $s0, $0, $0
	addi $s1, $0, 5
	addi $t0, $0, 37

while:	beq $s1, $t0, done
	add $s0, $s0, $s1
	addi $s1, $s1, 1
	j while

done:	li $v0, 10
	syscall
