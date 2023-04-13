#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  char c;
  short s;
  int i;
  long l;
  float f;
  double d;

  printf("char   -> indirizzo %p, dimensione %ld byte\n", &c, sizeof(c));
  printf("short  -> indirizzo %p, dimensione %ld byte\n", &s, sizeof(s));
  printf("int    -> indirizzo %p, dimensione %ld byte\n", &i, sizeof(i));
  printf("long   -> indirizzo %p, dimensione %ld byte\n", &l, sizeof(l));
  printf("float  -> indirizzo %p, dimensione %ld byte\n", &f, sizeof(f));
  printf("double -> indirizzo %p, dimensione %ld byte\n", &d, sizeof(d));

  return 0;
}
