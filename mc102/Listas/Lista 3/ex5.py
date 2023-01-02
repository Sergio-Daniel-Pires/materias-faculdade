a = float(input("Qual o valor do lado a do triângulo?"))
b = float(input("Qual o valor do lado b do triângulo?"))
c = float(input("Qual o valor do lado c do triângulo?")) 

s = (a+b+c)/2
area = (s*(s-a)*(s-b)*(s-c))**(1/2)

print(f"A área do triângulo é igual a {area:.2f} (medida)")