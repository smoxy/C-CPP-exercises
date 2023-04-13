#include <stdio.h>

void FloydTriangle(int N){
  for (int i=1;i<=N;i+=1){
    int cont=0;
    while (cont!=i){
      printf("*");
      cont+=1;
    }
    printf("\n");
  }
}

int main(int argc,char**argv){
  int N;
  printf("Inserisci base triangolo: ");
  scanf("%d",&N);
  FloydTriangle(N);
}
