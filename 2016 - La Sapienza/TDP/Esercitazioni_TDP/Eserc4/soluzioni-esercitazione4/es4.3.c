#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int* num = (int*)malloc(sizeof(int)); 
  int* minimo = (int*)malloc(sizeof(int));

  *num = -1;
  while(*num < 0) {
    printf("Inserire un numero (0 per terminare): ");
    scanf("%d", num);
  }
  *minimo = *num;

  while(*num != 0) {
    printf("Inserire un numero (0 per terminare): ");
    scanf("%d", num);
    if(*num < *minimo && *num > 0) {
      *minimo = *num;
    }
  }

  if(*minimo > 0) {
    printf("Il numero minimo inserito e': %d\n", *minimo);
  }

  free(minimo);
  free(num);

  return 0;
} 
