.section .data
.insira:
    .word 0x69736e49
    .word 0x75206172
    .word 0x756e206d
    .word 0x6f72656d
    .word 0x72617020
    .word 0x61662061
    .word 0x69726f74
    .word 0x203a6c61

.resultado:
    .word 0x6166204f
    .word 0x69726f74
    .word 0xe9206c61
    .word 0x0000203a

.section .text
fact: # recebe a0, devolve a1
    addi  sp, sp, -8
    sw ra, 0(sp)
    blt a0, t5, ultimo   # enquanto a0 n for menor q 2
        sw a0, 4(sp)     # continua empilhando
        addi a0, a0, -1  # 
        call fact

    lw t0, 4(sp)
    addi t2, t0, -1
    addi t4, a1, 0
    # fazer t0 vezes a1
    loop:		   # loop de multiplicacao
        add a1, a1, t4
        sub t2, t2, t3
        blt zero, t2, loop
    j final

ultimo:
    addi a1, zero, 1

final:
    lw ra, 0(sp)
    addi sp, sp, 8
    ret

main:
    # printa inserir
    addi t0, zero, 3
	lui a0, %hi(.insira)
	addi a0, a0, %lo(.insira)
	addi a1, zero, 32
	ecall

    # valores fixos para blt e beq
    addi t5, zero, 2
    addi t3, zero, 1

    addi t0, zero, 4
    ecall

    call fact
    addi t1, a1, 0

    # printa o resultado eh
    addi t0, zero, 3
	lui a0, %hi(.resultado)
	addi a0, a0, %lo(.resultado)
	addi a1, zero, 16
	ecall

    #printa resultado
    addi a0, t1, 0
    addi t0, zero, 1
	ecall
    
