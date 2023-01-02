import math

def listagem(n):
    """
    Essa função só cria uma lista com valores entregues
    e computa um ultimo elemento que é o tamanho de cada uma
    """
    listaF = []
    tam = []
    for i in range(n):
        listaI = []
        listaI = list(map(float, input().split()))
        tam.append(len(listaI))
        listaF.append(listaI)
    listaF.append(tam)
    return listaF

def FI(lista, n, tam):
    """
    FI de "Frequencias iguais" e tem dois for's para
    que a lista consiga "se mover pela coluna" (como se
    fosse uma matriz) ao inves de percorrer a linha. 
    """
    freq = []
    for i in range(len(lista[0])):
        freqa = 0
        for t in range(n):
            freqa += lista[t][i]
        freqa = freqa/n
        freq.append(str(round(freqa, 2)))
    return freq

def normalizacao(lista, mmin):
    """
    Como esse programa só trabalha com numero iguais
    de frequencias, essa função normaliza tudo para
    a frequencia de menor valor.
    Obs: O if da fracao serviu para passar no teste extremo
    nao entendi mt bem oq era pra fazer caso fosse 0, ent deixei
    assim msm
    """
    listaf = []
    for i in range(len(lista)):
        freqn = []
        atual = 0
        if mmin != 0:
            fracao = len(lista[i])/mmin
        else:
            fracao = 1
        listatual = lista[i]
        while atual < len(lista[i]):
            x = (listatual[(math.ceil(atual)):(math.ceil(atual+fracao))])
            if len(x) != 0:
                freqn.append(sum(x)/len(x)) 
            atual += fracao
        listaf.append(freqn)
    return listaf

def main():
    """
    Retira a lista de tamanhos da lista principal
    e compara para ver se vai precisar normalizar ou não.
    ai dps ele só chama as outras funções para interpolar
    e printa o resultado
    """
    n = int(input())
    listaF = listagem(n)
    tam = listaF[len(listaF)-1]
    listaF.pop()
    if tam[0] == sum(tam)/(len(tam)):
        listaF = FI(listaF, n, tam)
    else:
        tam.sort()
        mmin = tam[0]
        listaN = normalizacao(listaF, mmin)
        listaF = FI(listaN, n, tam)
    print (" ".join(listaF))

main()