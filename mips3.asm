li $t1, 4096 #t1 = 2048
loop1: #creates loop
srl $t1,$t1 1 # shifts right dividing by 2 *think decimal binary*

add $a0, $t1, $zero # loads the rest of numbers
li $v0, 1 #prints out 
syscall 

add $a0, $zero,32  # loads the rest of numbers
li $v0, 11 #prints out 
syscall 
bne $t1, 0, loop1 # ends loop when t1 reaches 0