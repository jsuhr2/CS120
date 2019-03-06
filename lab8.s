.data
message: .asciiz "Jasper Suhr.\n"

.text

main:	la $a0, message
	add $s0, $0, 0
	addi $t0, $0, 10
	

for:	beq $s0, $t0, done
	li $v0, 4
	syscall
	addi $s0, $s0, 1
	j for

done: 	li $v0, 10
	syscall


