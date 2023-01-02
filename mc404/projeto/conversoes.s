.section .data
.insira:
    .word 0x72746e45
    .word 0x3a616461
    .word 0x00000020

.resto:
    .word 0x206d6f43
    .word 0x74736572
    .word 0x00203a6f

.hexa:
    .word 0x00000000
    .word 0x00000000

binario:
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000
    .word 0x00000000

.outdec:
    .word 0x63656420
    .word 0x6c616d69
    .word 0x203ae920

.outstr:
    .word 0x72747320
    .word 0x3a676e69
    .word 0x00000020

.menu:
    .word 0x766e6f43
    .word 0x6f737265
    .word 0x0a3a7365
    .word 0x65442e35
    .word 0x61702063
    .word 0x42206172
    .word 0x360a6e69
    .word 0x6365442e
    .word 0x72617020
    .word 0x65482061
    .word 0x2e370a78
    .word 0x206e6942
    .word 0x61726170
    .word 0x63654420
    .word 0x422e380a
    .word 0x70206e69
    .word 0x20617261
    .word 0x0a786548
    .word 0x65482e39
    .word 0x61702078
    .word 0x44206172
    .word 0x310a6365
    .word 0x65482e30
    .word 0x61702078
    .word 0x42206172
    .word 0x00006e69

.opcao:
    .word 0x6e696d0a
    .word 0x6f206168
    .word 0x6f616370
    .word 0x0000203a

.saida:
    .word 0x61732041
    .word 0x20616469
    .word 0x00006d65

.section .text
menu:
    addi t0, zero, 3
    # no menu para economizar espaco
    # eu vejo onde comeco na memoria
    # e vou printando so de salto em
    # salto, sem repetir palavras
    # t5 fixo para nums e sempre mais 2
    #addi t5, zero, 1280
    addi a1, zero, 102
    lui a0, %hi(.menu)
    addi a0, a0, %lo(.menu)
    ecall
    jr ra

opcao:
    addi t0, zero, 3
    addi a1, zero, 14
    lui a0, %hi(.opcao)
    addi a0, a0, %lo(.opcao)
    ecall

    # pega o digito
    addi t0, zero, 4
    ecall
    add t4, zero, a0
    jr ra

saida:
    addi t0, zero, 3
    addi a0, zero, 0
    lui a0, %hi(.saida)
	addi a0, a0, %lo(.saida)
    addi a1, zero, 10
    ecall
    jr ra

outdec:
    # Printa saida 'A saida em decimal eh:'
    addi sp, sp, -4
    sw ra, 0(sp)
    call saida
    lw ra, 0(sp)
    addi sp, sp, 4

    addi a0, zero, 0
    lui a0, %hi(.outdec)
	addi a0, a0, %lo(.outdec)
    addi a1, zero, 12
    ecall

    negativooutdec:
        bge t2, zero, printa    #
            addi t0, zero, 2
            addi a0, zero, 45   # isso aqui printa o sinal negativo
            ecall

            sub t2, zero, t2    # inverte o numero

        printa:                 # aqui printa
            addi t0, zero, 1
            addi a0, t2, 0
            ecall
        
        addi s3, zero, 4
        bne t4, s3, fimoutdec
            addi t4, zero, 0
            addi t2, t1, 0

            # printa resto
            addi t0, zero, 3
            addi a0, zero, 0
            lui a0, %hi(.resto)
            addi a0, a0, %lo(.resto)
            addi a1, zero, 11
            ecall
            j negativooutdec

        fimoutdec:

    j final

insira:
    addi t0, zero, 3
    lui a0, %hi(.insira)
	addi a0, a0, %lo(.insira)
    addi a1, zero, 10
    ecall
    ret

dec: # retorna decimal em a0
    addi sp, sp, -4
    sw ra, 0(sp)

    call insira

    lw ra, 0(sp)
    addi sp, sp, 4

    addi t0, zero, 4
    ecall
    ret

str: # retorna string em a0
    addi t0, zero, 6
    addi a1, zero, 32
    ecall
    ret

strlen: # recebe string em a0, conserva a0 e retorna tam em t2
    addi s1, a0, 0
    addi s2, zero, 32
    addi t2, zero, 0

    loopstrlen:
        lbu t1, 0(s1)
        beq t1, s2, fimstrlen
        beq t1, zero, fimstrlen
        addi s1, s1, 1
        addi t2, t2, 1
        j loopstrlen
    
    fimstrlen:
        addi t2, t2, -1
        ret

strinvertida:
    add s1, a0, a1 # joga string pro final em s1
    addi s1, s1, -1
    addi t0, zero, 2
    loopinverte: # vai printando cada char
        lbu a0, 0(s1)
        ecall

        addi s1, s1, -1
        addi a1, a1, -1
        bne a1, zero, loopinverte

    fiminvertestr:

        addi a0, zero, 10
        ecall

    j final

