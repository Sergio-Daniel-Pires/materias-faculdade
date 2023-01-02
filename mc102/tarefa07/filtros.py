import math
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

def cores(lista):
    """
    Essa função pega o arquivo bruto de uma imagem e cria uma lista
    de listas com cada uma das das 3 valores que um pixel tem, dentro
    de outra lista que representa a linha, dentro de outra lista
    que representa a matriz como um todo.
    """
    listaf = []
    tipo = lista[0]
    a, b = list(map(int, lista[1].split()))
    maxx = lista[2]
    listaf.append(tipo)
    listaf.append(a)
    listaf.append(b)
    listaf.append(maxx)
    del lista[0:3]
    for i in lista:
        lista = list(map(int, i.split()))
        cores = []
        for i in range((len(lista)//3)):
                """
                a função "a","b" fazem o calculo de quantas
                casas precisamos adicionar em cada lista
                para que cada uma tenha 3 termos:
                """
                a = i*3
                b = ((i+1)*3)
                cores.append(lista[a:b])
        listaf.append(cores)
    return listaf

def matriz(lista, fil):
    """
    Essa função lê a matriz de uma imagem e aplica um pixel preto
    nas bordas e um filtro nos outros pixeis.
    """
    tam_fil = len(fil[0])
    central = math.floor((tam_fil)/2)
    #Central são quantos elementos precisam para
    #atingir o termo central da matriz, isso ajuda na fórmula
    #que eu desenvolvi pro código
    img = []
    tipo = lista[0]
    largura = lista[1]
    altura = lista[2]
    maxrange = lista[3]
    del lista[0:4]
    for i in range(len(lista)):
        linha = []
        for c in range(0, largura):
            if i-central < 0 or c-central < 0 or i+central > altura-1 or c+central > largura-1:
                linha.append('0 0 0')
            else:
                linha.append(" ".join(filtro(fil, i, c, lista, tam_fil)))
        img.append(linha)
        #essa parte aplica um determinado filtro a todos
        #os pixels que não sejam bordas. 
        linha = []
    imgf = []
    imgf.append(tipo)
    imgf.append(f"{largura} {altura}")
    imgf.append(str(maxrange))
    for i in img:
        imgf.append(" ".join(i))
    return imgf

def filtro(filtro, i, c, lista, tam_fil):
    """
    Essa função aplica o filtro nos pixeis que precisam.
    """
    pixel = []
    central = math.floor(tam_fil/2)
    teste = []
    for a in range(0, 3):
        for b in range(0, tam_fil):
            for d in range(0, tam_fil):
                #n = 1 para facilitar compreensão
                #a formula (i-1+d) faz com que eu consiga usar o mesmo for
                #tanto para pegar uma posição da matriz filtro, tanto da lista
                #sendo que pra isso, o -1+d serve para centralizar o elemento
                #que veio da lista anterior
                teste.append(lista[(i-central+d)][(c-central+b)][a]*filtro[b][d])
        if sum(teste) > 255:
            sumteste = 255
        elif sum(teste) < 0:
            sumteste = 0
        else:
            sumteste = sum(teste)
        #isso faz com que os pixeis fora do range 255 fiquem com o valor
        #255 (branco) ou 0 (preto), para que o programa leia normalmente.
        pixel.append(str(int(sumteste)))
        teste = []
    return pixel

def criar_arquivo(img, nome):
    """
    cria um arquivo baseado numa lista, sendo que cada
    elemento da lista entra em uma linha do arquivo
    """
    with open(nome, "w") as arquivo:
        print("\n".join(img), file=arquivo)

def ler_filtro(arquivo):
    """
    essa função le a matriz do filtro, cada linha é considerado uma
    lista e cada espaço uma separação de elementos dentro dessa lista.
    """
    with open(arquivo) as arquivo:
        palavras = []
        for linha in arquivo:
            palavra = linha.strip()
            palavras.append(palavra)
    palavrasf = []
    for i in palavras:
        palavrasf.append(list(map(float, i.split(" "))))
    return palavrasf

def main():
    """
    pega os argumentos passados pelo usuario na linha de comando
    para transformar uma imagem escolhida em uma imagem com
    um filtro aplicado e cria no diretório essa nova imagem. 
    """
    filtro = sys.argv[1]
    nome_arquivo_atual = sys.argv[2]
    nome_novo_arquivo = sys.argv[3]
    ler_imagem = ler_aquivo_palavras(nome_arquivo_atual)
    t_imagem = cores(ler_imagem)
    aplica_filtro = matriz(t_imagem, ler_filtro(filtro))
    criar_arquivo(aplica_filtro, nome_novo_arquivo)

main()
