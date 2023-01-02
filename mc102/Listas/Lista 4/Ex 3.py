'''
3. Escreva um programa que recebe uma lista e um inteiro m e realiza um deslocamento à esquerda de 
tamanho m. Por exemplo a seguinte figura apresenta uma lista de tamanho 5, no qual se realiza
 um deslocamento de tamanho 2.
'''

lista = input().split()
inteiro = int(input())
nova_lista = []
for index in range(len(lista)-inteiro):
    nova_lista.append(lista[index+inteiro])
for index in range(inteiro):
    nova_lista.append(lista[index])

print(nova_lista)

### Grupo : Daniel Hosomi, Caio, Arthur Guerra, Gustavo Eugenio, Lannis, Lucas, Luan, Octavio, Rafael, Felipe Scherer, Ygor, Sergio