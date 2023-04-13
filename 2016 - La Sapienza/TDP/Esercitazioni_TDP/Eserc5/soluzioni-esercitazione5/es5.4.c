#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  void* data = (void*)malloc(2 * sizeof(float) + sizeof(int));

  printf("Inserire un numero (0.0 per terminare): ");
  scanf("%f", (float*)data);

  while(*((float*)data) != 0.0) {
    (*(int*)((char*)data + 2 * sizeof(float)))++;
    *((float*)data + 1) += *((float*)data);    
    printf("Inserire un numero (0.0 per terminare): ");
    scanf("%f", (float*)data);
  }

  if(*(int*)((char*)data + 2 * sizeof(float)) != 0) {
    printf("La media aritmetica dei numeri inseriti e': %f\n", 
	   *((float*)data + 1) / (float)(*(int*)((char*)data + 2 * sizeof(float))));
  }

  free(data);

  return 0;
}
