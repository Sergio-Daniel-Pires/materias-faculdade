print("Digite o conjunto 1:", end=' ')
conjunto1= list(map(int,input().split()))
print("Digite o conjunto 2:", end=' ')
conjunto2= list(map(int,input().split()))
interseccao= []
diferenca= []
uniao= []

uniao=conjunto1

for i in conjunto1:
    for j in conjunto2:
        if i==j:
            interseccao.append(j)
            break

for i in conjunto2:
    ok=0
    for j in uniao:
        if i==j:
            ok=1
            break
    if ok==False:
        uniao.append(i)



for i in conjunto1:
    ok =0
    for j in conjunto2:
        if i==j:
            ok=1
            break
    if ok==False:
        diferenca.append(i)

print("A intersecção é: ", end='')
for i in interseccao:
    print(i,end=' ')
print()
print("A união é: ", end='')
for i in uniao:
    print(i,end=' ')
print()
print("A diferença é: ", end='')
for i in diferenca:
    print(i,end=' ')
print()

### Grupo : Daniel Hosomi, Caio, Arthur Guerra, Gustavo Eugenio, Lannis, Lucas, Luan, Octavio, Rafael, Felipe Scherer, Ygor, Sergio