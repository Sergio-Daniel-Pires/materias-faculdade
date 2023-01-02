#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

typedef struct no
{
    char nome[20];
    int id;
    float valor;
    struct no *esq, *dir;
} No;

No *aloca(char nome[20], int id, float valor)
{
    //Aloca na memoria o No
    No *novo = malloc(sizeof(No));
    novo->esq = NULL;
    novo->dir = NULL;
    strcpy(novo->nome, nome);
    novo->valor = valor;
    novo->id = id;
    return novo;
}

typedef struct fila
{
    No *no;
    struct fila *proximo;
} Fila;

void desaloca_fila(Fila *fila)
{
    //Libera recursivamente da memória a fila
    if (fila)
    {
        desaloca_fila(fila->proximo);
        free(fila);
    }
}

void printar_fila(Fila *fila, int id, float valor)
{
    //Printa os elementos da fila, dando a impressao
    //de que o programa printa a arvore pelos nos
    Fila *fila_aux = fila->proximo;
    int verificacao = false;
    printf("OFERTAS para %d:\n", id);
    while (fila_aux)
    {
        printf("%s %d %0.2f\n", fila_aux->no->nome, id, fila_aux->no->valor);
        fila_aux = fila_aux->proximo;
        verificacao = true;
    }
    if (verificacao == false){
        printf("nenhuma boa oferta foi encontrada");
    }
    printf("\n");
}

void insere_elemento(Fila *fila, No *no_atual)
{
    //Insere elemento numa fila
    //serve para printar por ordem alfabética
    if(no_atual){
        Fila *atual = fila;
        Fila *proximo = atual->proximo;
        while (1)
        {
            if (proximo == NULL || strcmp(proximo->no->nome, no_atual->nome) > 0)
            {
                break;
            }
            atual = atual->proximo;
            proximo = atual->proximo;
        }
        Fila *novo = malloc(sizeof(Fila));
        novo->no = no_atual;
        novo->proximo = proximo;
        atual->proximo = novo;
    }
}

void busca(No *atual, Fila *fila, int id, float valor){
    //Busca de forma recursiva um elemento na arvore
    if(atual){
        if(atual->id == id && atual->valor <= valor){
            insere_elemento(fila, atual);
        }
        busca(atual->esq, fila, id, valor);
        busca(atual->dir, fila, id, valor);
    }
}

void desaloca_arvore(No *no_atual)
{
    //Libera recursivamente da memoria os nos
    if (no_atual)
    {
        desaloca_arvore(no_atual->esq);
        desaloca_arvore(no_atual->dir);
        free(no_atual);
    }
}

No *insere_no(No *no_atual, char nome[20], int id, float valor)
{
    /*Efetivamente insere o nó
    Efetuando o calculo dos 10%*/
    No *novo = aloca(nome, id, valor);
    if(no_atual->id == id && strcmp(no_atual->nome, nome)==0){
        no_atual->valor = valor;
        return NULL;
    }
    else{
        
        if (no_atual->valor > valor)
        {
            no_atual->esq = novo;
        }
        else
        {
            no_atual->dir = novo;
        }
        return novo;
    }
    return NULL;
}

No *acha_no(No *topo, char nome[20], int id, float valor)
{
    /*
    Localiza onde é para inserir o nó e retorna o ponteiro do local
    */
    if (
        //Verifica se não é para mudar um nó já existente
        (topo->id == id && strcmp(topo->nome, nome)==0) ||
        (topo->esq != NULL && topo->esq->id == id && strcmp(topo->esq->nome, nome)==0) ||
        (topo->dir != NULL && topo->dir->id == id && strcmp(topo->dir->nome, nome)==0)
    ){
        return topo;
    }
    if (topo->valor > valor && topo->esq)
    {
        return acha_no(topo->esq, nome, id, valor);
    }
    else if(topo->valor <= valor && topo->dir)
    {
        return acha_no(topo->dir, nome, id, valor);
    }
    return topo;
}

int main(void)
{
    //Inicializacao de variaveis
    int entradas;
    No *topo = NULL;

    char nome[20];
    int id;
    float valor;

    scanf("%d", &entradas);
    for (int i = 0; i < entradas; i++)
    {
        No *no_atual;
        scanf("%s %d %f", nome, &id, &valor);
        //Salva o nó inicial da arvore
        if(topo == NULL){
            topo = aloca(nome, id, valor);
            
        }
        else{
            //salva os seguintes nós na arvore
            no_atual = acha_no(topo, nome, id, valor);
            insere_no(no_atual, nome, id, valor);
        }
    }
    
    //Verifica quais ofertas deve procurar e a que custo
    
    scanf("%d", &entradas);
    for (int i = 0; i < entradas; i++)
    {
        //Isso evita que a fila comece de uma letra aleatoria como P
        //Retirar isso quebra o algoritmo que adiciona a palavra no lugar certo
        Fila *fila = malloc(sizeof(Fila));
        No *inicio_fila = aloca("aaaaaaaaaaaaaaaaaa", 0, 0);
        fila->no = inicio_fila;
        fila->proximo = NULL;
        
        scanf("%d %f", &id, &valor);
        busca(topo, fila, id, (valor * 1.1));

        //printa e libera fila
        printar_fila(fila, id, valor);
        desaloca_fila(fila);
        free(inicio_fila);
    }

    //Libera memoria arvore
    desaloca_arvore(topo);
    

    return 0;
}