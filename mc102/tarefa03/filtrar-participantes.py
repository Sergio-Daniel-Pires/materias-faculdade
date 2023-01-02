N, Q, V, M, a, b = input().split()
iniciais = [a,b]
atual = 1
vencedores = []
## print(atual, N) outro teste, favor ignorar
while int(N) >= atual:
    nome, q, v = input().split()
    inicial = nome[0]
    lance_atual = 1
    total = []
    Media = 0
    if int(v) >= 1:
        while int(v) >= lance_atual:
            fracao = float(input())
            total.append(fracao)
            lance_atual += 1
            Media = sum(total) / int(v)
    if int(q) >= int(Q) or (int(v) >= int(V) and Media >= float(M)) or inicial in iniciais:
        vencedores.append(str(nome))
    atual += 1
#Mais testes
#print (" ".join(vencedores))
#print (q, Q, Media, M, v, V, inicial, iniciais)


# FUNCIONANDO
for i in vencedores:
    print(i)
