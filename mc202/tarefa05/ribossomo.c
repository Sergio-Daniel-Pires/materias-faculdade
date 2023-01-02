#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 14

int main(void){
    char *vetor;
    char DNA[MAX], RNA[MAX], ivetor[MAX];
    int total;

    //Salva DNA e RNA
    scanf("%s", DNA);
    scanf("%s", RNA);

    //Faz o resto
    scanf("%d", &total);
    total += 1;
    //Aloca Vetor
    vetor = (char *)(malloc(total * sizeof(char)));

    //Salva str no vetor
    for(int i=0;i<total;i++){
        scanf("%c", &vetor[i]);
    }

    //Zera o ID
    for(int i=0;i<MAX;i++){
        ivetor[i] = 0;
    }

    //Verifica aparições:
    printf("ID: ");
    for(int i=0;i<total;i++){
        char letra = vetor[i];
        for(int j=0;j<MAX;j++){
            if(letra==DNA[j]){
                int vezes = ivetor[j];
                printf("\t%d", vezes);
                ivetor[j] += 1;
                break;
            }
        }
    }

    //printa o DNA
    printf("\nDNA:");
    for(int i=0;i<total;i++){
        printf("\t%c", vetor[i]);
    }
    printf("\n");
    
    //printa pra ficar bonito
    printf("    ");
    for(int i=0;i<total-1;i++){
        printf("\t|");
    }
    printf("\n");

    //printa RNA
    printf("RNA: ");
    for(int i=0;i<total;i++){
        char letra = vetor[i];
        for(int j=0;j<MAX;j++){
            if(letra==DNA[j]){
                printf("\t%c", RNA[j]);
                break;
            }
        }
    }
    printf("\n");

    //libera vetor
    free(vetor);

    return 0;
}