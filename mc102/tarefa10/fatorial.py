def fatorial(n):
    if n < 1:
        return 1
    else:
        return n * fatorial(n-1)

def main():
    n = int(input())
    print(fatorial(n))

main()

"""
Obs: desculpa se o algoritmo esta muito parecido
com alguns exemplos da internet, foi por que todos
as explicações sobre recursão que eu vi (incluindo
a da unidade) são com fatorial.
"""