m = 2
n = 2
matriz = []
print("Insira os elementos da matriz por linha: ")

for i in range(m):         
    lista =[]
    for j in range(n):      
         lista.append(int(input()))
    matriz.append(lista)

det = (matriz[0][0]*matriz[1][1]) - (matriz[1][0]*matriz[0][1])

print(f"O determinante da matriz é: {det}")