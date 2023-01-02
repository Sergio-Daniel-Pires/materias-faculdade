#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "piramide.h"
#define true 1
#define false 0

No *aloca(double valor, char nome[20])
{
    //Aloca na memoria o No
    No *novo = malloc(sizeof(No));
    novo->esq = NULL;
    novo->dir = NULL;
    strcpy(novo->nome, nome);
    novo->valor = valor;
    return novo;
}

void *desaloca_fila(Fila *fila)
{
    //Libera recursivamente da memória a fila
    if (fila)
    {
        desaloca_fila(fila->proximo);
        free(fila);
    }
    return 0;
}

void *desaloca_arvore(No *no_atual)
{
    //Libera recursivamente da memoria os nos
    if (no_atual)
    {
        desaloca_arvore(no_atual->esq);
        desaloca_arvore(no_atual->dir);
        free(no_atual);
    }
    return 0;
}

No *insere_no(No *no_atual, double valor, char nome[20])
{
    /*Efetivamente insere o nó
    Efetuando o calculo dos 10%*/
    char recrutador_atual[20];
    strcpy(recrutador_atual, no_atual->nome);
    No *novo = aloca(valor, nome);

    //Bonifica com 10% o recrutado
    no_atual->valor = no_atual->valor - novo->valor * 0.10;
    novo->valor = novo->valor * 1.10;

    //Verifica se ele vai ser inserido na esquerda ou na direita
    if (no_atual->esq == NULL)
    {
        no_atual->esq = novo;
        (no_atual->esq)->nivel = no_atual->nivel + 1;
    }
    else
    {
        no_atual->dir = novo;
        (no_atual->dir)->nivel = no_atual->nivel + 1;
    }
    return novo;
}

int calc_valor(No *topo, char recrutador[20])
{
    /*
    Localiza onde é para inserir o nó e retorna o ponteiro do local
    */
    if (topo){
        char recrutador_atual[20];
        strcpy(recrutador_atual, topo->nome);
        if (strcmp(recrutador_atual, recrutador) == 0)
        {   
            //Faz a bonificacao de quando atinge os 2 recrutados
            topo->valor += ((topo->esq->valor * 0.06) + (topo->dir->valor * 0.06));
            topo->esq->valor = topo->esq->valor * 0.94;
            topo->dir->valor = topo->dir->valor * 0.94;
            return 5;
        }

        //Bonifica ate 5 niveis acima
        double valor;
        double recebido = 0;

        valor = calc_valor(topo->esq, recrutador);
        if (valor){
            recebido = topo->esq->valor * (valor / 100);
            topo->valor += recebido;
            topo->esq->valor -= recebido;
        }
        else{
            valor = calc_valor(topo->dir, recrutador);
            if (valor){
                recebido = topo->dir->valor * (valor / 100);
                topo->valor += recebido;
                topo->dir->valor -= recebido;
            }
        }
        if (valor > 0)
        {
            return valor - 1;
        }
        return 0;
    }
    return 0;
}

No *acha_no(No *topo, char recrutador[20])
{
    /*
    Localiza onde é para inserir o nó e retorna o ponteiro do local
    */
    if (topo){
        char recrutador_atual[20];
        strcpy(recrutador_atual, topo->nome);
        if (strcmp(recrutador_atual, recrutador) == 0)
        {
            return topo;
        }

        //Aqui vai percorrer tudo para ver se acha a posicao
        No *achado;
        achado = acha_no(topo->esq, recrutador);
        if (achado){
            return achado;
        }
        achado = acha_no(topo->dir, recrutador);
        if (achado){
            return achado;
        }
    }
    return NULL;
}

void cria_fila(Fila *fila, No *no_atual){
    if(no_atual){
        cria_fila(fila, no_atual->esq);
        Fila *atual = fila;
        Fila *proximo = atual->proximo;
        while (1){
            if (proximo == NULL || proximo->no->nivel > no_atual->nivel)
            {
                break;
            }
            atual = atual->proximo;
            proximo = atual->proximo;
        }
        if(no_atual->nivel != 1){
            Fila *novo = malloc(sizeof(Fila));
            novo->no = no_atual;
            novo->proximo = proximo;
            atual->proximo = novo;
        }
        cria_fila(fila, no_atual->dir);
    }
}

void printar_fila(Fila *fila)
{
    //Printa os elementos da fila, dando a impressao
    //de que o programa printa a arvore pelos nos
    int nivel = 0;
    while (fila)
    {
        if (nivel != fila->no->nivel)
        {
            nivel = fila->no->nivel;
            printf("\nNivel %d: ", nivel);
        }
        printf("[%s %0.2lf] ", fila->no->nome, fila->no->valor);
        fila = fila->proximo;
    }
    printf("\n");
}

int main(void)
{
    //Inicializando valores
    char tipo[8], recrutador[20], nome[20];
    double valor;

    //Cria Nó inicial e primeiro elemento da
    //fila encadeada (vai ser util para printar)
    scanf("%s %s %lf", tipo, recrutador, &valor);
    No *topo = aloca(valor, recrutador);
    topo->nivel = 1;
    Fila *fila = malloc(sizeof(Fila));
    fila->proximo = NULL;
    fila->no = topo;
    printf("Nivel 1: [%s %0.2lf] \n", fila->no->nome, fila->no->valor);

    while (scanf("%s %s %s %lf", recrutador, tipo, nome, &valor) != EOF)
    {
        No *no_atual = acha_no(topo, recrutador);
        insere_no(no_atual, valor, nome);

        //Essa parte vai criar a fila sempre na ordem certa, printar e destruir
        Fila *fila = malloc(sizeof(Fila));
        fila->proximo = NULL;
        fila->no = topo;
        cria_fila(fila, topo);

        //Calcula valor a ser descontado
        if (no_atual->esq && no_atual->dir)
            calc_valor(topo, no_atual->nome);

        printar_fila(fila);
        desaloca_fila(fila);
    }

    //libera memoria
    desaloca_arvore(topo);
    desaloca_fila(fila);

    return 0;
}