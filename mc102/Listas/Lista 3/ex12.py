racao = int(input("Digite a quantidade do saco de ração em quilos: "))
gato1 = int(input("Digite a quantidade de ração do gato 1 em gramas: "))
gato2 = int(input("Digite a quantidade de ração do gato 2 em gramas: "))
sobra = (racao*1000) - ((gato1+gato2)*5)
print(f"Sobra {sobra} gramas de ração no saco após 5 dias")