### opcoes
# MULTIPLICACAO
# recebe t5 e t6 (decimais)
# multiplica t5 e t6 e retorna em t2 
mult:
    # Vou deslocando o multiplicador para a direita ate ele ser zero
    # isso garante que o loop, ai uso xor para ver se e 0 ou 1
    # e o multiplicando para esquerda para somar
    # se for 1 eu somo
    # t5 e o multiplicando e t5 o multiplicador
    # o primeiro digito eh guardado no s0
    addi t2, zero, 0
    loopmult:
        # verifica se o s0 eh um
        addi s0, t5, 0
        slli s0, s0, 31
        srli s0, s0, 31
        beq s0, zero, multdesloc; # if s0 == zero then multdesloc
            add t2, t2, t6
        
        multdesloc:  # faz os deslocamentos da multiplicacao
            srli t5, t5, 1
            slli t6, t6, 1
            bne t5, zero, loopmult # if t5 != zero then loopmult

    ret

div: # divide t5 por t6, traz o resultado em t2 e o resto em t1
    # aqui verifica os erros
    # erro t6 menor q t5

    addi s5, t5, 0  # conserva t5 e t6
    addi s6, t6, 0

    addi s3, zero, 1 # diferenca de tamanho
    loopigualadiv: # iguala os dois usando s3
        slli s3, s3, 1
        slli s6, s6, 1
        bge s5, s6, loopigualadiv

    srli s6, s6, 1
    srli s3, s3, 1

    addi t2, zero, 0
    loopdiv: # dividendo vai ser s6 e divisor s5 e o resultado em t2
        blt s5, s6, fimloopdiv  # se dividendo for menor divisor, pula
            add t2, t2, s3
            sub s5, s5, s6

        fimloopdiv:
            srli s6, s6, 1
            srli s3, s3, 1
            bne s3, zero, loopdiv

    addi t1, s5, 0
    ret

dectobin: # recebe um decimal em t5 e retorna em a0 e tamanho em a1
    lui a0, %hi(binario)
    addi a0, a0, %lo(binario)

    addi t6, zero, 0  # conta quantos bits tem
    loopdectobin:
        addi s0, t5, 0     #
        slli s0, s0, 31    # pega o primeiro bit sempre
        srli s0, s0, 31    # 
        addi s1, zero, 48

        beq s0, zero, salvabin; # se s0 == zero ele vai direto para o print
            addi s1, s1, 1      # senao, ele soma um antes de printar

        salvabin:
            sb s1, 0(a0)
            addi t6, t6, 1
        
        addi a0, a0, 1
        srli t5, t5, 1 # Tira o primeiro binario
        bne t5, zero, loopdectobin # if t5 != zero then loopmult
    
    printadectobin:    # printa o binario pegando
        sub a0, a0, t6
        addi a1, t6, 0

    ret

bintodec: # recebe palavra em a0 e retorna dec em t2
    addi sp, sp, -4
    sw ra, 0(sp)
    call strlen
    lw ra, 0(sp)
    addi sp, sp, 4

    addi s1, t2, 0   # tamanho da string
    addi t2, zero, 0 # reseta t2
    add a0, a0, s1   # joga a0 pro final

    addi t5, zero, 1
    loopbintodec:
        lbu t1, 0(a0)
        addi t1, t1, -48
        beq zero, t1, bintodecinc; # if t0 == t1 then target
            add t2, t2, t5

        bintodecinc:
            slli t5, t5, 1

            addi a0, a0, -1

            beq s1, zero, fimbintodec
            addi s1, s1, -1
            j loopbintodec

    fimbintodec: # verifica negativo do bin to dec

        ret
    
dectohex:
    lui s4, %hi(hexa)
    addi s4, s4, %lo(hexa)

    blt zero, t5, loopdectohex
        sub t5, zero, t5

    loopdectohex: # Enquanto o res da divisao for maior que 16, fica no loop 
        addi t6, zero, 16 # t6 eh sempre 16

        addi sp, sp, -4
        sw ra, 0(sp)
        call div   # pega os tamanhos de t5 e t6
        lw ra, 0(sp)
        addi sp, sp, 4

        # converte o resultado para o seu respectivo ASCII
        # se menor que 9 ele so soma 10, senao, soma 55 
        addi t6, zero, 9
        blt t6, t1, hexchar
            addi t1, t1, 48
            j salvahex
        hexchar:
            addi t1, t1, 55
        salvahex:
        # salva na variavel
        sb t1, 0(s4)
        addi s4, s4, 1
        addi a2, a2, 1
        addi t6, zero, 16 # t6 eh sempre 16
        blt t2, t6, fimdectohex # se o res da div for menor que 16, vai po fim
                                # caso nao, salva resto na pilha e res como t5
            addi t5, t2, 0
            j loopdectohex

    fimdectohex: # salva o ultimo resto e resultado
        addi t6, zero, 9
        blt t6, t2, fimhexchar
            addi t2, t2, 48
            j fimsalvahex
        fimhexchar:
            addi t2, t2, 55
        fimsalvahex:
        sb t2, 0(s4)
        addi s4, s4, 1
        addi a2, a2, 1
        addi a1, a2, 0
        
        lui a0, %hi(hexa)
        addi a0, a0, %lo(hexa)
        
    ret

