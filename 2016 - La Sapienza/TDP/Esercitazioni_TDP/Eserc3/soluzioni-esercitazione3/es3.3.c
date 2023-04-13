#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  float d;
  printf("Inserire il raggio del cerchio: ");
  scanf("%d", &d);

  if(d < 1) {
    printf("Il raggio deve essere un intero strettamente positivo!\n");
    return -1;
  }

  int dd =d * d;
  for(int r = -d; r <= d; ++r) {
    int rr = r * r;
    for(int c = -d; c <= d; ++c) {
      int cc = c * c;
      int interno = rr + cc <= dd;
      if(interno) {
	printf("*");
      } 
      else {
	printf("-");
      }
    }
    printf("\n");
  }

  return 0;
} 
