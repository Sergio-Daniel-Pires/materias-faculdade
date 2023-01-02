escala = input("Dê a escala:")
temp = float(input("Digite a temperatura:"))
if escala == "F":
    Celsius = False
elif escala == "C":
    Celsius = True
if Celsius:
    temp = 5/9 * (temp - 32)
else:
    temp = 32 + (9/5 * temp)
print(f"A temperatura é {temp}")