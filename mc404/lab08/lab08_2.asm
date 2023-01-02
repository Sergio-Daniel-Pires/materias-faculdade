.section .text
main:
    addi t0, zero, 5
    addi t1, zero, 0
    addi s1, zero, 32
    loopchar:
        addi t1, t1, 1
        addi sp, sp, -4
        ecall
        sw a0, 0(sp)
        bne a0, s1, loopchar
    
    addi t1, t1, -1  
    addi sp, sp, 4
    
    # printa
    addi t0, zero, 2
    loopprint:
        lw a0, 0(sp)
        ecall
        addi sp, sp, 4
        addi t1, t1, -1
        blt zero, t1, loopprint
