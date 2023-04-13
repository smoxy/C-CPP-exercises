#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int* data = (int*)malloc(2 * sizeof(int));

  *data = -1;
  while(*data < 0) {
    printf("Inserire un numero (0 per terminare): ");
    scanf("%d", data);
  }
  *(data + 1) = *data;

  while(*data != 0) {
    printf("Inserire un numero (0 per terminare): ");
    scanf("%d", data);
    if(*data < *(data + 1) && *data > 0) {
      *(data + 1) = *data;
    }
  }

  if(*(data + 1) > 0) {
    printf("Il numero minimo inserito e': %d\n", *(data + 1));
  }

  free(data);

  return 0;
} 
