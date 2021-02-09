.data
astric:.asciiz "*"
line:.byte'\n'
.text

li $t0, 1
outer:

#prints a new line
li $v0,4
la $a0,line
syscall


li $t1, 1
inner:

li $v0, 4 #instead of integer it prints out * because 4 is string
la $a0,astric
syscall

add $t1, $t1, 1
ble $t1, $t0, inner

#goes to 7 in 1234567
add $t0, $t0, 1
ble $t0, 7 outer
