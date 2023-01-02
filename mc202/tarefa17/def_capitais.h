#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tam_char 50
#define infinito 9999999

typedef struct cidade
{
    int pessoas_contidas;
    char nome_cidade[tam_char];
} Cidade;

typedef struct dados_cidade
{
    char cidade[tam_char];
    double fator_centralidade;
    int acesso_pessoas;
} Dados_cidade;

typedef struct fila
{
    Dados_cidade *atual;
    struct fila *prox, *ant;
} Fila;

void enfileira(Fila **fila, Dados_cidade *atual);

double calcula_fator_centralidade(int cidade_atual, int num_cidades, Cidade *cidades, double **matriz_adj, Dados_cidade *atual);

void quicksort(Fila **fila);

void encontra_menor_caminho(double **matriz_adj, int num_cidades);

void salva_distancia(double **matriz_adj, Cidade *cidades, char cidade1[], char cidade2[], int distancia, int num_cidades);