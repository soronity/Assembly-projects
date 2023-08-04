    .data
str: .asciiz "\nHello, world!"

    .text
    .globl main

main:
    la $a0, str  # Load address of string into $a0
    li $v0, 4    # System call code for print_string is 4
    syscall      # Call operating system to output string
    
    # Exit
    li $v0, 10   # System call code for exit is 10
    syscall      # Call operating system to terminate program
