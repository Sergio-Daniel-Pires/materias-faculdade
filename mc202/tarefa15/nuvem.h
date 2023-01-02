#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define true 1
#define false 0
#define MAX 50
#define primo 1783

typedef struct lista_palavras
{
    char palavra[MAX];
    int stop;
    int vezes;
    int hash;
} Lista_palavras;

typedef struct hash_cel
{
    Lista_palavras palavras[20];
} Hash_cel;

typedef struct fila
{
    Lista_palavras *atual;
    struct fila *prox, *ant;
} Fila;

int hash(char *chave);

void enfileira(Fila **fila, Lista_palavras *atual);

void quicksort(Fila **fila);

void normalizastr(char *str_bruta, char *str_nova, int *naotemnumero);