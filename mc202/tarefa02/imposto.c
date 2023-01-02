#include <stdio.h>
#define MAX 1000

void imprime(double matriz[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 15; j++)
            printf("%0.2lf ", matriz[i][j]);
        printf("\n");
    }
}
double impostomes(double n);
double impostoano(double n);
double imposto(double ent, double min, double max, double prct);

double imposto(double ent, double min, double max, double prct)
{
    double valor = 0;
    if (ent > min && ent < max)
    {
        valor = (ent - min) * prct;
    }
    else
    {
        if(ent > max){
            valor = (max-min) * prct;
        }
        else{
            valor = 0;
        }
    }
    return valor;
}

double impostomes(double n)
{
    double valor = 0;
    valor += imposto(n, 1499.15, 2246.75, 0.075);
    valor += imposto(n, 2246.75, 2995.70, 0.15);
    valor += imposto(n, 2995.70, 3743.19, 0.225);
    valor += imposto(n, 3743.19, n + 1, 0.275);
    return valor;
}

double impostoano(double n)
{
    double valor = 0;
    valor += imposto(n, 18000.00, 26400.00, 0.075);
    valor += imposto(n, 26400.00, 36000.00, 0.15);
    valor += imposto(n, 36000.00, 44400.00, 0.225);
    valor += imposto(n, 44400.00, n + 1, 0.275);
    return valor;
}

void criarmatrizes(double matriz[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        double ano = 0,totalano = 0;
        for (int j = 0; j < 12; j++)
        {
            double val, valf;
            scanf("%lf", &val);
            valf = impostomes(val);
            matriz[i][j] = valf;
            ano += valf;
            totalano += val;
        }
        matriz[i][12] = ano;
        matriz[i][15] = totalano;
        matriz[i][14] = 0;
    }
    for (int i = 0; i < n; i++){
        double val, totano, valanual, retido;
        scanf("%lf", &val);
        totano = matriz[i][15]-val;
        valanual = impostoano(totano);
        retido = matriz[i][12];
        matriz[i][13] = valanual;
        matriz[i][14] = valanual-retido;
    }
    printf("Jan	Fev	Mar	Abr	Mai	Jun	Jul	Ago	Set	Out	Nov	Dez	Retido	Devido	Ajuste\n");
    imprime(matriz, n);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    double matriz[MAX][MAX];
    criarmatrizes(matriz, n);
    return 0;
}