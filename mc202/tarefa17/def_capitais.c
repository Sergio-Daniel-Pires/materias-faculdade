#include "def_capitais.h"

void enfileira(Fila **fila, Dados_cidade *atual){
    /*
        Adiciona uma palavra nova na fila de palavras
    */
    Fila *novo = malloc(sizeof(Fila));
    novo->atual = atual;
    novo->ant = (*fila);
    novo->prox = NULL;
    if ((*fila))
    {
        (*fila)->prox = novo;
    }
    (*fila) = novo;
}

double calcula_fator_centralidade(int cidade_atual, int num_cidades, Cidade *cidades, double **matriz_adj, Dados_cidade *atual){
    /*
        Começa calculando o divisor
        Ja adicionando o da propria cidade
        No fim, caso ele seja igual ao
        tanto de cidades
        Ele ja retorna falso
    */
    double dividendo = 0;
    double divisor = 0;

    for(int cidade_matriz = 0; cidade_matriz < num_cidades; cidade_matriz++){
        
        // Verifica ligacoes da cidade atual 
        if(matriz_adj[cidade_atual][cidade_matriz] || cidade_atual == cidade_matriz){
            atual->acesso_pessoas += cidades[cidade_matriz].pessoas_contidas;

            //Adiciona a multiplicacao da distancia vezes o numero de cidades contidas
            dividendo += (cidades[cidade_matriz].pessoas_contidas * matriz_adj[cidade_atual][cidade_matriz]);

            //Adiciona o tanto de cidades contidas ao divisor
            divisor += cidades[cidade_matriz].pessoas_contidas;
        }
    }
    double fator_centralidade = dividendo/divisor;
    return fator_centralidade;
}

void quicksort(Fila **fila){
    /*
    Algoritmo padrao de quick sort para ordernar
    com a diferença que também ordena em ordem alfabética
    */
    Fila *maior, *menor;
    maior = (*fila);
    while (maior)
    {
        menor = maior->ant;
        while (menor)
        {
            if (maior->atual->fator_centralidade > menor->atual->fator_centralidade || (maior->atual->fator_centralidade == menor->atual->fator_centralidade && strcmp(maior->atual->cidade, menor->atual->cidade) < 0)){   
                Dados_cidade *auxiliar = maior->atual;
                maior->atual = menor->atual;
                menor->atual = auxiliar;
            }
            menor = menor->ant;
        }
        maior = maior->ant;
    }
}

void encontra_menor_caminho(double **matriz_adj, int num_cidades){
    // Algoritmo baseado num video visto no ytb
    for(int k = 0; k < num_cidades; k++){
        for(int i = 0; i < num_cidades; i++){
            for(int j = 0; j < num_cidades; j++){
                if((matriz_adj[i][k] + matriz_adj[k][j] < matriz_adj[i][j] || (matriz_adj[i][j] == 0 && matriz_adj[i][k] + matriz_adj[k][j] != 0)) && i != j && matriz_adj[i][k] && matriz_adj[k][j])
                    matriz_adj[i][j] = matriz_adj[i][k] + matriz_adj[k][j];
            }
        }
    }
}

void salva_distancia(double **matriz_adj, Cidade *cidades, char cidade1[], char cidade2[], int distancia, int num_cidades){
    int pos1, pos2;
    for(int cidade_atual = 0; cidade_atual < num_cidades; cidade_atual++){
        //acha a posicao da cidade1 na matriz
        if(strcmp(cidades[cidade_atual].nome_cidade, cidade1) == 0)
            pos1 = cidade_atual;
        //acha a posicao da cidade2 na matriz
        if(strcmp(cidades[cidade_atual].nome_cidade, cidade2) == 0)
            pos2 = cidade_atual;
    }

    // Depois de achar, salva a distancia relativa entre os dois
    matriz_adj[pos1][pos2] = distancia;
    matriz_adj[pos2][pos1] = distancia;
}