hextodec:
    addi sp, sp, -4
    sw ra, 0(sp)
    call strlen
    lw ra, 0(sp)
    addi sp, sp, 4

    addi s1, t2, 0   # tamanho da string
    addi t2, zero, 0 # reseta t2
    add a0, a0, s1   # joga a0 pro final

    addi s8, zero, 1
    addi s3, zero, 0
    loophextodec:
        lbu t6, 0(a0)
        # converte o resultado para o seu respectivo ASCII
        # se menor que 9 ele so soma 10, senao, soma 55 
        addi t1, zero, 57
        blt t1, t6, hextodecchar
            addi t6, t6, -48
            j salvahextodec
        hextodecchar:
            addi t6, t6, -55

        salvahextodec:
            addi t5, s8, 0

            addi sp, sp, -4
            sw ra, 0(sp)
            call mult
            lw ra, 0(sp)
            addi sp, sp, 4

            add s3, s3, t2
            addi a0, a0, -1

            beq s1, zero, fimhextodec
            slli s8, s8, 4
            addi t5, s8, 0
            addi s1, s1, -1
            j loophextodec

    fimhextodec:
        addi t2, s3, 0
        ret

bintohex: # recebe binario em a0 e retorna hex em a0
    addi sp, sp, -4
    sw ra, 0(sp)
    call bintodec   # pega os tamanhos de t5 e t6
    lw ra, 0(sp)
    addi sp, sp, 4

    add t5, zero, t2

    addi sp, sp, -4
    sw ra, 0(sp)
    call dectohex   # pega os tamanhos de t5 e t6
    lw ra, 0(sp)
    addi sp, sp, 4

    ret

hextobin: # recebe hex em a0 e retorna bin em a0
    addi sp, sp, -4
    sw ra, 0(sp)
    call hextodec   # pega os tamanhos de t5 e t6
    lw ra, 0(sp)
    addi sp, sp, 4

    add t5, zero, t2

    addi sp, sp, -4
    sw ra, 0(sp)
    call dectobin   # pega os tamanhos de t5 e t6
    lw ra, 0(sp)
    addi sp, sp, 4

    ret

### final

escolhas:
    # vai para decimais
    addi t3, zero, 7
    blt t4, t3, decimais

    # vai para binarias
    addi t3, zero, 9
    blt t4, t3, binarias

    # vai para hexadecimais
    addi t3, zero, 11
    blt t4, t3, hexadecimais

    j final

    decimais:
        call dec
        addi t5, a0, 0

        addi t3, zero, 5
        addi ra, ra, 16
        beq t4, t3, dectobin
        beq t4, t3, strinvertida

        addi t3, zero, 6
        addi ra, ra, 16
        beq t4, t3, dectohex
        beq t4, t3, strinvertida
        
        j final

    binarias:
        call str

        addi t3, zero, 7
        addi ra, ra, 12
        beq t4, t3, bintodec
        beq t4, t3, outdec

        addi t3, zero, 8
        addi ra, ra, 16
        beq t4, t3, bintohex
        beq t4, t3, strinvertida

        j final

    hexadecimais:
        call str

        addi t3, zero, 9
        addi ra, ra, 12
        beq t4, t3, hextodec
        beq t4, t3, outdec

        addi t3, zero, 10
        addi ra, ra, 16
        beq t4, t3, hextobin
        beq t4, t3, strinvertida

        j final
main:
    # Usando t5 e t6 como os registradores para operacoes 
    # t4 para opcao t3 para switch case
    # t2 para resultado
    # O menu para as 4 informacoes, saida e 
    # nao achado tmb
    # vai de 1 a 5, sendo 5 a saida e um invalido
    # se o numero nao for de 1 a 5, eh invalido

    # salva e recupera servem para
    # salvar os valores de a0, a1 e t0
    # muito util para recuperar rapidamente
    
    call menu
    call opcao
    call escolhas
    final:
