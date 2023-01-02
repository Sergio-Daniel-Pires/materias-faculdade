#include <stdio.h>
#include <stdlib.h>

typedef struct amigo{
    int id;
    int inicio;
    struct amigo *prox;
    struct amigo *antes;
} Amigo;


void cria_lista(Amigo *ini, Amigo *aux, int m);
Amigo *aloca();

Amigo *aloca(){
    return malloc(sizeof(Amigo));
}
 
void printa(Amigo *aux, Amigo *ini){
    /*
    Printa em ordem crescente os dois times, 
    para isso, ele utiliza um while sempre
    verdadeiro que enquanto todos os ID's
    não forem iguais a 300 (altura max) não para.
    */
    Amigo *maior = ini;
    aux = ini->prox;
    while(1){
        if (maior->id > aux->id && aux->id != 300){
            maior = aux;
        }
        if(aux->prox == NULL){
            if (maior->id != 300){
                printf("%d ", maior->id);
                maior->id = 300;
                aux = ini;
            }
            else{
                printf("\n");
                break;
            }
        }
        else{
            aux = aux->prox;
        }
    }
}

void cria_lista(Amigo *ini, Amigo *aux, int m){
    /*
    Cria novas structs do tipo 'amigo' apontando
    para suas respectivas proximas e anteriores
    */
    Amigo *nova;
    for(int i=0;i<m-1;i++){
        //salva id na nova
        int id;
        scanf("%d", &id);
        nova = aloca();
        nova->id = id;
        //Faz a anterior apontar pra nova
        //E essa nova apontar para aux (anterior)
        nova->antes = aux;
        nova->prox = NULL;
        nova->inicio = 0;
        aux->prox = nova;

        //Aux atualiza para começar ciclo tudo dnv
        aux = nova;
    }
    
    //Isso deixa a lista circular
    aux->prox = ini;
    ini->antes = aux;
}

void decide_times(Amigo *aux, Amigo *ini, Amigo *aux1, Amigo *ini1, Amigo *aux2, Amigo *ini2, int m){
    Amigo *novo;

    aux = ini;
    for(int i=0; i<m; i++){
        int atual;
        scanf("%d", &atual);

        //Verifica se tem que ir pro proximo ou anterior
        if(i%2 != 0){
            int j = 0;
            while(j < atual-1){
                aux = aux->prox;
                if (aux->id != 0){
                    j++;
                }
            }
            novo = aloca();
            novo->id = aux->id;
            aux1->prox = novo;
            novo->prox = NULL;
            aux->id = 0;
            aux1 = novo;
        }
        else{
            int j = 0;
            while(j < atual-1){
                aux = aux->antes;
                if (aux->id != 0){
                    j++;
                }
            }
            novo = aloca();
            novo->id = aux->id;
            aux2->prox = novo;
            novo->prox = NULL;
            aux->id = 0;
            aux2 = novo;
        }
        //Verifica se o inicio precisa ser deslocado para direita
        if(ini->id == 0){
            ini = ini->prox;
            while(ini->id == 0){
                if (ini->inicio == 1){
                    break;
                }
                ini = ini->prox;
            }
        }
        aux = ini;
        
    }
}

int main(void){
    Amigo *ini, *aux;

    ini = aloca();
    ini->prox = NULL;
    ini->antes = NULL;

    //Registrar lista
    int m;
    scanf("%d", &m);

    //Salvando primeiro no inicio e aux aponta pra ini
    int id_ini;
    scanf("%d", &id_ini);
    ini->id = id_ini;
    aux = ini;

    cria_lista(ini, aux, m);

    /*
    auxiliares pro time 1 e 2 e inicios diferentes
    Dessa vez o começo vai ser definido, para evitar
    repetição e dificuldades (pra mim) 
    */
    Amigo *aux1, *ini1, *aux2, *ini2;

    ini1 = aloca();
    ini2 = aloca();

    aux1 = ini1;
    ini1->id = 300;
    ini1->prox = NULL;

    aux2 = ini2;
    ini2->id = 300;
    ini2->prox = NULL;

    ini->inicio = 1;

    decide_times(aux, ini, aux1, ini1, aux2, ini2, m);

    //Maior pro menor da 

    printa(aux2, ini2);
    printa(aux1, ini1);


    //Libera as duas saidas e a lista encadeada duplamente ligada
    while (aux2 != NULL){
        Amigo *delete = aux2;
        aux2 = aux2->prox;
        free(delete);
    }
    while (aux1 != NULL){
        Amigo *delete = aux1;
        aux1 = aux1->prox;
        free(delete);
    }
    ini = ini->prox;
    while(ini->id == 0){
        if (ini->inicio == 1){
            break;
        }
        Amigo *delete = ini;
        ini = ini->prox;
        free(delete);
    }
    free(ini);

    return 0;
}