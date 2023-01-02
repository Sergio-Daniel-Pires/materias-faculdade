num1 = int(input("Digite o primeiro número:"))
num2 = int(input("Digite o segundo número:"))
operador = input("Digite a operação (+,-,* ou /):")
resultado = 0

if operador == '+':
    resultado = num1+num2
    print(resultado)

elif operador == '-':
    resultado = num1-num2
    print(resultado)

elif operador == '*':
    resultado = num1*num2
    print(resultado)

elif operador == '/':
    if num2 != 0:
        resultado = num1/num2
        print(resultado)
    else:
        print("Não é possível dividir por 0")