import math

N = int(input())
numeros = list(map(int,input().split()))

media= sum(numeros)/len(numeros)
resposta=0

for i in numeros:
    resposta+=(i-media)**2

resposta/=(N-1)
print(math.sqrt(resposta))

### Grupo : Daniel Hosomi, Caio, Arthur Guerra, Gustavo Eugenio, Lannis, Lucas, Luan, Octavio, Rafael, Felipe Scherer, Ygor, Sergio