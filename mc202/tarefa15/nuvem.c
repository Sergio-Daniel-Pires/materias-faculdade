
#include "nuvem.h"

int hash(char *chave){
    /*
    Função simples para transformar string em hash
    */
    int h = 0;
    for (int i = 0; chave[i] != '\0'; i++)
        h = (h * 256 + chave[i]) % primo;
    return h;
}

void enfileira(Fila **fila, Lista_palavras *atual){
    /*
    Adiciona uma palavra nova na fila de palavras
    */
    Fila *novo = malloc(sizeof(Fila));
    novo->atual = atual;
    novo->ant = (*fila);
    novo->prox = NULL;
    if ((*fila))
    {
        (*fila)->prox = novo;
    }
    (*fila) = novo;
}

void quicksort(Fila **fila){
    /*
    Algoritmo padrao de quick sort para ordernar
    com a diferença que também ordena em ordem alfabética
    */
    Fila *maior, *menor;
    maior = (*fila);
    while (maior)
    {
        menor = maior->ant;
        while (menor)
        {
            if (maior->atual->vezes < menor->atual->vezes || (maior->atual->vezes == menor->atual->vezes && strcmp(maior->atual->palavra, menor->atual->palavra) > 0))
            {
                Lista_palavras *auxiliar = maior->atual;
                maior->atual = menor->atual;
                menor->atual = auxiliar;
            }
            menor = menor->ant;
        }
        maior = maior->ant;
    }
}

void normalizastr(char *str_bruta, char *str_nova, int *naotemnumero){
    /*
    Função serve para normalizar as palavras, tirando os caracteres especiais,
    juntando as palavras após retirar e copiando para a nova variavel.
    retorna também se havia numeros na string
    */

    //Aqui trata a palavra
    int pos_bruta = 0;
    int pos_nova = 0;
    while (1)
    {
        //Caso de parada
        if (str_bruta[pos_bruta] == '\0')
        {
            str_nova[pos_nova] = '\0';
            break;
        }
        if (isdigit(str_bruta[pos_bruta]))
        {
            *naotemnumero = false;
            break;
        }
        //verifica se esta em uppercase
        if (isupper(str_bruta[pos_bruta]))
        {
            str_nova[pos_nova] = tolower(str_bruta[pos_bruta]);
            pos_bruta++;
            pos_nova++;
        }

        //verifica se tem ponto
        else if (ispunct(str_bruta[pos_bruta]))
            pos_bruta++;

        else
        {
            str_nova[pos_nova] = str_bruta[pos_bruta];
            pos_bruta++;
            pos_nova++;
        }
    }
}