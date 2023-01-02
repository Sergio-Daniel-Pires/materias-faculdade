#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dns.h"

int main(void){
    //Inicializando valores
    /*
    u = maximo de consultas
    n = numero de DNS's conhecidos
    m = consultas que vão ser feitas
    */
    char DNS[100], IP[16];
    int u, n, m;
    Arvore *topo_server;
    Arvore *topo_client, *no_atual;

    //Salva valores iniciais
    scanf("%d", &u);
    scanf("%d", &n);

    //Salva os servidores
    for(int qtd_servers = 0; qtd_servers < n; qtd_servers++){
        //Aqui vai salvar cada servidor que possui um DNS salvo
        scanf("%s %s", DNS, IP);
        if(qtd_servers){
            insere_server(&topo_server, DNS, IP, &no_atual);
        }
        else{
            aloca_Arvore(&topo_server, DNS, IP);
        }
    }

    scanf("%d", &m);
    for(int qtd_client = 0; qtd_client < m; qtd_client++){
        char GET[4];
        char FROM[4];
        scanf("%s %s %s %s", GET, DNS, FROM, IP);
        
        //Aqui acha quem ta requisitando o cliente
        if(qtd_client){
            insere_server(&topo_client, IP, "\0", &no_atual);
        }
        else{
            aloca_Arvore(&topo_client, IP, "\0");
            no_atual = topo_client;
        }
        //Aqui verifica se ele pode fazer requisições
        //Caso possa, tenta realizar a conexao
        //Se conseguir, adiciona +1 nos acessos
        if(no_atual->acessos >= u){
            printf("FORBIDDEN %s FROM %s\n", DNS, IP);
        }
        else{
            Arvore *atual_server;
            //Acha o servidor requisitado
            acha_server(topo_server, DNS, &atual_server);
            //Caso chege no final e não for o certo, retorna NOTFOUND
            if(atual_server){
                printf("ACCEPTED %s FROM %s RESPOND %s\n", DNS, IP, atual_server->IP);
            }
            else{
                printf("NOTFOUND %s FROM %s\n", DNS, IP);
            }
            no_atual->acessos += 1;
        }
    }

    //Libera memoria
    desaloca_arvore(&topo_server);
    desaloca_arvore(&topo_client);
    return 0;
}