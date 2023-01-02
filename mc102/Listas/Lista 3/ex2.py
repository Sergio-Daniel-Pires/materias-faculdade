#2.
x = float(input("Digite o valor de x:"))

if (x+(x/2)+(x**x)) >= 0:
    x = (x+(x/2)+(x**x))**(1/2)
    raiz_existe = True
else:
    raiz_existe = False

if raiz_existe:
    print(f"f(x) é igual a {x}")
else:
    print("Não há imagem real para o valor determinado de x")