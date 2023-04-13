#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int n1;
  printf("Inserire un primo numero positivo intero: ");
  scanf("%d", &n1);

  int n2;
  printf("Inserire un secondo numero positivo intero: ");
  scanf("%d", &n2);

  int mcm = 1;
  for(int i = 1; i <= n1 && i <= n2; ++i) {
    if(n1 % i == 0 && n2 % i == 0) {
      mcm = i;
    }
  }
  printf("Il minimo comune multiplo e': %d\n", mcm);

  return 0;
}
