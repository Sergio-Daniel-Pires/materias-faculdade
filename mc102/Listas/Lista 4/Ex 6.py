'''
Faça um programa que leia uma lista de 10 caracteres que representam o gabarito de 
uma prova de múltipla escolha 
e outra lista de 10 caracteres que representam as respostas de um estudante.
O programa deve imprimir o número de acertos do estudante.
'''

lista_notas = input().split()
lista_respostas = input().split()
numero_acertos = 0
for resposta_estudante, certa in zip(lista_notas, lista_respostas):
    if resposta_estudante == certa:
        numero_acertos += 1

print(f"Números de acertos: {numero_acertos}")

### Grupo : Daniel Hosomi, Caio, Arthur Guerra, Gustavo Eugenio, Lannis, Lucas, Luan, Octavio, Rafael, Felipe Scherer, Ygor, Sergio