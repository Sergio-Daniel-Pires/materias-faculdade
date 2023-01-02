#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dns.h"

void aloca_Arvore(Arvore **atual_server, char DNS[100], char IP[16]){
    *atual_server = malloc(sizeof(Arvore));
    (*atual_server)->esq = NULL;
    (*atual_server)->dir = NULL;
    (*atual_server)->nivel = 0;
    (*atual_server)->acessos = 0;
    strcpy((*atual_server)->DNS, DNS);
    strcpy((*atual_server)->IP, IP);
}

void desaloca_arvore(Arvore **no_atual)
{
    //Libera recursivamente da memoria os nos
    if (*no_atual)
    {
        desaloca_arvore(&(*no_atual)->esq);
        desaloca_arvore(&(*no_atual)->dir);
        free(*no_atual);
    }
}

void calcNivel(Arvore **atual){
    int nivelesq, niveldir, nivel = 0;

    //Salva valores da esquerda e da direita
    if((*atual)->esq)
        nivelesq = (*atual)->esq->nivel;
    else
        nivelesq = -1;

    if((*atual)->dir)
        niveldir = (*atual)->dir->nivel;
    else
        niveldir = -1;

    //Verifica qual o nivel
    if(nivelesq == -1 && niveldir == -1)
        nivel = 0;
    else if(nivelesq > niveldir)
        nivel = nivelesq + 1;
    else
        nivel = niveldir + 1;

    (*atual)->nivel = nivel;
}

int nivel(Arvore **atual){
    if(*atual)
        return (*atual)->nivel;
    return -1;
}

void rotDir(Arvore **atual){
    Arvore *auxiliar;
    auxiliar = (*atual)->esq;
    (*atual)->esq = auxiliar->dir;
    auxiliar->dir = *atual;
    *atual = auxiliar;
}

void rotEsq(Arvore **atual){
    Arvore *auxiliar;
    auxiliar = (*atual)->dir;
    (*atual)->dir = auxiliar->esq;
    auxiliar->esq = *atual;
    *atual = auxiliar;
}

int calculafb(Arvore **atual){
    int fb;
    int nivelesq = nivel(&(*atual)->esq);
    int niveldir = nivel(&(*atual)->dir);
    fb = niveldir - nivelesq;
    return fb;
}

void balanceamento(Arvore **atual){
    //Verifica se esta desbalanceado
    int fb = calculafb(atual);
    
    //rotacao para direita
    if(fb == -2){
        //Verifica se precisa de rotacao dupla
        if(calculafb(&(*atual)->esq) == 1){
            rotEsq(&(*atual)->esq);
            rotDir(atual);
        }
        else
            rotDir(atual);
    }
    //rotacao para esquerda 
    else if(fb == 2){
        //Verifica se precisa de rotacao dupla
        if(calculafb(&(*atual)->dir) == -1){
            rotDir(&(*atual)->dir);
            rotEsq(atual);
        }
        else
            rotEsq(atual);
    }
}

void insere_server(Arvore **atual, char DNS[100], char IP[20], Arvore **no_atual){
    //Aqui para quando o web master quer alocar o servidor
    //Salvando nivel certo e verificando FB
    char atual_DNS[100];
    strcpy(atual_DNS, (*atual)->DNS);
    int comparacao = strcmp(atual_DNS, DNS);
    if(comparacao){
        if(comparacao > 0){
            if((*atual)->esq){
                insere_server(&(*atual)->esq, DNS, IP, no_atual);
            }
            else{
                aloca_Arvore(&(*atual)->esq, DNS, IP);
                *no_atual = (*atual)->esq;
            }
        }
        else{
            if((*atual)->dir){
                insere_server(&(*atual)->dir, DNS, IP, no_atual);
            }
            else{
                aloca_Arvore(&(*atual)->dir, DNS, IP);
                *no_atual = (*atual)->dir;
            }
        }
        calcNivel(atual);
        balanceamento(atual);
    }
    else
        *no_atual = *atual;
}

void acha_server(Arvore *atual, char DNS[100], Arvore **server_atual){
    if(atual){
        char atual_DNS[100];
        strcpy(atual_DNS, atual->DNS);
        if(strcmp(atual_DNS, DNS)){
            if(strcmp(atual_DNS, DNS) > 0){
                acha_server(atual->esq, DNS, server_atual);
            }
            else{
                acha_server(atual->dir, DNS, server_atual);
            }
        }
        else{
            *server_atual = atual;
        }
    }
    else{
        *server_atual = NULL;
    }
}