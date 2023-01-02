def ordena(lista, maior):
    lista.sort(reverse = maior)
    """
    Ordena 'lista' do maior para o menor, caso 'maior' seja True; caso
    contrário, ordena do menor para o maior. Essa função modifica a lista
    passada por parâmetro.

    Parâmetros: lista de números ou strings e um booleano.
    Retorna: nada.
    """


def moda(lista):
    ### ram é o numero maximos de repetições
    ram = 0
    ### maxx, é o maximo
    maxx = len(lista)
    for i in lista:
        letra = i
        ### rat é o numero atual de repetições
        rat = 0
        atual = 0
        while atual < maxx:
            if letra == lista[atual]:
                atual += 1
                rat += 1
            else:
                atual += 1
        if rat > ram:
            ram = rat
            moda = letra
    return moda

    """
    Encontra a moda de 'lista', isto é, o valor que mais se repete; em caso de
    empate, retorne o que aparece primeiro.
    Parâmetros: lista de strings.
    Retorna: a moda de 'lista'.
    """


def mediana(valores):
    valores.sort()
    tamanho = len(valores)/2
    if tamanho == int(tamanho):
        mediana = valores[(int(tamanho))]
    else:
        mediana = valores[(int(tamanho)+0.5)]
    return mediana
    """
    Encontra a mediana de 'valores', isto é, o valor que ocupa a posição
    central da lista ordenada. Quando a lista tem tamanho par,
    definimos a mediana como o valor da primeira posição na segunda
    metada da lista ordenada.

    Parâmetros: lista de floats.
    Retorna: a mediana de 'valores'.
    """


def media(valores):
    ### div é oq vai dividir a soma
    div = len(valores)
    total = sum(valores)
    return (total/div)
    """
    Encontra a média de 'valores'.

    Parâmetros: lista de floats.
    Retorna: a média de 'valores'.
    """


def media_ponderada(valores, pesos):
    div = sum(pesos)
    atual = 0
    nota = 0
    ### cima são os numeros que ficam encima na divisão
    cima = []
    while atual < len(valores):
            nota =+ (valores[atual]*pesos[atual])
            cima.append(nota)
            atual += 1
    total = sum(cima)
    return (total/div)
    """
    Encontra a média ponderada de 'valores'.

    Parâmetros: listas de floats.
    Retorna: a média ponderada de 'valores'.
    """


def filtrar_entre(valores, menor, maior):
    lista = []
    for i in valores:
        if menor <= i < maior:
            lista.append(i)
    return lista
    """
    Cria uma lista com os números de 'valores' que estejam no intervalo
    ['menor', 'maior') (o primeiro intervalo é fechado e o segundo é aberto).

    Parâmetros: lista de floats e os limites.
    Retorna: a lista filtrada.
    """


def filtrar_caracteristica(lista, caracteristica, alvo):
    atual = 0
    paises = []
    for i in caracteristica:
        if i == alvo:
            paises.append(lista[atual])
            atual += 1
        else:
            atual += 1
    return paises
    """
    Cria uma lista com os elementos de 'lista' cuja posição em 'caracteristica'
    seja igual a 'alvo'. Por exemplo, com a entrada abaixo, retornaríamos
    ['Alemanha', 'Portugal']:
    lista = ['Brasil', 'Alemanha', 'Angola', 'Portugal']
    caracteristica = ['América do Sul', 'Europa', 'África', 'Europa']
    alvo = 'Europa'

    Parâmetros: listas de números ou strings e um valor alvo.
    Retorna: a lista com a característica filtrada.
    """

def comparar(mins, valores, maxs):
    vezes = 0
    for i in valores:
        if mins <= i < maxs:
            vezes += 1
    return vezes
    """
    Pro programa não ficar com muitas linhas repetidas
    pq eu precisava criar um laço com while/for eu criei
    outra função que faz o trabalho de comparar todos os
    valores de uma lista (valores) com os intervalos (mins e maxs)
    e fiquei repetindo ela
    """

def histograma(valores, intervalos):
    histograma = []
    atual = 1
    maxx = len(intervalos)
    while atual < maxx:
        mins = intervalos[atual-1]
        maxs = intervalos[atual]
        histograma.append(comparar(mins, valores, maxs))
        atual += 1
    return histograma

    """
    Cria uma lista com as frequências do histograma de 'valores', divididas nas
    classes conforme a lista 'intervalos'. Por exemplo, se temos [10, 20, 30]
    como intervalos, devemos obter as frequências dos intervalos [10, 20) e [20,
    30).

    Parâmetros: listas de números.
    Retorna: lista de frequência do histograma.
    """


def maiores_k(valores, k):
    valores.sort(reverse = True)
    return valores[0:k]
    """
    Cria uma lista com os 'k' maiores números de 'valores'.

    Parâmetros: lista de inteiros e um número inteiro.
    Retorna: lista com os 'k' maiores números.
    """


def menores_k(valores, k):
    valores.sort()
    return valores[0:k]
    """
    Cria uma lista com os 'k' menores números de 'valores'.

    Parâmetros: lista de inteiros e um número inteiro.
    Retorna: lista com os 'k'menores números.
    """


def remove_duplicatas(lista):
    nova_lista = []
    for i in lista:
        if i not in nova_lista:
            nova_lista.append(i)
    return nova_lista
    """
    Cria uma lista removendo todos os elementos duplicados de 'lista', mantendo
    a ordem relativa original. Use somente listas, for/while e variáveis
    simples para implementar essa função.

    Parâmetros: listas de strings.
    Retorna: 'lista' sem duplicatas.
    """
