#ifndef MAX_SIZE
#define MAX_SIZE 3

typedef struct stack char_stack_t;

void push(char_stack_t *stack, char value);

char pop(char_stack_t *stack);

 #endif