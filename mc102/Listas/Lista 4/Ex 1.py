#Grupo: Sergio, Daniel Hosomi, Caio, Arthur Guerra, Gustavo Eugenio, Lannis, Lucas, Luan, Octavio, Rafael, Felipe Scherer, Ygor
lista_numeros = []
lista_numeros_organizada = []
lista_numeros = list(map(float, input("Digite uma lista: ").split()))
for i in lista_numeros:
    lista_numeros_organizada.append(i)
lista_numeros_organizada.sort()
menor_numero = lista_numeros_organizada[0]
m = 0

for i in lista_numeros:
    if menor_numero == i:
        print(f"Um menor elemento vale {menor_numero} e está na posição {m}")
    m += 1