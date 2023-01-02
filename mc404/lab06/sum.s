.section .text

main:
    
    addi t0,zero,5  # valores em t0 e t1
    addi t1,zero,5

    add a0,t1,t0    # somando t0 com t1 e guardando em a0
    
    addi t0,zero,1  # impressao de inteiro - t0=1 e a0 o inteiro

    ecall 

    jr ra
