.text

main:	addi $s0, $0, 4
	addi $s1, $0, 10
	add $s2, $s0, $s1

	bne $s0, $s2, else
	add $s2, $s2, $s1
	j done

else:	add $s1, $s0, $s1

done:	li $v0, 10
	syscall
