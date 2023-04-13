#include <stdio.h>

int main (int argc,char**argv) {
  int n=0;
  int cont1=0;
  int cont2=0;
  int lines=0;
  int final=0;
  printf("Inserisci dimensione lato:");
  scanf("%d", &n);
  lines=n-2;
  final=n-1;
  while (cont2!=n) {
    printf("*");
    cont2++;
  }
  printf("\n");
  cont2=0;
  while (cont1!=lines) {
    while (cont2!=n) {
      if (cont2==0) {
	printf("*");
	cont2++;
      }
      else if (cont2==final){
	printf("*");
	cont2++;
      }
      else {
	printf(" ");
	cont2++;
      }
    }
    printf("\n");
    cont1++;
    cont2=0;
  }
  while (cont2!=n) {
    printf("*");
    cont2++;
  }
  printf("\n");
  cont2=0;
  return 0;
}
