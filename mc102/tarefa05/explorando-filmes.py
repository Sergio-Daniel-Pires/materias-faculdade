import sys

indices = []
paises = []
anos = []
classes = []
duracoes = []

with open("testes/filmes.dat") as f:
    for linha in f:
        indice, pais, ano, classe, duracao = linha.split()
        indices.append(int(indice))
        paises.append(pais)
        anos.append(int(ano))
        classes.append(classe)
        duracoes.append(int(duracao))

def produtividade(inicio, fim):
    """
    Pra cada ano, ele compara todos os
    elementos do arquivo e vai computando
    numa váriavel e "vezes" e "saida",
    posteriormente salvando tudo numa Lista.
    Aviso: Eu gosto muito de ter uma váriavel "atual"
    seja para quebrar whiles ou para salvar
    a posição de uma linha etc. Então ela vai
    ser muito usada aqui para esses fins.
    """
    vezes = 0
    atual = 0
    todas = []
    while True:
        if inicio+atual > fim:
            break
        for i in anos:
            if inicio+atual == i:
                vezes += 1 
        saida = (str(inicio+atual) + ": " + str(vezes))
        vezes = 0
        atual += 1
        todas.append(saida)
    return todas

def anos_presentes(inicio, fim):
    """
    essa função pega um ano (inicialmente o 'inicial'),
    vai adicioando 1 unidade e verificando no arquivo se existe
    alguma linha com ele.
    Obs: eu tentei fazer sem a variavel "atual", mas quebrou
    como com ela funcionou bem (não sei pq), eu deixei.
    """
    atual = 0
    todas = []
    while True:
        if inicio+atual > fim:
            break
        elif inicio+atual in anos:            
            saida = (str(inicio+atual))
            atual += 1
            todas.append(saida)
        else:
            atual += 1
    return todas

def filmes_por_classificacao(classificacao):
    """
    Essa função tem uma estrutura de while
    que imita um for, olhando todos os elementos
    de uma lista e comparando com algo.
    obs: qnd tentei fazer com for quebrou
    """
    todas = []
    atual = 0
    while True:
        if atual >= 4000:
            break
        elif classes[atual] == classificacao:
            todas.append(indices[atual])
            atual += 1
        else:
            atual += 1
    todas.sort()
    todasstr = []
    for i in todas:
        todasstr.append(str(i))
    return todasstr

def histograma_dos_anos(intervalos):
    """
    Essa função pega todos elemetos da lista "anos" e fica 
    comparando se esta entre dois numeros de uma lista de
    intervalos, qnd acha todos os elementos, repete a função
    e só para qnd chegarmos no ultimo intervalo
    """
    atual = 1
    todas = []
    while True:
        if atual >= len(intervalos):
            break
        vezes = 0
        for i in anos:
            if intervalos[atual-1] <= i < intervalos[atual]:
                vezes += 1    
        saida = ("[" + str(intervalos[atual-1]) + ", "+str(intervalos[atual]) + "):" + str(vezes))
        todas.append(saida)
        atual += 1
    return todas

def filmes_por_pais_e_classificacao(classificacao, pais):
    """
    Mesmo código da função filmes por classificacao, só adicionei mais uma condição no IF
    """
    todas = []
    atual = 0
    while True:
        if atual >= 4000:
            break
        elif classes[atual] == classificacao and paises[atual] == pais:
            todas.append(indices[atual])
            atual += 1
        else:
            atual += 1
    todas.sort()
    todasstr = []
    for i in todas:
        todasstr.append(str(i))
    return todasstr

def main():
    """
    Função main dispensa apresentações né mores.
    brincadeiras a parte, a função main é onde esta
    o acesso para todas as outras funções e segue uma nota.
    Nota: tem tanto elif e código similares
    que fiquei agoniado pensando se n dava para
    compactar isso, com função ou algo assim.
    """
    acao = sys.argv[1]
    if acao == "produtividade":
        inicio, fim = input().split()
        inicio = int(inicio)
        fim = int(fim)
        resultado = produtividade(inicio, fim)
    elif acao == "anos_presentes":
        inicio, fim = input().split()
        inicio = int(inicio)
        fim = int(fim)
        resultado = anos_presentes(inicio, fim)
    elif acao == "filmes_por_classificacao":
        classificacao = input()
        resultado = filmes_por_classificacao(classificacao)
    elif acao == "histograma_dos_anos":
        intervalos = list(map(int, input().split()))
        resultado = histograma_dos_anos(intervalos)
    elif acao == "filmes_por_pais_e_classificacao":
        pais, classificacao = input().split()
        resultado = filmes_por_pais_e_classificacao(classificacao, pais)
    print("\n".join(resultado))

main()