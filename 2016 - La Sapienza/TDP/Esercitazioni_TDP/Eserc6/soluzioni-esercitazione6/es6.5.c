#include <stdio.h>
#include <stdlib.h>

int* allocaEdInizializza(int n, int valore);

int main(int argc, char **argv) {
  int n, valore;
  printf("Inserire il numero di interi che la zona di memoria deve contenere: ");
  scanf("%d", &n);
  printf("Inserire il valore con cui inizializzare l'area di memoria: ");
  scanf("%d", &valore);

  int *data = allocaEdInizializza(n, valore);

  for(int i = 0; i < n; ++i) {
    printf("%d ", data[i]);
  }
  printf("\n");

  free(data);

  return 0;
}

int* allocaEdInizializza(int n, int valore) {
  int *data = (int*)malloc(n * sizeof(int));
  for(int i = 0; i < n; ++i) {
    data[i] = valore;
  }
  return data;
}
