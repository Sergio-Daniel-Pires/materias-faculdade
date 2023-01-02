def salvar_pares(ents):
    """
    A função pega cada linha de um arquivo e
    salva em sua respectiva linha do dicionario.
    """
    dicionario = {}
    for n in range(ents):
        x,y = input().split()
        x = int(x)
        y = int(y)
        if x not in dicionario:
            dicionario[x] = {y}
        else:
            dicionario[x].add(y)
        if y not in dicionario:
            dicionario[y] = {x}
        else:
            dicionario[y].add(x)
    return dicionario

def achar_cadeias(dicionario):
    """
    Pega o dicionario de cada termo dentro de outro
    dicionario e verifica sua intersecção, que por sua
    vez passa por outra verificação para ver se ela esta
    contida no dicionario.
    """
    cadeia = set()
    for num in dicionario:
        inter = {x: dicionario[x] & dicionario[num] for x in dicionario[num]}
        for x in inter:
            for y in inter[x]:
                if y in inter:
                    trio = tuple(sorted({num, x, y}))
                    if trio not in cadeia: cadeia.add(trio)
                    
    for i in sorted(cadeia):
        print(" ".join(map(str, i)))


def main():
    """
    Recebe o numero de entradas e passa para
    a função 'salvar pares', depois passa
    um dicionario para a funcao achar cadeias
    """
    ents = int(input())
    dicionario = salvar_pares(ents)
    achar_cadeias(dicionario)

main()