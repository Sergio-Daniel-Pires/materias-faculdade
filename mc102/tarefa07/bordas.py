import sys

def ler_aquivo_palavras(nome_arquivo):
    """
    Lê um arquivo e devolve a lista de listas,
    uma por linha com cada valor individualmente
    """
    with open(nome_arquivo) as arquivo:
        palavras = []
        for linha in arquivo:
            palavra = linha.strip()
            palavras.append(palavra)
    return palavras

def ler_linhas(foto):
    """
    Essa função verifica cada pixel da imagem para
    verificar se ele é '1' ou '0'. Se for 1
    passa por um filtro.
    """
    palavras = ler_aquivo_palavras(foto)
    tipo = palavras[0]
    a, b = map(int, palavras[1].split())
    listafor = []
    for i in range(2, len(palavras)):
        linha = list(map(int, palavras[i].split()))
        listafor.append(linha)
    listaf = []
    listaf.append(f"{tipo}\n{a} {b}")
    for l in range(b):
        listaatual = []
        for c in range(a):
            if  listafor[l][c] == 0:
                listaatual.append('0')
            elif listafor[l][c] == 1:
                listaatual.append(borda(listafor, a, b, l, c))
        listaf.append(" ".join(listaatual))
    return listaf

def borda(listafor, a, b, l, c):
    """
    Essa função verifica se existe um pixel 0
    nas bordas do pixel que veio da função ler_linhas()
    """
    listaf = []
    for li in range(l-1, l+2):
        for ci in range(c-1, c+2):
            if 0 <= ci <= a and 0 <= li <= b:
                listaf.append(listafor[li][ci])
    for i in listaf:
        if i == 0:
            valor = '1'
            return valor
        else:
            valor = '0'

    return valor
            

def main():
    """
    Requisita 2 argumentos e devolve uma imagem somente
    com as bordas da imagem e nome que veio do segundo
    argumento
    """
    foto = sys.argv[1]
    arquivo = sys.argv[2]
    lista = ler_linhas(foto)
    with open(arquivo, "w") as arquivo:
            print("\n".join(lista), file=arquivo)


main()



