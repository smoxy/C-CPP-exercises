#include <stdio.h>
#include <math.h>

int risolviEquazione(float *x1, float *x2, float a, float b, float c);

int main(int argc, char **argv) {
  float a, b, c;
  printf("Inserire il coefficiente a dell'equzione di secondo grado: ");
  scanf("%f", &a);
  if(a == 0) {
    printf("Il coefficiente a dell-equazione deve essere diverso da zero.\n");
    return -1;
  }
  printf("Inserire il coefficiente b dell'equzione di secondo grado: ");
  scanf("%f", &b);
  printf("Inserire il coefficiente c dell'equzione di secondo grado: ");
  scanf("%f", &c);

  int risultato;
  float x1, x2;
  risultato = risolviEquazione(&x1, &x2, a, b, c);

  if(risultato > 0) {
    printf("Le soluzioni dell'equazione sono: %f, %f.\n", x1, x2);
  }
  else if(risultato == 0) {
    printf("L'equazione ha un'unica soluzione: %f.\n", x1);
  }
  else {
    printf("L'equazione non ha soluzioni reali.\n");
  }

  return 0;
}

int risolviEquazione(float *x1, float *x2, float a, float b, float c) {
  float delta = b * b - 4.0f * a * c;
  if(delta > 0) {
    *x1 = (b + sqrtf(delta)) / (2.0f * a);
    *x2 = (b - sqrtf(delta)) / (2.0f * a);
    return 1;
  }
  else if(delta < 0) {
    return -1;
  }
  else {
    *x1 = b / (2.0f * a);
    *x2 = *x1;
    return 0;
  }
}
