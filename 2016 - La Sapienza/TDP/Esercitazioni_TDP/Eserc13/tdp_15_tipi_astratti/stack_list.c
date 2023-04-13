#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "list_functions.h"

struct Stack{
  ListElem* top_element;
  int size;
};

Stack* Stack_create() {
  Stack* s=(Stack*) malloc (sizeof (Stack));
  s->size=0;
  s->top_element=NULL;
  return s;
}

void Stack_destroy(Stack* s){
  while(s->top_element){
    s->top_element=List_popFront(s->top_element);
  }
  free (s);
}

stack_info_type Stack_top(Stack* stack) {
  assert(Stack_size(stack));
  return stack->top_element->info;
}

void Stack_pop(Stack* stack){
  assert(Stack_size(stack));
  stack->top_element=List_popFront(stack->top_element);
  stack->size--;
}

void Stack_push(Stack* stack, stack_info_type info){
  stack->top_element=List_pushFront(stack->top_element, info);
  stack->size++;
}

int Stack_size(Stack* stack){
  return stack->size;
}
