#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printa(int **matriz, int n);
int verfLinCol(int **matriz, int x, int y, int n);

int linha(int **matriz, int lin, int pos, int n){
    /*
    Puxa cada elemento de uma linha e soma+1, caso
    passe na verificação, verifica se as próximas
    casas vão passar também, caso uma não passe
    volta a essa primeira casa
    */
    int verf = 1;
    int num = matriz[lin][pos];
    if (pos == 1 && lin > n){
        return 0;
    }
    for(int i=num+1;i<=n+1;i++){
        matriz[lin][pos] = i;
        num = matriz[lin][pos];
        verf = verfLinCol(matriz, pos, lin, n);
        int pos1, lin1;
        if (pos < n){
            pos1 = pos+1;
            lin1 = lin; 
        }
        else{
            pos1 = 1;
            lin1 = lin+1; 
        }
        if(verf==0 && linha(matriz, lin1, pos1, n)==0){
            return 0;
        }
        if(num==n+1){
            matriz[lin][pos] = 0;
            return 1;
        }
    }
    return verfLinCol(matriz, pos, lin, n);
}

int verfLinCol(int **matriz, int x, int y, int n){
    /*
    Verifica cada linha e cada coluna (de frente para trás
    e vice-versa), melhor explicado como em cada 'for'
    */
    int num = matriz[y][x];
    if (num==n+1 || num==0){
        return 1;
    }
    //Se achar algo retorna 1
    //Achou nada retona 0
    int retorno = 0;

    //verifica linha E->D
    int maxl, contl = 0, maiorl = 0;
    maxl = matriz[y][0];
    for(int i=1;i < n+1;i++){
        if (matriz[y][i] > maiorl){
            //Faz a contagem dos arranhaceis vistos
            maiorl = matriz[y][i];
            contl++;
        }
        if (matriz[y][i] == num && i!=x){
            //Verifica se há elementos iguais
            retorno = 1;
        }
    }
    if(contl > maxl){
        //Se a contgem for maior do que deveria, retorna 1
        retorno = 1;
    }

    //verifica linha D->E
    int maxlI, contlI = 0, maiorlI = 0;
    maxlI = matriz[y][n+1];
    for(int i=n;i > 0;i--){
        if (matriz[y][i] > maiorlI){
            //Faz a contagem dos arranhaceis vistos
            maiorlI = matriz[y][i];
            contlI++;
        }
        if (matriz[y][i] == num && i!=x){
            //Verifica se há elementos iguais
            retorno = 1;
        }
    }
    if(contlI > maxlI && x==n){
        retorno = 1;
    }

    //verf coluna C->B
    int maxc, contc, maiorc;
    maxc = matriz[0][x];
    contc = 0, maiorc = 0;
    int zeroc = 0;
        for(int i=1;i < n+1;i++){
            //Verifica a contagem de arranhaceis e repeticoes de numeros
            //Porém, só retorna algo se a linha estiver toda ocupada
            if (matriz[i][x]==0){
                zeroc = 1;
            }
            if (matriz[i][x] > maiorc){
                maiorc = matriz[i][x];
                contc++;
            }
            if (matriz[i][x] == num && i!=y){
                retorno = 1;
            }
        }
    if(contc > maxc && zeroc == 0){
        retorno = 1;
    }

    //verf coluna B->C
    int maxcI, contcI, maiorcI;
    maxcI = matriz[n+1][x];
    contcI = 0, maiorcI = 0;
    int zerocI = 0;
    for(int i=n;i > 0;i--){
        //Verifica a contagem de arranhaceis e repeticoes de numeros
        //Porém, só retorna algo se a linha estiver toda ocupada
        if (matriz[i][x]==0){
            zerocI = 1;
        }
        if (matriz[i][x] > maiorcI){
            maiorcI = matriz[i][x];
            contcI++;
        }
        if (matriz[i][x] == num && i!=y){
            retorno = 1;
        }
    }
    if(contcI > maxcI && zerocI == 0){
        retorno = 1;
    }

    //Verificacoes finais de linha
    //Caso as linhas estajam completas e as verificações
    //Não estejam corretas, retorna erro "1"
    if(contl < maxl && retorno == 0 && x == n){
        return 1;
    }
    if(contlI < maxlI && retorno == 0 && x == n){
        return 1;
    }
    if(contc < maxc && retorno == 0 && zeroc == 0 && y == n){
        return 1;
    }
    if(contcI < maxcI && retorno == 0 && zerocI == 0){
        return 1;
    }
    return retorno;
}

void printa(int **matriz, int n){
    //printa a matriz usando 2 for's
    for(int i=1;i < n+1;i++){
        for(int j=1;j < n+1;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void libera(int **matriz, int n){
    //libera os espaços alocados
    for(int i=0;i < n+2;i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main(void){
    int n, **matriz, num;
    scanf("%d", &n);
    
    //Aqui aloca memória
    matriz = (int **)malloc(sizeof(int *)*(n+2));
    for(int i=0;i < n+2;i++){
        matriz[i] = (int *)malloc(sizeof(int)*(n+2));
        for(int j=0;j < n+2;j++){
            scanf("%d", &num);
            matriz[i][j] = num;
        }
    }
    linha(matriz, 1, 1, n);
    printa(matriz, n);
    libera(matriz, n);
    return 0;
}