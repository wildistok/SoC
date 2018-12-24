
#include "stack.h"

struct stack {
	char data[MAX_SIZE];
	size_t size;
};

char pop(char_stack_t *stack) 
{
	if (stack->size == 0) {
		printf("STACK OWERFLOW\n");
		exit(-1);
	} 
	stack->size--;
	return stack->data[stack->size];
}

void push(char_stack_t *stack, char value) {
	stack->data[stack->size] = value;
	stack->size++;
}