### Grupo : Daniel Hosomi, Caio, Arthur Guerra, Gustavo Eugenio, Lannis, Lucas, Luan, Octavio, Rafael, Felipe Scherer, Ygor, Sergio

'''
a)
A saida do programa são todos os numeros pares da Lista 1. Pois, no primeiro for ele muda apenas os parametros
da Lista 2, que é diferente da Lista 1. Portanto, como a Lista 1 continua igual, quando ele percorre ela, ele puxa
apenas os numeros pares e imprime eles.
'''


###b)
lista = list(map(int,input().split()))
pares = [i for i in lista if i%2 ==0]
print(pares)