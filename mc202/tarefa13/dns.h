typedef struct arvore{
    char DNS[100];
    char IP[16];
    int nivel;
    int acessos;
    struct arvore *esq, *dir;
} Arvore;

void aloca_Arvore(Arvore **atual_server, char DNS[100], char IP[16]);

void desaloca_arvore(Arvore **no_atual);

void calcNivel(Arvore **atual);

int nivel(Arvore **atual);

void rotDir(Arvore **atual);

void rotEsq(Arvore **atual);

int calculafb(Arvore **atual);

void balanceamento(Arvore **atual);

void insere_server(Arvore **atual, char DNS[100], char IP[20], Arvore **no_atual);

void acha_server(Arvore *atual, char DNS[100], Arvore **server_atual);