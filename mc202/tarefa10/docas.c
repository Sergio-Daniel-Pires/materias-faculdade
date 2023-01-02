#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define carrega 0
#define descarrega 1

typedef struct navio{
    char nome[20];
    char mercadoria[20];
    int funcao;
    int quantidade;
    struct navio *proximo;
} Navio;

typedef struct doca{
    int numero;
    int qtd_total;
    struct container *topo;
    struct doca *proxima;
} Doca;

typedef struct container{
    int qtd;
    char mercadoria[20];
    struct container *anterior;
} Container;

Navio *aloca(){
    return malloc(sizeof(Navio));
}

void adiciona_container(Doca *doca_atual, char mercadoria[20]);

int descarregamento(Navio *atual, Doca *doca_inicio, int max_operar){
    /*
    Verifica se uma doca esta vazio e/ou tem espaço para colocar mais um container
    */
    Doca *doca_atual = doca_inicio;
    while(1){
        if(doca_atual->topo == NULL || doca_atual->qtd_total < max_operar){
            //Aqui verifica se "junta" os containeres ou não
            //Igual ocorre quando vão tirar fracionado no carregamento
            if(doca_atual->topo == NULL){
                adiciona_container(doca_atual, atual->mercadoria);
            }
            else if(strcmp(doca_atual->topo->mercadoria, atual->mercadoria)){
                adiciona_container(doca_atual, atual->mercadoria);
            }
            //Opera quantidade que entra e sai do navio
            int operado = max_operar - doca_atual->qtd_total;;
            if(operado > atual->quantidade){
                operado = atual->quantidade;
            }
            doca_atual->topo->qtd += operado;
            doca_atual->qtd_total += operado;
            atual->quantidade -= operado;
            printf("%s descarrega %s doca: %d conteineres: %d\n", atual->nome, atual->mercadoria, doca_atual->numero, operado);
            return 1;
        }
        //Verifica se ele conseguiu descarregar em algum lugar
        //caso não, retorna 0
        //(necessario para uma soma mais tarde)
        if(doca_atual->proxima == NULL){
            break;
        }
        else{
            doca_atual = doca_atual->proxima;
        }
    }
    return 0;
}

int carregamento(Navio *atual, Doca *doca_inicio, int max_operar){
    //Verifica se o primeiro container da pilha tem a mercadoria
    //De que o navio precisa
    Doca *doca_atual = doca_inicio;
    while(1){
        if(doca_atual->topo != NULL){
            if (strcmp(doca_atual->topo->mercadoria, atual->mercadoria)==0){
                //Aqui tem operações para verificar quanto pode e/ou precisa retirar
                int operado = atual->quantidade;
                int permitido_sair;
                //Verifica qual é maior, se o maximo de operações com guindase
                //Ou o quanto pode sair
                if(max_operar > doca_atual->topo->qtd){
                    permitido_sair = doca_atual->topo->qtd;
                }
                else{
                    permitido_sair = max_operar;
                }
                //Verifica se o "permitido_sair" é mais do que precisa no navio
                //Senão pega só o quanto precisa
                if(permitido_sair < atual->quantidade){
                    operado = permitido_sair;
                }
                doca_atual->topo->qtd -= operado;
                doca_atual->qtd_total -= operado;
                atual->quantidade -= operado;
                printf("%s carrega %s doca: %d conteineres: %d\n", atual->nome, atual->mercadoria, doca_atual->numero, operado);
                //remove container da pilha se a quantidade dele for 0
                if(doca_atual->topo->qtd == 0){
                    Container *deletar = doca_atual->topo;
                    doca_atual->topo = doca_atual->topo->anterior;
                    free(deletar);
                }
                return 1;
            }
        }
        //Verifica se efetuou um carregamento, se não retorna 0
        //(necessario para uma soma mais tarde)
        if(doca_atual->proxima == NULL){
            break;
        }
        else{
            doca_atual = doca_atual->proxima;
        }
    }
    return 0;
}

void adiciona_container(Doca *doca_atual, char mercadoria[20]){
    //Adiciona container e redefine o topo da pilha
    Container *novo_container = malloc(sizeof(Container));
    novo_container->anterior = doca_atual->topo;
    doca_atual->topo = novo_container;
    novo_container->qtd = 0;
    strcpy(novo_container->mercadoria, mercadoria);
}

