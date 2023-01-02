#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    int cod;
    char nome[25];
    char vaxx[13];
    struct pessoa *proxima;
} Pessoa;

Pessoa *aloca(){
    return malloc (sizeof(Pessoa));
}

int main(void){
    Pessoa *aux, *nova, *inicio, *conector;

    //Aloca o inicio da fila na memoria
    inicio = aloca();
    inicio->proxima = NULL;
    inicio->cod = 0;

    aux = inicio; //para começar no começo
    int cod; //numero
    char nome[25], vaxx[15]; //nome e status de vacinação
    
    int i=0;
    int dupla = 0;

    while (scanf("%d %s %s", &cod, nome, vaxx) != EOF){
        nova = aloca();
        nova->cod = cod;
        strcpy(nova->nome, nome);
        strcpy(nova->vaxx, vaxx);
        nova->proxima = NULL;
        if(strcmp("coach", nome)==0 || strcmp("ex-bbb", nome)==0 || strcmp("filho-politico", nome)==0 || strcmp("herdeiro", nome)==0 || strcmp("youtuber-financas", nome)==0){
            if (dupla == 1){
                while(aux->proxima != NULL){
                    aux = aux->proxima;
                }
                aux->proxima = conector;
            }
            conector = inicio->proxima;//salva conector que vai quebrar do inicio
            inicio->proxima = nova;
            aux = inicio;
            dupla = 1;
        }
        else if(strcmp("funcionario", nome)==0){
            if (dupla == 1){
                while(aux->proxima != NULL){
                    aux = aux->proxima;
                }
                aux->proxima = conector;
                dupla = 0;
                
            }
            while(aux->proxima != NULL){
                aux = aux->proxima;
            }
            aux->proxima = nova;
        }
        else{
            while(aux->proxima != NULL){
                aux = aux->proxima;
            }
            if (inicio->proxima == NULL && dupla == 0){
                inicio->proxima = nova;
            }
            aux->proxima = nova;
        }
        i++;
    }
    if (dupla == 1){
        while(aux->proxima != NULL){
            aux = aux->proxima;
        }
        aux->proxima = conector;
    }

    //Verifica se tem um fiscal na fila
    int fisc = 0;
    aux = inicio;
    while(1){
        if (fisc == 1){
            if(strcmp(aux->vaxx, "nao-vacinado")==0){
                aux->cod = 0;
            }
            else{
                fisc = 0;
            }
        }
        if(strcmp("fiscal", aux->nome)==0){
            fisc = 1;
        }
        if(aux->proxima == NULL){
            break;
        }
        aux = aux->proxima;
    }

    aux = inicio;
    int x = 0;
    while(1){
        if(aux->cod != 0){
            printf("%d %s %s\n", aux->cod, aux->nome, aux->vaxx);
        }
        if(aux->proxima == NULL){
            break;
        }
        else{
            aux = aux->proxima;
        }
        x++;
    }

    //Libera a memória alocada
    Pessoa *auxx;
    aux = inicio;
    while(aux->proxima != NULL){
        auxx = aux->proxima;
        free(aux);
        aux = auxx;
    }
    
    free(auxx);

    return 0;
}