.section .data
vector:
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000

.section .text
main:
    # Printa Informacoes para colocar 5 numeros


    # Funcao Inserir 5 numeros
    funcinserir:
        addi t3, zero, 1	
        addi t2, zero, 5
        addi s0, zero, %lo(vector) # carrega data
        
        addi t0, zero, 4
        loopguardar:
            ecall
            sw a0, 0(s0)
            
            addi s0, s0, 4
            sub t2, t2, t3
            blt zero, t2, loopguardar

    # Funcao bubsort
    bubsort:
        addi t0, zero, 0 # verifica loop
        addi t2, zero, 4 # posicao atual
        addi t3, zero, 1 # registrador 1
        addi s0, s0, -16 # posicao inicial fixa
        loop:
            lw t4, -4(s0)       # carrega t4
            lw t5, 0(s0)        # carrega t5
            ble t4, t5, verf    # compara t4 com t5
                addi t0, zero, 1
                sw t4, 0(s0)
                sw t5, -4(s0)
            verf:
            addi s0, s0, 4
            sub t2, t2, t3
            blt zero, t2, loop
            bne t0, zero, bubsort

    # Funcao imprimir
    addi s0, s0, -20 # Retorna vetor para o inicio
    imprimir:
        addi t3, zero, 1	
        addi t2, zero, 5
        addi t0, zero, 1
        loopimprimir:
            lw a0, 0(s0)
            ecall
            
            addi s0, s0, 4
            sub t2, t2, t3
            blt zero, t2, loopimprimir
