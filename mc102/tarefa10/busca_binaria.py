def binaria(min, max, lista, n):
        meio=(max+min)//2
        if max-min <= 2 and lista[meio] != n:
            return -1
        if lista[meio] == n:
            return meio
        if lista[meio] < n:
            return binaria(meio+1,max, lista, n)
        else:
            return binaria(min,meio, lista, n)

def main():
    lista = list(map(int, input().split()))
    n = int(input())

    print(binaria(0, len(lista)-1, lista, n))

main()