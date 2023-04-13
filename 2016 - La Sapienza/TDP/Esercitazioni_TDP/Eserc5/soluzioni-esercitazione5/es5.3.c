#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  void* data = (void*)malloc(sizeof(float) + sizeof(char)); 

  printf("Inserire la temperatura: ");
  scanf("%f", (float*)data);

  printf("Inserire la scala (K, C, F): ");
  scanf(" %c", (char*)data + sizeof(float));

  switch(*((char*)data + sizeof(float))) {
  case 'K':
    printf("C: %f\n", *((float*)data) - 273.15f);
    printf("F: %f\n", (*((float*)data) - 273.15f) * 9.0f / 5.0f + 32.0f);
    break;
  case 'C':
    printf("K: %f\n", *((float*)data) + 273.15f);
    printf("F: %f\n", *((float*)data) * 9.0f / 5.0f + 32.0f);
    break;
  case 'F':
    printf("K: %f\n", ((*((float*)data) - 32.0f) * 5.0f / 9.0f) + 273.15f);
    printf("C: %f\n", (*((float*)data) - 32.0f) * 5.0f / 9.0f);
    break;
  default:
    break;
  }

  free(data);

  return 0;
}
