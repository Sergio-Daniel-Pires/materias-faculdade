.section .data
.insira:
    .word 0x72746e45
    .word 0x3a616461
    .word 0x00000020

.resto:
    .word 0x206d6f43
    .word 0x74736572
    .word 0x00203a6f

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
    .word 0x61732041
    .word 0x20616469
    .word 0x64206d65
    .word 0x6d696365
    .word 0x65206c61
    .word 0x00203a68

.menu:
    .word 0x6f637345
    .word 0x2061686c
    .word 0x20616d75
    .word 0x7265706f
    .word 0x6f616361
    .word 0x2e310a3a
    .word 0x63696441
    .word 0x320a6f61
    .word 0x6275532e
    .word 0x63617274
    .word 0x330a6f61
    .word 0x6c754d2e
    .word 0x6c706974
    .word 0x63616369
    .word 0x340a6f61
    .word 0x7669442e
    .word 0x6f617369

.opcao:
    .word 0x6e696d0a
    .word 0x6f206168
    .word 0x6f616370
    .word 0x0000203a

.errodivzero:
    .word 0x6964204f
    .word 0x6f736976
    .word 0x616e2072
    .word 0x6f70206f
    .word 0x73206564
    .word 0x30207265
    .word 0x00000a21

.teveoverflow:
    .word 0x76756f48
    .word 0x766f2065
    .word 0x6c667265
    .word 0x2021776f
    .word 0x746c6f56
    .word 0x6f646e61
    .word 0x72617020
    .word 0x206f2061
    .word 0x756e656d
    .word 0x0000000a

.section .text
menu:
    addi t0, zero, 3
    # no menu para economizar espaco
    # eu vejo onde comeco na memoria
    # e vou printando so de salto em
    # salto, sem repetir palavras
    # t5 fixo para nums e sempre mais 2
    #addi t5, zero, 1280
    addi a1, zero, 69
    lui a0, %hi(.menu)
    addi a0, a0, %lo(.menu)
    ecall

    jr ra

opcao:
    addi a1, zero, 14
    lui a0, %hi(.opcao)
    addi a0, a0, %lo(.opcao)
    ecall

    # pega o digito
    addi t0, zero, 4
    ecall
    add t4, zero, a0
    jr ra

teveoverflow:
    addi t0, zero, 3
    lui a0, %hi(.teveoverflow)
	addi a0, a0, %lo(.teveoverflow)
    addi a1, zero, 37
    ecall
    j main

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

outdec:
    # Printa saida 'A saida em decimal e:'
    addi t0, zero, 3
    addi a0, zero, 0
    lui a0, %hi(.outdec)
	addi a0, a0, %lo(.outdec)
    addi a1, zero, 23
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

    ret

### opcoes

# SOMA
# recebe t5 e t6 (decimais)
# soma os dois e retorna em t2
soma:
    add t2, t5, t6
    # Primeiro verifica overflow se os sinais forem iguais
    # isso por que se forem diferentes, o maior com o menor da 0

    slti s0, t6, 0
    slt s1, t2, t5
    bne s0, s1, teveoverflow # Basicamente, verifica se o numero nao trocou de sinal

    ret

# SUBTRACAO
# recebe t5 e t6 (decimais)
# subtrai de t6 o t5 e retorna em t2 
sub:
    sub t2, t5, t6

    # verificacao overflow
    # Xor verifica APENAS um deles for nao positivo
    # salva tmb sinal do C
    # se xor for verdadeiro, sinal de B tem que ser
    # diferente de sinal de C
    slt s8, zero, t5        # Sinal de A 
    slt s9, zero, t6        # Sinal de B
    slt s10, zero, t2       # Sinal de C
    beq s8, s9, fimsub      # se ambos positivos ou negativos, vai pro fim
        bne s9, s10, fimsub  # se sinal de B diferente de C, vai pro fim
            j teveoverflow

    fimsub:
    ret

# MULTIPLICACAO
# recebe t5 e t6 (decimais)
# multiplica t5 e t6 e retorna em t2 
mult:
    # Vou deslocando o multiplicador para a direita ate ele ser zero
    # isso garante que o loop, vejo se se eh 0 ou 1
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

# DIVISAO
# recebe t5 e t6 (decimais)
# divide t5 por t6 e retorna em t2 

errodivzero:
    addi t0, zero, 3
    lui a0, %hi(.errodivzero)
	addi a0, a0, %lo(.errodivzero)
    addi a1, zero, 26
    ecall
    j main

div: # divide t5 por t6, traz o resultado em t2 e o resto em t1
    # aqui verifica os erros
    # erro t6 menor q t5

    # erro div por 0
    beq t6, zero, errodivzero # erro de divisao por 0

    # div por negativo
    addi s5, zero, 0
    blt zero, t5, verfnegativo
        sub t5, zero, t5
        addi s5, zero, 1

    verfnegativo:
    addi s6, zero, 0
    blt zero, t6, fimnegativo
        sub t6, zero, t6
        addi s6, zero, 1

    fimnegativo:
    addi s3, zero, 1 # diferenca de tamanho
    loopigualadiv: # iguala os dois usando s3
        slli s3, s3, 1
        slli t6, t6, 1
        bge t5, t6, loopigualadiv

    srli t6, t6, 1
    srli s3, s3, 1

    addi t2, zero, 0
    loopdiv: # dividendo vai ser t6 e divisor t5 e o resultado em t2
        blt t5, t6, fimloopdiv  # se dividendo for menor divisor, pula
            add t2, t2, s3
            sub t5, t5, t6

        fimloopdiv:
            srli t6, t6, 1
            srli s3, s3, 1
            bne s3, zero, loopdiv

    addi t1, t5, 0
    xor s7, s5, s6       # se apenas um dos dois era negativo
    beq s7, zero, fimdiv # resultado vai virar negativo
        sub t2, zero, t2
    fimdiv:
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

### final

escolhas:
    # Cada funcao usa um BEQ
    # somo RA pra evitar loop

    # vai para aritmetica
    addi t3, zero, 5
    blt t4, t3, aritmetica

    j final

    aritmetica:
        call dec        # pega os dois decimais
        addi t5, a0, 0  # e salva para t5 e t6
        call dec        #
        addi t6, a0, 0  #

        addi t3, zero, 1
        addi ra, ra, 16
        beq t4, t3, soma

        addi t3, zero, 2
        addi ra, ra, 12
        beq t4, t3, sub

        addi t3, zero, 3
        addi ra, ra, 12
        beq t4, t3, mult

        addi t3, zero, 4
        addi ra, ra, 12
        beq t4, t3, div

        call outdec
        j main
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
