#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_PASSOS 2
#define TAM_NOME 30

typedef struct sala
{
    int atributos;
    char nome_sala[TAM_NOME];
    int pos_matriz;
    int jogadores_passaram;
} Sala;

typedef struct fila
{
    struct fila *anterior, *proximo;
    char nome_sala[TAM_NOME];
} Fila;

int salvar_atributos(){
    int atributos = 0;
    int multiplicador = 100000;
    int valor_atributo;
    for(int i = 0; i < 6; i++){
        scanf(" %d", &valor_atributo);
        atributos += multiplicador * valor_atributo;
        multiplicador = multiplicador / 10;
    }
    return atributos;
}

void adiciona_fila(Fila **fila, char nome_sala[TAM_NOME]){
    Fila *novo = malloc(sizeof(Fila));
    novo->anterior = (*fila);
    strcpy(novo->nome_sala, nome_sala);

    if((*fila)){
        (*fila)->proximo = novo;
    }

    (*fila) = novo;
}

void procura_salas(int sala_atual, int **matriz_adj, int sala_anterior, int maximo_salas, int passos_andados, Sala *salas, Fila **fila, int num_jogadores){
    if(salas[sala_atual].jogadores_passaram + 1 == num_jogadores){
        adiciona_fila(fila, salas[sala_atual].nome_sala);
    }
    salas[sala_atual].jogadores_passaram++;
    if(passos_andados < MAX_PASSOS){
        for(int sala = 0; sala < maximo_salas; sala++){
            //Verifica se a matriz esta em 1 E
            //a sala nova é diferente da atual
            if(sala != sala_atual && sala != sala_anterior && matriz_adj[sala_atual][sala] == 1){
                procura_salas(sala, matriz_adj, sala_atual, maximo_salas, (passos_andados + 1), salas, fila, num_jogadores);
            }
        }
    }
}

void imprime_fila(Fila *fila){
    if(fila){
        printf("%s\n", fila->nome_sala);
        imprime_fila(fila->anterior);
    }
}

void quicksort(Fila **fila){
    /*
    Algoritmo padrao de quick sort para ordernar
    com a diferença que também ordena em ordem alfabética
    */
    Fila *maior, *menor;
    maior = (*fila);
    while (maior){
        menor = maior->anterior;
        while (menor)
        {
            if (strcmp(maior->nome_sala, menor->nome_sala) > 0)
            {
                char str_auxiliar[TAM_NOME];
                strcpy(str_auxiliar, maior->nome_sala);
                strcpy(maior->nome_sala, menor->nome_sala);
                strcpy(menor->nome_sala, str_auxiliar);
            }
            menor = menor->anterior;
        }
        maior = maior->anterior;
    }
    imprime_fila((*fila));
}

int main(void){
    //Declaracao de variaveis
    int numero_salas, numero_jogadores, atributos;
    char nome_sala[TAM_NOME];
    Sala *salas;
    int **matriz_adj;
    Fila *fila;
    fila = NULL;

    scanf("%d", &numero_salas);
    salas = (Sala *)malloc(numero_salas * sizeof(Sala));
    matriz_adj = (int **)malloc(numero_salas * sizeof(int*));
    
    //define os dados de cada sala
    for(int i = 0; i < numero_salas; i++){
        scanf("%s", nome_sala);
        strcpy(salas[i].nome_sala, nome_sala);
        salas[i].pos_matriz = i;
        salas[i].atributos = salvar_atributos();

        //criando matriz de adjacencias
        matriz_adj[i] = (int *)malloc(numero_salas * sizeof(int));
    }

    //Cria a matriz de adjascencias
    for(int i = 0; i < numero_salas; i++){
        for(int j = 0; j < numero_salas; j++){
            int calculo;
            int salai = salas[i].atributos;
            int salaj = salas[j].atributos;
            calculo = salai - salaj;
            if (calculo == -100000 || calculo == -10000 || calculo == -1000
                || calculo == -100 || calculo == -10 || calculo == -1){
                    matriz_adj[i][j] = 1;
                    matriz_adj[j][i] = 1;
            }
        }
    }

    scanf("%d", &numero_jogadores);
    char nome_jogador[TAM_NOME];

    //Aqui faz a parte dos players
    for(int i = 0; i < numero_jogadores; i++){
        scanf("%s", nome_jogador);
        atributos = salvar_atributos();
        
        //aqui acha a sala em que ele esta
        int pos;
        for(int sala_atual = 0; sala_atual < numero_salas; sala_atual++){
            if(salas[sala_atual].atributos == atributos){
                pos = sala_atual;
                break;
            }
            //printf("sala: %s || vezes que passaram: %d\n", salas[sala_atual].nome_sala, salas[sala_atual].jogadores_passaram);
        }
        //printf("\n");
        procura_salas(pos, matriz_adj, -1, numero_salas, 0, salas, &fila, numero_jogadores);
    }

    if(fila){
        quicksort(&fila);
        
    }
    else{
        printf("\nImpossivel terminar em duas rodadas.\n");
    }

    return 0;
}