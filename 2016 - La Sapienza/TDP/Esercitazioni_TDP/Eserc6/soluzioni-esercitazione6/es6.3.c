#include <stdio.h>

void stampaAsterischi(int n);

int main(int argc, char **argv) {
  float valore;
  scanf("%f", &valore);

  while(valore != 0.0) {
    stampaAsterischi(valore);
    scanf("%f", &valore);
  }
  
  return 0;
}

void stampaAsterischi(int n) {
  for(int i = 0; i < n; ++i) {
    printf("*");
  }
  printf("\n");
}
