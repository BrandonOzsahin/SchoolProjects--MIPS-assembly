.data
Array: .space 10000 #creats array with size 10000
arrayinput:.asciiz "Enter size of array: "
integer: .asciiz "Enter n intergers based on size of array: "
Sorted:  .asciiz "Sorted array = "
.text

li $v0, 4 #syscall to display mesage
la $a0, arrayinput
syscall

li $v0, 5 #read number
syscall

add $t1, $v0, $zero #t5 gets integers arraay size
sub $t1, $t1, 1 # has to subtract 1 so it doesnt "overflow" and go over

addi $t0, $zero, 0 # starts loop to inut numbers into array size
loop:

li $v0, 4 #syscall to display mesage
la $a0, integer
syscall

li $v0, 5 #read number
syscall

add $t2,$t0,$zero
sll $t2, $t0,2 #shifts left by 4 (multiplies)

add $t4, $v0, 0
sw $t4, Array ($t2) #stores the array of size 10000 into t4 fom t2
addi $t0, $t0, 1 #clears t0  but its = to 1
slt $t2,$t1,$t0
beq $t2,$zero,loop
la $a0, Array


#Note:	t1 stores n-1
#t2 stores address of array
#Marks selection sort
la $t2, Array
Outer:#for (j = 0; j < n-1; j++) , where j would be $a1

add $a2,$a1,$zero #  iMin = j	  , where iMin would be a2
add $t0,$a1,1	
Inner: #for (i = j+1; i < n; i++) , where i would be $t0
#if (a[i] < a[iMin])
#{  iMin = i  }
beq $t1,$a1,EndInner
# Load a[i] on $t6
mul $t3,$t0,4
add $t3,$t3,$t2	  # t0 stores i, t2 stores address of array
lw $t6,0($t3)
# Load a[iMin] on t7
mul $t3,$a2,4
add $t3,$t3,$t2	 # a2 stores iMin, t2 stores address of array
lw $t7,0($t3)	
#Compare a[i] < a[iMin]
bge $t6,$t7,continue2
add $a2,$t0,$zero
continue2:
add $t0,$t0,1
ble $t0,$t1,Inner
EndInner:

# if (iMin != j) 
# { swap(a[j], a[iMin])}
beq $a1,$a2,continue1

#SWAP min
# Load a[j] on $t6
mul $t3,$a1,4
add $t3,$t3,$t2	  # a1 stores j, t2 stores address of array
lw $t6,0($t3)
# Load a[iMin] on t7
mul $t4,$a2,4
add $t4,$t4,$t2	 # a2 stores iMin, t2 stores address of array
lw $t7,0($t4)
#Store
sw $t6,0($t4)
sw $t7,0($t3)


continue1:
add $a1,$a1,1
blt $a1,$t1,Outer
EndOuter:
#prints sorted array msg
li $v0, 4 
la $a0, Sorted
syscall

la $t0,Array
add $t2,$zero,$zero
print:

lw $a0,0($t0) #places all value of t0 into a0 a temporary
li $v0,1 #loads integers into v0 to print
syscall


li $a0,32 	#$a0 = character to print
li $v0,11 	#print character
syscall

addi $t0,$t0,4
addi $t2,$t2,1
slt $t3,$t1,$t2
beq $t3,$zero,print




#add $t2, $t2, 1
#ble $t2, $t0, loop

#li $v0,1
#add $a0,$zero,$t0

#add $t1, $sp $zero
#addi $t1, $t1, 4
#sw 0 ($sp)
