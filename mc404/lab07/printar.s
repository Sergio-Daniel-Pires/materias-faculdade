.section .rodata
    .HELLO:
    .word 0x3034434d
    .word 0x00002134

.section .text
main:
    
    addi t0, zero, 3
    lui a0, %hi(.HELLO)
    
    addi a0, a0, %lo(.HELLO)
    addi a1, zero, 7
    ecall
