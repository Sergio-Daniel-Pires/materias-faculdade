### 2)a)
def a():
    soma = []
    for n in range(0, 50):
        dividendo = (n*2)+1
        divisor = n+1
        soma.append(dividendo/divisor)
    print(sum(soma))
### 2)b)
def b():
    soma = []
    for n in range(0, 49):
        dividendo = (2**(n+1))
        divisor = 50-n
        soma.append(dividendo/divisor)
    print(sum(soma))
### 2)c)
def c():
    soma = []
    for n in range(1, 11):
        dividendo = n
        divisor = n**2
        if (n%2) == 0:
            soma.append(-(dividendo/divisor))
        else:
            soma.append(dividendo/divisor)
    print(sum(soma))
