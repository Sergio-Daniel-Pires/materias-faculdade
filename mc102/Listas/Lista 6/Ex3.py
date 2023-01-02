n = int(input())
matrizf = []
alg = 1
for num in range(1, n+1):
    linha = []
    for elem in range(1, num+1):
        linha.append(str(alg))
        alg += 1
    matrizf.append(linha)

for linha in matrizf:
    print(" ".join(linha))
