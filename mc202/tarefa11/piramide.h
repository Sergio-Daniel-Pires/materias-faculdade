typedef struct no
{
    struct no *esq, *dir;
    double valor;
    int nivel;
    char nome[20];
} No;

typedef struct fila
{
    No *no;
    struct fila *proximo;
} Fila;

No *aloca(double valor, char nome[20]);

void *desaloca_fila(Fila *fila);

void *desaloca_arvore(No *no_atual);

No *insere_no(No *no_atual, double valor, char nome[20]);

int calc_valor(No *topo, char recrutador[20]);

No *acha_no(No *topo, char recrutador[20]);

void cria_fila(Fila *fila, No *no_atual);

void printar_fila(Fila *fila);