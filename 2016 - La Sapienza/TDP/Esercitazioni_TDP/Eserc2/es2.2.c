#include <stdio.h>

int main (int argc,char**argv) {
  int a=1;
  int s=0;
  int n=0;
  while (a!=0) {
    printf("Inserisci un numero:");
    scanf("%d", &a);
    s=s+a;
    n++;
  }
  
  n=n-1;
  s=s/n;
  printf("La media aritmetica è %d\n", s);
  return 0;
}
