#include <stdio.h>
#include <string.h>
#include "planejar.h"
#define MAX 100


Data ler_data(){
    Data data;
    scanf("%d/%d/%d", &(data.dia), &(data.mes), &(data.ano));
    return data;
}

void cancelar(Voo voos[], int qtd_voos, int numero_voo){
    for(int i=0;i<qtd_voos;i++){
        if(voos[i].nvoo == numero_voo){
            voos[i].nvoo = 0;
        }
    }
}

void alterar(Voo voos[], int qtd_voos, int numero_voo, float novo_valor){
    for(int i=0;i<qtd_voos;i++){
        if(voos[i].nvoo == numero_voo){
            voos[i].valor = novo_valor;
        }
    }
}

int compara_data(Data data1, Data data2){
    int verf = 0;
    if (data2.ano > data1.ano || (data2.ano == data1.ano && (data2.mes > data1.mes || (data2.mes == data1.mes && data2.dia >= data1.dia)))){
        verf = 1;
    }
    return verf; 
}

void planejar(Voo voos[], int qtd_voos, Plano planejar[]){
    char partida[4];
    Atual planejado[1];
    planejado[0].valor = 1000000000;
    strcpy(partida, planejar[0].ida);
    for(int i=0;i<qtd_voos;i++){
        if (voos[i].nvoo != 0){
            if (strcmp(partida, voos[i].ida)==0 && compara_data(planejar[0].dida, voos[i].data)==1){
                for(int j=0;j<qtd_voos;j++){
                    if (voos[j].nvoo != 0){
                        double valor_atual = 0;
                        valor_atual = voos[i].valor + voos[j].valor;
                        if((strcmp(voos[j].ida, voos[i].vinda)==0) && (strcmp(voos[j].vinda, voos[i].ida)==0) && compara_data(voos[j].data, planejar[0].vinda)){
                            int dias = diferenca_data(voos[i].data, voos[j].data);
                            if (dias >= 3 && valor_atual < planejado[0].valor){
                                planejado[0].valor = valor_atual;
                                planejado[0].numv = voos[j].nvoo;
                                planejado[0].numi = voos[i].nvoo;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n%d\n", planejado[0].numi, planejado[0].numv);
}

int diferenca_data(Data data1, Data data2){
    int dias;
    int datafinal = dataemdia(data2);
    int datainicial = dataemdia(data1);
    dias = datafinal-datainicial;
    return dias;
}

int dataemdia(Data data){
    int dias = 1;
    dias += (data.ano-1)*365;
    for(int i=1;i<data.mes;i++){
        if (i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12){
            dias += 31;
        }
        else if (i==2){
            dias += 28;
        }
        else{
            dias += 30;
        }
    }
    dias += data.dia;
    return dias;
}