#include <stdio.h>

int main (int argc,char**argv) {
  int n=0;
  int cont1=0;
  int cont2=0;
  printf("Inserisci dimensione lato:");
  scanf("%d", &n);
  while (cont1!=n) {
    while (cont2!=n) {
      printf("*");
      cont2++;
    }
    printf("\n");
    cont1++;
    cont2=0;
  }
  return 0;
}
