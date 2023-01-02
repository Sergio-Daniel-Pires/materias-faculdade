m, n = input().split()
m, n = int(m), int(n)
matrizf = []
impar = 1
for l in range(m):
    linha = []
    for elemento in range(n):
        if impar == 1:
            linha.append('01')
        elif impar < 10:
            linha.append(f'0{impar}')
        else:
            linha.append(str(impar))
        impar += 2
    if ((l+2)%2) == 0: 
        matrizf.append(linha)
    else:
        linha.reverse()
        matrizf.append(linha)

for linha in matrizf:
    print(" ".join(linha))
