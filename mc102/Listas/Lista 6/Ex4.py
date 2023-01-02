n = int(input())
matrizf = []
for num in range(n):
    linha = []
    for x in range(1, (n*2)):
        if x == n or (x >= n-num and x <= n+num):
            linha.append('*')
        else:
            linha.append('.')
    matrizf.append(linha+linha)

for linha in matrizf:
    print("".join(linha))