void classifica_func(Navio *atual, char func[11]){
    //verifica se é para carregar ou descarregar
    //por ser uma binario, facilita na verificacao mais tarde
    if (strcmp(func, "carrega")){
        atual->funcao = descarrega;
    }
    else{
        atual->funcao = carrega;
    }
}

void percorre_fila(Navio *atual, Doca *doca_inicio, int max_operar, Navio *inicio){
    //Percorre a fila, se for constado que nenhum barco realizou nenhuma operação
    //Ele encerra, caso contrário, ele reinicia a fila pelo inicio
    int verificador = 0;
    while(1){
        if(atual->funcao && atual->quantidade != 0){
            verificador += descarregamento(atual, doca_inicio, max_operar);
        }
        else if(atual->quantidade != 0){
            verificador += carregamento(atual, doca_inicio, max_operar);
        }
        if(atual->proximo==NULL){
            if(verificador == 0){
                break;
            }
            else{
                verificador = 0;
                atual = inicio;
            }
        }
        else{
            atual = atual->proximo;
        }
    }
}

void inicializa_docas(Doca *doca_atual, int num_docas){
    //Inicializa as docas vazias
    for(int i=1; i<num_docas ;i++){
        Doca *nova = malloc(sizeof(Doca));
        doca_atual->proxima = nova;
        doca_atual = nova;
        nova->numero = i;
        nova->proxima = NULL;
        nova->qtd_total = 0;
    }
}

void libera_docas(Doca *doca_atual){
    /*
    Função simples com while para liberar
    docas e, caso precise, containeres
    */
    while(1){
        Doca *deletar = doca_atual;
        if(doca_atual->topo != NULL){
            //Aqui vai liberando pilha até chegar em NULL
            Container *deletar_cont, *atual;
            atual = doca_atual->topo;
            while(atual->anterior != NULL){
                deletar_cont = atual;
                atual = atual->anterior;
                free(deletar_cont);
            }
        }
        if(doca_atual->proxima == NULL){
            free(deletar);
            break;
        }
        else{
            doca_atual = doca_atual->proxima;
            free(deletar);
        }
    }
}

int main(void){
    //definindo tipos
    int num_docas, max_operar, num_navios, qtd;
    Navio *inicio, *anterior, *novo;
    char func[11];

    scanf("%d", &num_docas);
    scanf("%d", &max_operar);
    scanf("%d", &num_navios);

    //Inicializa as docas
    Doca *doca_inicio, *doca_atual;
    doca_inicio = malloc(sizeof(Doca));
    doca_inicio->numero = 0;
    doca_inicio->topo= NULL;
    doca_inicio->qtd_total = 0;
    doca_atual = doca_inicio;
    inicializa_docas(doca_atual, num_docas);

    //definindo inicio da fila de navios
    inicio = aloca();
    scanf("%s %s %s %d", inicio->nome, func, inicio->mercadoria, &qtd);
    inicio->quantidade = qtd;
    classifica_func(inicio, func);
    inicio->proximo = NULL;
    anterior = inicio;

    //Essa parte da função cria a fila atrás do 'inicio'
    for(int i=0;i < num_navios-1;i++){
        //cria sistema de fila
        novo = aloca();
        novo->proximo = NULL;
        anterior->proximo = novo;
        anterior = novo;

        scanf("%s %s %s %d", novo->nome, func, novo->mercadoria, &qtd);
        novo->quantidade = qtd;
        classifica_func(novo, func);
    }
    Navio *atual = inicio;
    percorre_fila(atual, doca_inicio, max_operar, inicio);

    //Libera navios, verificando se ainda havia mercadoria neles
    int quantidade_navios = 0;
    atual = inicio;
    while(1){
        Navio *deletar = atual;
        if(atual->quantidade){
            quantidade_navios++;
        }
        if(atual->proximo == NULL){
            free(deletar);
            break;
        }
        else{
            atual = atual->proximo;
        }
        free(deletar);
    }
    if(quantidade_navios){
        printf("ALERTA: impossivel esvaziar fila, restam %d navios.\n", quantidade_navios);
    }

    //libera docas, caso haja containers, os liberam tmb
    doca_atual = doca_inicio;
    libera_docas(doca_atual);
    return 0;
}