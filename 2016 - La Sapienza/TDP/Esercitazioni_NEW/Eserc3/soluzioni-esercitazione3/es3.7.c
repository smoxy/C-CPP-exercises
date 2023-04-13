#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  for(int i = 0; i < 128; ++i) {    
    printf("%c ; %d\n", i, i);
  }
  printf("\n");

  return 0;
}
