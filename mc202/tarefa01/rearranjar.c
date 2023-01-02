#include <stdio.h>

#define MAX 10000

void imprime(int vetor[], int n){
    for (int i = 0;i<n;i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void alt1(int b,int c,int n, int vetor[]){
  int ini = 0;
  int fim = 0;
  int vaux[MAX];
  for (int i=0;i<n;i++){
    if (vetor[i]==b){
      ini = i;
      }
    if (vetor[i]==c){
      fim = i;
      }
      vaux[i] = vetor[i];
    }
  for (int i=0;i<n;i++){
    if (ini <= i && i <= fim){
      vetor[i] = vaux[fim-i+ini];
      }
    }
  }

void alt2(int b,int c,int n, int vetor[]){
  int col = 0;
  int temp;
  if (b != c){
    for (int i=0;i<n;i++){
      if (vetor[i]==b && col==0){
        col = 1;
        temp = vetor[i];
      }
      if (col==1){
        vetor[i]=vetor[i+1];
        if (vetor[i+1]==c){
          vetor[i+1]=temp;
          col=2;
        }
      }
    }
  }
}


void criarVetor (int vetor[], int tam) {
  for (int i=0; i<tam; i++)
    vetor[i] = i+1;
  }

void alteracoes(int vetor[], int alt, int n){
    for (int i=0; i<alt; i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        if (a==1){
          alt1(b,c,n,vetor);
        }
        else{
          alt2(b,c,n,vetor);
        }  
    }
    imprime(vetor, n);
}

int main (void) {
  int n, vetor[MAX], alt;
  scanf("%d", &n);
  scanf("%d", &alt);
  criarVetor(vetor, n);
  alteracoes(vetor, alt, n);
  return 0;
  }
