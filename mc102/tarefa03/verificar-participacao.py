## Q = Quantidade de participações
Q = 3

## V = Vezes que o vencedor deu o maior lance
V = 2

## "a" e "b" = inicias que podem participar
a = "D"
b = "R"
novas_iniciais = [a,b]

## M = Média minima
M = 120.45

nome = input("Qual o seu nome: ")
##print("a inicial do seu nome é " + nome[0]) Isso foi um teste, favor ignorar
inicial = nome[0]
passados= int(input("Quantos leilões já participou antes: "))
vencidos = int(input("Quantos lances você já venceu: "))
if vencidos >= 2:
    lance_atual = 1
    total = []
    ## Fiquei triste que fiz um código para se o evento tivesse +2 entradas
    ## pra descobrir que era no máximo duas :(
    #while vencidos >= lance_atual:
    #    fracao = float(input("Lance vencedor " + str(lance_atual) + ":"))
    #    total.append(fracao)
    #    lance_atual += 1
    while 2 >= lance_atual:
        fracao = float(input("Lance vencedor " + str(lance_atual) + ":"))
        total.append(fracao)
        lance_atual += 1
    Media = sum(total) / 2
if passados >= 3 or (vencidos >= 2 and Media >= M) or inicial in novas_iniciais:
    print("Parabéns! Você pode se inscrever.")
else:
    print("Infelizmente, você não poderá participar nesse ano.")