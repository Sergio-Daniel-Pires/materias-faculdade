#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roteador.h"
#define false 0
#define true 1
#define PAI(i) ((i-1)/2)
#define F_ESQ(i) (2*i+1) /*Filho esquerdo de i*/
#define F_DIR(i) (2*i+2) /*Filho direito de i*/

Fila *aloca(int memoria_roteador){
    //Aloca fila na memória
    Fila *fila;
    fila = malloc(sizeof(Fila));
    fila->vetor = malloc(memoria_roteador * sizeof(Item));
    fila->tamanho = 0;
    fila->maximo = memoria_roteador;
    return fila;
}

int parada(int id, int prioridade, int incremento){
    //Verifica se é o caso de parada
    if(id == 0)
        if(prioridade == 0)
            if(incremento == 0)
                return true;
    return false;
}

void troca(Item *atual, Item *pai){
    //Verifica se o pai é maior que os dois
    //ele insere o maior no lugar do pai
    Item vetor_auxiliar;
    vetor_auxiliar = (*pai);
    (*pai) = (*atual);
    (*atual) = vetor_auxiliar;
}

Item cria_item(int id, int prioridade, int incremento, int tick){
    //Cria e adiciona os itens no item
    Item novo;
    novo.id = id;
    novo.prioridade = prioridade;
    novo.incremento = incremento;
    novo.tick = tick;
    return novo;
}

void verifica_cima(Fila *fila, int atual){
    //verifica se precisa continuar subindo e trocando
    int prior_pai = fila->vetor[PAI(atual)].prioridade;
    int prior_filho = fila->vetor[atual].prioridade;
    if (atual > 0 && prior_pai < prior_filho) {
        troca(&fila->vetor[atual], &fila->vetor[PAI(atual)]);
        verifica_cima(fila, PAI(atual));
    }
}

void insere(Fila *fila, Item novo, int memoria_roteador){
    //Insere na fila
    if(fila->tamanho < memoria_roteador){
        fila->vetor[fila->tamanho] = novo;
        fila->tamanho += 1;
        verifica_cima(fila, fila->tamanho - 1);
    }
}

void verifica_baixo(Fila *fila, int atual){
    //Verifica se precisa continuar descendo/qual e trocando
    int maior_filho;
    if (F_ESQ(atual) < fila->tamanho) {
        maior_filho = F_ESQ(atual);
        if (F_DIR(atual) < fila->tamanho && fila->vetor[F_ESQ(atual)].prioridade < fila->vetor[F_DIR(atual)].prioridade){
            maior_filho = F_DIR(atual);
        }
        if (fila->vetor[atual].prioridade < fila->vetor[maior_filho].prioridade) {
            troca(&fila->vetor[atual], &fila->vetor[maior_filho]);
            verifica_baixo(fila, maior_filho);
        }
    }
}

Item maximo(Fila *fila) {
    //Extrai o maior elemento da fila
    Item item = fila->vetor[0];
    troca(&fila->vetor[0], &fila->vetor[fila->tamanho - 1]);
    fila->tamanho--;
    verifica_baixo(fila, 0);
    return item;
}

int main(void){
    //Declarar variaveis
    int max_tick, memoria_roteador;
    int id, prioridade, incremento;
    int tick = 1;
    Fila *fila;

    scanf("%d %d", &max_tick, &memoria_roteador);

    fila = aloca(memoria_roteador);

    while (scanf("%d %d %d", &id, &prioridade, &incremento) != EOF){
        if(parada(id, prioridade, incremento)){
            //Verifica se é uma linha de parada
            printf("TICK %d\n", tick);
            for(int x = 0; x < max_tick; x++){
                if(fila->tamanho == 0){
                    fila->tamanho = 0;
                    break;
                }
                //printa os ticks precisos
                Item atual = maximo(fila);
                printf("%d\t%d\t%d\n", atual.id, atual.prioridade, atual.incremento);
            }
            tick++;
        }
        else{
            //Se nao for o caso de parada, insere
            Item novo = cria_item(id, prioridade, incremento, tick);
            insere(fila, novo, memoria_roteador);
        }
    }

    //Libera a memoria
    free(fila->vetor);
    free(fila);
    return 0;
}