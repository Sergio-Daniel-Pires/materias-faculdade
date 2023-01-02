typedef struct item{
    int id;
    int prioridade;
    int incremento;
    int tick;
} Item;

typedef struct fila{
    Item *vetor;
    int tamanho;
    int maximo;
} Fila;

int parada(int id, int prioridade, int incremento);

void extrair(Fila *fila);

void troca(Item *atual, Item *pai);

Item cria_item(int id, int prioridade, int incremento, int tick);

void verifica(Fila *fila, int atual);

void insere(Fila *fila, Item novo, int memoria_roteador);

Fila *aloca(int memoria_roteador);