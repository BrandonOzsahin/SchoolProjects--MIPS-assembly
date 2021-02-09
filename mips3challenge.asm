li $v0, 5
syscall
add $t0, $zero, $v0

li $t1, 255
srl $t0, $t0, 16
and $t3, $t0, $t1

add $a0, $zero, $t3
li $v0, 1
syscall

