#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  unsigned char b = 'a';
  short s = 2;
  int i = 100;
  long l = 5000;
  float f = 2.5f;
  double d = 5.0;
  char c = 'j';

  printf("1) %ld\n", b + 10 * l);
  printf("2) %ld\n", (b + i) * l);
  printf("3) %f\n", (b + i) * l + f);
  printf("4) %lf\n", s / f + sin(d));
  printf("5) %d\n", c == 'b');
  printf("6) %f\n", l + 1.5f);
  printf("7) %d\n", i < 10);

  return 0;
}
