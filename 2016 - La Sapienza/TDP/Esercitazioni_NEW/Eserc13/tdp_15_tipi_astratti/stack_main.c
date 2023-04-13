#include "stack.h"
#include <stdio.h>

int main(int argc, char** argv){
  Stack* s=Stack_create();
  for (int i=0; i<10; i++){
    Stack_push(s, i);
  }

  while(Stack_size(s)){
    int x=Stack_top(s);
    printf("%d\n",x);
    Stack_pop(s);
  }
}
