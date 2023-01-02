seg = int(input("Digite a duração do evento em segundos: "))
horas = seg//3600
min = (seg%3600)//60
segundos = (seg%3600)%60
print(f"Horas: {horas}")
print(f"Minutos: {min}")
print(f"Segundos: {segundos}")