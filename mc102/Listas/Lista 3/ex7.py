import math
x = float(input("Digite um número: "))
raiz = math.sqrt(x)
novo = str(raiz).split(".")
print(novo[0][-3], novo[1][2])