#include "stack.h"
#include <stdlib.h>
#include <assert.h>

const int StackDefaultCapacity=1024;

struct Stack {
  stack_info_type* data;
  int capacity; 
  int size;
};


Stack* Stack_create(){
  Stack* s=(Stack*) malloc(sizeof(Stack));
  s->data=(stack_info_type*)
    malloc(StackDefaultCapacity*sizeof(stack_info_type));
  s->capacity=StackDefaultCapacity;
  s->size=0;
  return s;
}

void Stack_destroy(Stack* stack){
  free(stack->data);
  free(stack);
}

stack_info_type Stack_top(Stack* stack){
  assert(stack->size);
  return  stack->data[stack->size-1];
}

void Stack_pop(Stack* stack) {
  assert(stack->size);
  stack->size--;
}

void Stack_push(Stack* stack, stack_info_type info) {
  assert(stack->size<stack->capacity);
  stack->data[stack->size]=info;
  stack->size++;
}

int Stack_size(Stack* stack){
  return stack->size;
}
