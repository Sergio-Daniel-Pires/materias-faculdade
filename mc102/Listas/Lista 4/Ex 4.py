print("Digite a lista:", end=' ')
numeros=list(map(int,input().split()))
LCS = []

for i in numeros:
    ok = 0
    for j in LCS:
        if j>i:
            ok=1
            break
    if ok==False:
        LCS.append(i)

print("Uma maior subsequencia crescente é ",end='')
for i in LCS:
    print(i,end=' ')
print(f"e tem {len(LCS)} elementos")


### Grupo : Daniel Hosomi, Caio, Arthur Guerra, Gustavo Eugenio, Lannis, Lucas, Luan, Octavio, Rafael, Felipe Scherer, Ygor, Sergio