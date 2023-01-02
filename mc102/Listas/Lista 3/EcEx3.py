num = input("Digite um número de quatro dígitos:")

dois_primeiros = int(num[:2])
dois_ultimos = int(num[-2:])

igual_3025 = False

if str((dois_primeiros+dois_ultimos)**2) == num:
    igual_3025 = True

if igual_3025:
    print("O número tem a mesma propriedade do 3025")
else:
    print("O número não tem a mesma propriedade do 3025")