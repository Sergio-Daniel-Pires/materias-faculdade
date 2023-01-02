dias = int(input("Digite a quantidade de dias: "))
meses = int(input("Digite a quantidade de meses: "))
anos = int(input("Digite a quantidade de anos: "))

idade_dias = dias + (30*meses) + (365*anos)

print(f"A idade em dias é: {idade_dias}")