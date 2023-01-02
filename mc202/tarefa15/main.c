#include "nuvem.h"

int main(void){
    //Declaracao de variaveis
    int max_de_palavras, num_de_stops;
    Hash_cel *hashs;
    Fila *fila;
    char palavra[MAX];

    //Entrada inicial para atribuir a variaveis
    scanf("%d\n", &max_de_palavras);
    scanf("%d", &num_de_stops);
    hashs = (Hash_cel *)malloc(max_de_palavras * sizeof(Hash_cel));
    fila = NULL;

    for (int i = 0; i < num_de_stops; i++){
        /*
        Salva as Stop Words dentro do hash
        */
        scanf(" %s", palavra);
        int indice = hash(palavra);
        int pos = 0;

        //Verifica se há colisões
        for (int i = 0; i < 20; i++){
            if (hashs[indice].palavras[i].vezes == 0 || strcmp(hashs[indice].palavras[i].palavra, palavra) == 0){
                pos = i;
                break;
            }
        }
        strcpy(hashs[indice].palavras[pos].palavra, palavra);
        hashs[indice].palavras[pos].stop = true;
        hashs[indice].palavras[pos].vezes = 1;
    }

    char palavra_bruta[50];
    while (scanf("%s ", palavra_bruta) != EOF){
        char palavra_nova[50];
        int naotemnumero = true;
        normalizastr(palavra_bruta, palavra_nova, &naotemnumero);

        //Aqui verifica o indice
        if (naotemnumero){
            int indice;
            indice = hash(palavra_nova);
            int pos = 0;

            //Verifica se há colisões
            for (int i = 0; i < 20; i++){
                if (hashs[indice].palavras[i].vezes == 0 || strcmp(hashs[indice].palavras[i].palavra, palavra_nova) == 0){
                    pos = i;
                    break;
                }
            }
            //Verifica se palavra é uma stop word e se ela ja esta no hash
            //Caso não estiver, salva ela
            //caso esteja, incrementa '1' nas vezes
            if (hashs[indice].palavras[pos].stop != true){
                if (hashs[indice].palavras[pos].vezes == 0 && strlen(palavra_nova) > 1){
                    strcpy(hashs[indice].palavras[pos].palavra, palavra_nova);
                    hashs[indice].palavras[pos].vezes = 1;
                    hashs[indice].palavras[pos].stop = false;
                    hashs[indice].palavras[pos].hash = indice;
                    enfileira(&fila, &hashs[indice].palavras[pos]);
                }
                else{
                    hashs[indice].palavras[pos].vezes++;
                }
            }
        }
    }

    //Deixa na ordem certa para imprimir e ja vai liberando
    quicksort(&fila);
    int impressos = 0;
    while(fila){
        if(impressos < MAX){
            printf("%s %d\n", fila->atual->palavra, fila->atual->vezes);
            impressos++;
        }
        Fila *liberar = fila;
        fila = fila->ant;
        free(liberar);
    }
    free(fila);
    free(hashs);

    return 0;
}