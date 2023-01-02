lances = 0
lance = 0
maior_lançador = "Maior lançador"
while True:    
    op = input()
    if op == "I":
        X, Y = input().split()
        lance = Y
        print("Bem-vindo ao Leilão de Algoritmópolis! Produto " + X + " com lance mínimo R$ " + Y)
    elif op == "L":
        nome, novo_lance = input().split()
        if float(novo_lance) > float(lance)  or (lances == 0 and novo_lance == lance):
            lance = novo_lance
            maior_lançador = nome
            lances += 1
            print (nome + " deu um lance de R$ " + novo_lance)
        else:
            print ("Lance inválido de " + nome)
    elif op == "S":
        if lances >= 1:
            print ("Status do Leilão do Produto " + X + "\n" + str(lances) + " lances até agora" + "\n" + maior_lançador + " deu o melhor lance, de valor R$ " + str(lance))
        else:
            print ("Status do Leilão do Produto " + X + "\n" + "Não houve lances")
    elif op ==  "F":
        print ("Leilão finalizado com " + str(lances) + " lances")
        if lances > 0:
            print (maior_lançador + " venceu com o lance de valor R$ " + str(lance))
        else:
            print ("Não houve vencedor")
        break