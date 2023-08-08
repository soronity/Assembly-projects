.data 
prompt: .asciiz "Guess a number between 1 and 100: "
win_msg: .asciiz "You won <3\n"
low_msg: .asciiz "Too low dude\n"
high_msg: .asciiz "You're too high man\n"

target_number: .word 50 
userGuess: .space 4

.text
main: 
  li $v0, 4
  la $a0, prompt
  syscall

  li $v0, 5
  syscall
  move $t0, $v0

  lw $t1, target_number
  beq $t0, $t1, correct_response
  blt $t0, $t1, too_low_respone
  bgt,$t0, $t1, too_high_response

correct_response:
  li $v0, 4
  la $a0, win_msg
  syscall
  j end

too_low_respone:
  li $v0, 4
  la $a0, low_msg
  syscall
  j main

too_high_response:
  li $v0, 4
  la $a0, high_msg
  syscall
  j main

end:
  li $v0, 10
  syscall 
