.data
msg: .asciiz "Enter your number "
number: .asciiz "binary version: "
OoR: .asciiz "you are out of range enetr different number "
.text 


li $v0 4 #syscall to display mesage
la $a0 msg
syscall

li $v0, 5 #read number
syscall
add $t0, $zero, $v0 #number gets put into t0

ble $t0, 127, ifgreater #checks if it is greater or equal then 127 if it its it branches
j range #jumps to range area

ifgreater:
bge $t0, -128, iflessthen # checks if it is less then -128 

j range

range:  # displays error message 
li $v0 4
la $a0 OoR
syscall

iflessthen:
#continues code doing the loop
li $v0 4
la $a0 number
syscall

li $t1, 7 # 2^n n is 7 so the number is an 8 bits meaning highest is 0111 1111

loop:
blt $t1, 0, endloop # once t1 reaches its end the koop will end or else itll go on forevr
srlv $t2, $t0, $t1 #shifts variable to the right  of t0 tao t1 to final of t2
and $t2, 1 # && if t2 is one

li $v0, 1
addi $a0, $t2, 0 #shifts content into $a0 ( a tempororary hold variable) continuesly then displayus
syscall

beq $t1, 4 ,space #creates spaceing when 4th spot is reach
return:
sub $t1, $t1, 1 #subtracts t1 by 1 each time till 0

b loop #simple branch back to loop

 endloop: #ends program once hit final loop
 li $v0, 10
 syscall
 
 space:
 add $a0, $zero, 32 # creates space with syscall 32 
 li $v0, 11
 syscall
j return #returns back to the loop so it can continue on binary conversion