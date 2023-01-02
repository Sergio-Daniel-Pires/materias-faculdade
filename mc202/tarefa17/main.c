#include "def_capitais.h"

int main(void){
    //Declaracao de variaveis
    int num_cidades = 0, pessoas_contidas = 0, total_populacao = 0;
    double fator_centralidade;
    double **matriz_adj;
    char nome_cidade[tam_char];
    Cidade *cidades;
    Fila *fila = NULL;

    char cidade1[tam_char], cidade2[tam_char];
    double distancia;

    scanf("%d", &num_cidades);
    cidades = (Cidade *)malloc(num_cidades * sizeof(Cidade));
    matriz_adj = (double **)malloc(num_cidades * sizeof(double*));

    for(int i = 0; i < num_cidades; i++){
        scanf("%s %d", nome_cidade, &pessoas_contidas);
        total_populacao += pessoas_contidas; 
        
        strcpy(cidades[i].nome_cidade, nome_cidade);
        cidades[i].pessoas_contidas = pessoas_contidas;

        // Criando matriz de adjacencias
        matriz_adj[i] = (double *)malloc(num_cidades * sizeof(double));
        for(int j = 0; j < num_cidades; j++){
            matriz_adj[i][j] = 0;
        }
    }
    
    // Aqui salva distancia das cidades
    while(scanf("%s %s %lf", cidade1, cidade2, &distancia) != EOF){
        salva_distancia(matriz_adj, cidades, cidade1, cidade2, distancia, num_cidades);
    }

    // Funcao para printar, util para debugar
    encontra_menor_caminho(matriz_adj, num_cidades);

    for(int cidade_atual = 0; cidade_atual < num_cidades; cidade_atual++){
        // Salva os dados no objeto Dados_cidade chamada atual
        Dados_cidade *atual = malloc(sizeof(Dados_cidade));
        atual->acesso_pessoas = 0;
        fator_centralidade = calcula_fator_centralidade(cidade_atual, num_cidades, cidades, matriz_adj, atual);
        atual->fator_centralidade = fator_centralidade;
        strcpy(atual->cidade, cidades[cidade_atual].nome_cidade);

        enfileira(&fila, atual);
    }
    quicksort(&fila);
    
    // Printa a fila
    while(1){
        if(fila->atual->fator_centralidade && fila->atual->acesso_pessoas >= total_populacao * 0.5)
            printf("%s %0.2lf\n", fila->atual->cidade, fila->atual->fator_centralidade);
        if(fila->prox){
            free(fila->prox->atual);
            free(fila->prox);
        }
        if(fila->ant){
            fila = fila->ant;
        }
        else{
            break;
        }
    }
    free(cidades);
    free(fila->atual);
    free(fila);

    // Libera matriz adj    
    for(int i = 0; i < num_cidades; i++){
        free(matriz_adj[i]);
    }
    free(matriz_adj);
    
    return 0;
}