.text
main:	addi $s1, $0, 0
	add $s0, $0, 0
	addi $t0, $0, 20

for:	beq $s0, $t0, done
	add $s1, $s1, $s0
	addi $s0, $s0, 1
	j for
done:
	li $v0, 1 # Syscall for print_int
	add $a0, $s1, $0 # Move s1 into a0
	syscall

	li $v0, 10
	syscall
