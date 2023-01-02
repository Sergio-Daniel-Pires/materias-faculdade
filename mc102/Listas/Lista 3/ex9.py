cont=0
horas = int(input("Digite a quantidade de horas em que a charrete foi usada: "))
if horas < 3:
    custo = horas*5
elif horas >= 3:
    while horas >= 3:
        horas = horas - 3
        cont +=1
    custo = (cont)*10 + horas*5
print(f"O cliente deve pagar {custo} reais")