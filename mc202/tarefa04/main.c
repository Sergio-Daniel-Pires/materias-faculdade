#include <stdio.h>
#include <string.h>
#include "planejar.h"

Voo voos[100];

Plano planovoo[3];

int main(void){
    int pos = 0;
    while(1){
        char op[15];
        scanf("%s", op);
        if ((strcmp(op, "registrar")==0)){
            scanf("%d", &voos[pos].nvoo);
            scanf("%s %s", voos[pos].ida, voos[pos].vinda);
            Data data_atual = ler_data();
            voos[pos].data.dia = data_atual.dia;
            voos[pos].data.mes = data_atual.mes;
            voos[pos].data.ano = data_atual.ano;
            scanf("%lf", &voos[pos].valor);
            pos += 1;
        }
        else if (strcmp(op, "alterar")==0){
            int num;
            double novo_valor;
            scanf("%d %lf", &num, &novo_valor);
            alterar(voos, pos, num, novo_valor);
        }
        else if (strcmp(op, "cancelar")==0){
            int num;
            scanf("%d", &num);
            cancelar(voos, pos, num);
        }
        else if(strcmp(op, "printa")==0){
            for(int i=0;i<pos;i++){
                printf("%d ", voos[i].nvoo);
            }printf("\n");
            for(int i=0;i<pos;i++){
                printf("%0.2lf ", voos[i].valor);
            }printf("\n");
        }
        else if(strcmp(op, "planejar")==0){
            scanf("%s", planovoo[0].ida);
            Data ida = ler_data(), vinda = ler_data();
            planovoo[0].dida.dia = ida.dia;
            planovoo[0].dida.mes = ida.mes;
            planovoo[0].dida.ano = ida.ano;
            planovoo[0].vinda.dia = vinda.dia;
            planovoo[0].vinda.mes = vinda.mes;
            planovoo[0].vinda.ano = vinda.ano;
            planejar(voos, pos, planovoo);
            break;
        }
    }
    return 0;
}