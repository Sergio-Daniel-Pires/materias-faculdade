'''
Daniel Hosomi, Rafael Pissaia, Daniel Hosomi

1. Faça um algoritmo que, para cada número inteiro de 1 até 100, imprima “tic” se esse número 
for múltiplo de 3, imprima “toc” se for múltiplo de 5 e imprima “tic-toc” se for múltiplo de 15.
'''

for numero in range(1, 101):
    condicao = True
    if numero % 15 == 0:
        print(f"{numero} - tic-toc")
        condicao = False
    if condicao != False:
        if numero % 3 == 0:
            print(f"{numero} - tic")
        if numero % 5 == 0:
            print(f"{numero} - toc")

### Grupo : Daniel Hosomi, Caio, Arthur Guerra, Gustavo Eugenio, Lannis, Lucas, Luan, Octavio, Rafael, Felipe Scherer, Ygor, Sergio