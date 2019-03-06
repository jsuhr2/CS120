.text

main:	addi $a0, $0, 5
	jal print_table
	addi $a0, $0, 6
	jal print_table
	li $v0, 10
	syscall

print_table:	add $t1, $0, $a0
	add $s0, $0, $0
	add $t0, $0, $ra
	for1:	beq $s0, $t1, done
		add $s1, $0, $0
		for2:	beq $s1, $t1, bob
			jal entry
			li $v0, 1
			syscall
			addi $s1, $s1, 1
			j for2
		bob: addi $a0, $0, 10
		li $v0, 11
		syscall
		addi $s0, $s0, 1
		j for1

entry: 	mul $a0, $s0, $s1
	jr $ra

done:	jr $t0
