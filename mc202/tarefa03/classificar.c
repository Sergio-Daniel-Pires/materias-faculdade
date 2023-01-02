#include <stdio.h>
#include <string.h>
#define MAXE 115
#define MAXC 30

void separa_nome(char nome[MAXC], char new[MAXC], int op);

void imprime(char matriz[MAXE][MAXC], int n){
    //Imprime cada string em uma linha
    for(int i=0;i<n;i++){
        char linha[MAXC];
        strcpy(linha, matriz[i]);
        if(strlen(linha)>3){
            printf("%s\n", linha);
        }
    }

}

void separa_nome(char nome[MAXC], char new[MAXC], int op){
    //Separa o nome para comparar e ver se é igual
    int atv = 1, pos;
    for(int i=0;i<MAXC;i++){
        if (nome[i]=='_'){
            if (op==1){
                new[i] = '\0';
                break;
            }
            else{
                atv = 2;
                pos = i;
            }
        }
        else{
            if(atv==1){
                new[i] = nome[i];
                }
            if(atv==2){
                new[i-pos-1] = nome[i];
            }
        }
    }
}

void cria_ordena_matriz(int n, char matriz[MAXE][MAXC]){
    //Cria uma matriz de char, onde cada linha é um nome
    for(int i=0;i<n;i++){
        char nome[MAXC];
        scanf("%s", nome);
        strcpy(matriz[i],nome);
    }
    char atual[MAXC];
    for(int i=0;i<MAXE;i++){
        for(int j=i+1;j<n;j++){
            int verf = strcmp(matriz[i], matriz[j]);
            if(verf > 0){
                strcpy(atual, matriz[i]);
                strcpy(matriz[i], matriz[j]);
                strcpy(matriz[j], atual);
            }
        }
    }
}

void acha_pares(char matriz[MAXE][MAXC], char matrizf[MAXE][MAXC], int n, int op){
    /*
    Separa os nomes, acha os pares, ordena e printa
    */
    int pos=0;
    for(int i=0;i<MAXE;i++){
        int atv = 0;
        char nomei[MAXC];
        pos += 1;
        strcpy(matrizf[pos], matriz[i]);
        separa_nome(matriz[i], nomei, op);
        for(int j=i+1;j<n;j++){
            char nomej[MAXC];
            separa_nome(matriz[j], nomej, op);
            if(strcmp(nomei, nomej)==0){
                strcpy(matrizf[pos+1], matriz[j]);
                strcpy(matriz[j],"\0");
                atv += 1;
                pos += 1;
            }
        }
        if (atv==0){
            strcpy(matrizf[pos],"\0");
        }
    }
    imprime(matrizf, pos);
}

int main(void)
//Roda o programa em ordem
{   
    int n, op;
    char matriz[MAXE][MAXC], matrizf[MAXE][MAXC], tipo[11];
    scanf("%d", &n);
    scanf("%s", tipo);
    if (strcmp(tipo, "homonimos")){
        op = 2;
    }
    else{
        op = 1;
    }
    cria_ordena_matriz(n, matriz);
    acha_pares(matriz, matrizf, n, op);
    return 0;
}