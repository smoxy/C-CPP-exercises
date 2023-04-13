#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  float d;
  printf("Inserire il raggio del cerchio: ");
  scanf("%f", &d);

  if(d < 1) {
    printf("Il raggio deve essere un intero strettamente positivo!\n");
    return -1;
  }

  int dd =d * d;
  //printf("\n\tdd = %d\td = %.2f", dd, d);
  for(int r = -d; r <= d; ++r) {
    int rr = r * r;
    //printf("\n\trr = %d\tr = %d\n", rr, r);
    for(int c = -d; c <= d; ++c) {
      int cc = c * c;
      //printf("\n\tcc = %d\tc = %d", cc, c);
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
