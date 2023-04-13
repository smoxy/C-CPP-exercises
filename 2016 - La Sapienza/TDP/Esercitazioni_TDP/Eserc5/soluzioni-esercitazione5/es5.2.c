#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  float* data = (float*)malloc(2 * sizeof(float));
  
  printf("Inserire un numero: ");
  scanf("%f", data);

  if(*data < 0.0) {
    printf("Il numero non deve essere negativo!\n");
    return -1;
  }

  *(data + 1) = *data;
  for(int i = 0; i < 10; ++i) {
    *(data + 1) = (*(data + 1) + (*data) / (*(data + 1))) / 2.0f;
  }

  printf("La radice di %f e': %f\n", *data, *(data + 1));

  free(data);

  return 0;
}
