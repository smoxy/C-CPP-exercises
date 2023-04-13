#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  float x;
  printf("Inserire un numero: ");
  scanf("%f", &x);

  if(x < 0.0) {
    printf("Il numero non deve essere negativo!\n");
    return -1;
  }

  int n = 10;
  float radice = x;
  for(int i = 0; i < n; ++i) {
    radice = (radice + x / radice) / 2.0f;
  }

  printf("La radice di %.2f e': %.2f\n", x, radice);

  return 0;
}
