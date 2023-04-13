#pragma once

typedef int stack_info_type;
struct Stack;

Stack* Stack_create();

void Stack_destroy(Stack* stack);

stack_info_type Stack_top(Stack* stack);

void Stack_pop(Stack* stack);

void Stack_push(Stack* stack, stack_info_type info);

int Stack_size(Stack* stack);
