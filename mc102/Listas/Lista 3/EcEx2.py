x = int(input("Dê o valor de X -- que deve ser inteiro:"))

divisivel_3 = False
divisivel_5 = False

if x%3 == 0:
    divisivel_3 = True
if x%5 == 0:
    divisivel_5 = True

if divisivel_3 and divisivel_5:
    print("X é divisível por 3 e por 5")
else: 
    print("X não é simultaneamente divisível por 3 e por 5")