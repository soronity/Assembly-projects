.data 
prompt: .asciiz "Guess a number between 1 and 100: "
win_msg: .asciiz "You won <3\n"
lose_msg: .asciiz "You lose :(\n"
low_msg: .asciiz "Too low dude\n"
high_msg: .asciiz "You're too high man\n"

.text
.globl main

rand_range: 
  li $v0, 42
  li $a0, 100

