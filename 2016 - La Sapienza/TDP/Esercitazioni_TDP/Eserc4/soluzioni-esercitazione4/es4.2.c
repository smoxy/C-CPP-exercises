#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int i = 10;   
  int j = 20; 
  char *p, *q;  
  
  p = (char*)&i;
  q = (char*)&j;
  for(int k = 0; k < sizeof(i); ++k) {
    *(q + k) = *(p + k);    
  }
    
  printf("%d == %d\n", i, j); 
  
  return 0;
}
