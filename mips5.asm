addi $t3, $zero,0

loop:
beq $t3, 10, exit
addi $v0, $zero, 5
syscall
sw $v0, 0($sp)
addi $sp, $sp, 4

addi $t3, $t3, 1
j loop
exit:

addi $t2, $zero, 0
loop2:
beq $t2, 10, end

addi $sp, $sp, -4
lw $a0, 0($sp)
li $v0, 1
addi $t2, $t2, 1
syscall
j loop2
end:
