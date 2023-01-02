def maximo(lista, max):
    if len(lista) == 0:
        return max
    else:
        if lista[0] > max: max = lista[0]
        del lista[0]
        return maximo(lista, max)

def main():
    lista = list(map(int, input().split()))
    print(maximo(lista, 0))
main()