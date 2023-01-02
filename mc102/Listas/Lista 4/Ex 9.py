'''
9. Suponha que um texto é formado por letras, vírgulas, pontos e espaços em branco. 
Escreva um programa que leia um texto e imprima uma lista das palavras (sem repetição) 
que têm comprimento menor ou igual a 5.
'''

texto = input().split()
lista_palavras = []

for palavra in texto:
    if palavra[-1] == "," or palavra[-1] == ".":
        if len(palavra) <= 6:
            lista_palavras.append(palavra)
    else:
        if len(palavra) <= 5:
            lista_palavras.append(palavra)

lista_palavras = set(lista_palavras)

print(lista_palavras)

### Grupo : Daniel Hosomi, Caio, Arthur Guerra, Gustavo Eugenio, Lannis, Lucas, Luan, Octavio, Rafael, Felipe Scherer, Ygor, Sergio