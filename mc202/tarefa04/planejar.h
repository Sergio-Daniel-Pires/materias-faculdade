typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct voo {
    int nvoo;
    char ida[4];
    char vinda[4];
    Data data;
    double valor;
} Voo;

typedef struct plano {
    char ida[4];
    Data dida;
    Data vinda;
} Plano;

typedef struct atual {
    double valor;
    int numi, numv;
} Atual;

Data ler_data();

int compara_data(Data data1, Data data2);

int diferenca_data(Data data1, Data data2);

void registrar(Voo voos[], int qtd_voos, int numero_voo);

void cancelar(Voo voos[], int qtd_voos, int numero_voo);

void alterar(Voo voos[], int qtd_voos, int numero_voo, float novo_valor);

void planejar(Voo voos[], int qtd_voos, Plano planejar[]);

int dataemdia(Data data);