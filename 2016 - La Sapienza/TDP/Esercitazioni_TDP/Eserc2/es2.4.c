#include <stdio.h>

int main (int argc,char**argv) {
  int a=1; //primo numero della serie di Fibonacci
  int b=1; //secondo numero della serie di Fibonacci
  long z=0; //Numero attuale della serie di Fibonacci
  int c=0; //Contatore dei numeri visualizzati
  int n=0; //Quantità di numeri della serie di Fibonacci da visualizzare
  printf("Inserisci un numero intero: ");
  scanf("%d", &n);
  printf("Ora stamperò i primi %d numeri della serie di Fibonacci\n", n);
  while (c <= 1) {
    printf("\t1");
    c++;
  }
  while (c != n) {
    z = b+a;
    printf("\t%lu", z);
    b = a;
    a = z;
    c++;
  }
  printf("\n");
  return 0;
}
