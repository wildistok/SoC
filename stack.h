#include <stdlib.h>
#include <stdio.h>

#ifndef MAX_SIZE
#define MAX_SIZE 100

typedef struct stack char_stack_t;

void push(char_stack_t *stack, char value);

char pop(char_stack_t *stack);

 #endif