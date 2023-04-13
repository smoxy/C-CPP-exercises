#include <stdio.h>

void stampaRigaAsterischi(int n, int fill);

int main(int argc, char **argv) {
  int dim;
  printf("Inserire la dimensione del quadrato di asterischi: ");
  scanf("%d", &dim);

  for(int r = 0; r < dim; ++r) {
    if(r == 0 || r == dim - 1) {
      stampaRigaAsterischi(dim, 1);
    }
    else {
      stampaRigaAsterischi(dim, 0);
    }
  }
  
  return 0;
}

void stampaRigaAsterischi(int n, int fill) {
  for(int i = 0; i < n; ++i) {
    if(fill) {
      printf("*");
    }
    else {
      if(i == 0 || i == n - 1) {
	printf("*");
      }
      else {
	printf(" ");
      }
    }
  }
  printf("\n");
}
