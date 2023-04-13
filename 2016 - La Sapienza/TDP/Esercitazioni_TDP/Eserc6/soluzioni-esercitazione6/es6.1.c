#include <stdio.h>

void scambia(int *a, int *b);

int main(int argc, char **argv) {
  int x;
  printf("Inserire un intero: ");
  scanf("%d", &x);

  int y;
  printf("Inserire un altro intero: ");
  scanf("%d", &y);

  printf("Contenuto di x e y prima dello scambio: %d, %d\n", x, y);

  scambia(&x, &y);

  printf("Contenuto di x e y dopo lo scambio: %d, %d\n", x, y);

  return 0;
}

void scambia(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
