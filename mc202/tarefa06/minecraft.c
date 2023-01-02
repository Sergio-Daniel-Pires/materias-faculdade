#include <stdio.h>
#include <stdlib.h>
#include "minecraft.h"

int **calcularAltitudes(int m, int n, int seed){
    int **altitudes;
    altitudes = (int **) malloc(m * sizeof(int *));
    for(int i=0;i<m;i++){
        altitudes[i] = (int *) malloc(n * sizeof(int));
        for(int j=0;j<n;j++){
            altitudes[i][j] = ((seed*(202+i+j)+12345+i+j)%256);
        }
    }
    return altitudes;
}

Bloco ***criarMundo(int m, int n, int **altitudes, int seed){
    Bloco ***mundo;
    mundo = malloc(m * sizeof(Bloco **));
    for(int i=0;i<m;i++){
        mundo[i] = malloc(n * sizeof(Bloco *));
        for(int j=0;j<n;j++){
            mundo[i][j] = malloc(256 * sizeof(Bloco));
            for(int k=0;k<256;k++){
                if(k>altitudes[i][j]){
                    mundo[i][j][k].tipo = 21;
                }
                else{
                    int bloco = ((seed*(202+i+j+k)+i+j+k)%33);
                    mundo[i][j][k].tipo = bloco;
                }
            }
        }
    }
    return mundo;
}

double explorarMundo(Bloco ***mundo, int m, int n, int **altitudes, double tempoPorBloco, int *qtdDiamante, int *qtdOuro, int *qtdFerro, int *qtdBlocos){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<256;k++){
                int bloco;
                if (k > altitudes[i][j]){
                    bloco = 21;
                }
                else{
                    bloco = mundo[i][j][k].tipo;
                }
                if(bloco==0) *qtdDiamante += 1;
                else if(bloco==1 || bloco==2) *qtdOuro += 1;
                else if(bloco >= 3 && bloco <= 5) *qtdFerro += 1;
                if(bloco < 21) *qtdBlocos += 1;
                }
            }
        }
    double ttempo = (*qtdBlocos)*(tempoPorBloco);
    printf("Total de Blocos: %d\nTempo total: %0.2lfs\nDiamantes: %d\nOuros: %d\nFerros: %d\n", *qtdBlocos, ttempo, *qtdDiamante, *qtdOuro, *qtdFerro);
    return ttempo;
}

int main(void){
    //Declarando variaveis
    Bloco ***mundo;
    int m, n, seed;
    double tempo;
    int **altitudes;

    //Atribuindo valores a elas
    scanf("%d %d", &m, &n);
    scanf("%d", &seed);
    scanf("%lf", &tempo);

    //Calcula altitudes e logo embaixo cada bloco
    altitudes = calcularAltitudes(m, n, seed);
    mundo = criarMundo(m, n, altitudes, seed);

    //Delcarando e apontando ponteiros
    int tot = 0, dimas = 0, ouros = 0, ferros = 0;
    int *qtdDiamante = &dimas;
    int *qtdOuro = &ouros;
    int *qtdFerro = &ferros;
    int *qtdBlocos = &tot;

    //explorando mundo
    explorarMundo(mundo, m, n, altitudes, tempo, qtdDiamante, qtdOuro, qtdFerro, qtdBlocos);
    
    //liberando memória
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            free(mundo[i][j]);
        }
        free(mundo[i]);
        free(altitudes[i]);
    }
    free(mundo);
    free(altitudes);
    return 0;
}