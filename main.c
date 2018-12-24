#include <string.h>

#include "stack.h"

struct stack {
	char data[MAX_SIZE];
	size_t size;
};


void rpn(char_stack_t *stack, char value) 
{
	char opr_1 = 0;
	char opr_2 = 0;
	switch(value) {
		case '+':
			opr_1 = pop(stack);
			opr_2 = pop(stack);
			push(stack, opr_2 + opr_1);
			break;
		case '-':
			opr_1 = pop(stack);
			opr_2 = pop(stack);
			push(stack, opr_2 - opr_1);
			break;
		case '*':
			opr_1 = pop(stack);
			opr_2 = pop(stack);
			push(stack, opr_2 * opr_1);
			break;
		case '/':
			opr_1 = pop(stack);
			opr_2 = pop(stack);
			push(stack, opr_2 / opr_1);
			break;
		default:
			break;
	} 
}


int main (int argc, char *argv[]) 
{ 
	char_stack_t stack;
	stack.size = 0;

	char str[256] = "";
	char tmp[4] = "";
	char j = 0;

	printf("Enter RPN.\nExample syntax: 7 3 4 * -\n");

	while (1) {
		scanf ("%[^\n]%*c", str);

		if (strcmp(str, "exit") == 0) {
			exit(0);
		}

		size_t len = strlen(str);

		for(size_t i = 0; i <= len; i++) {
			if ((str[i] == '-') || (str[i] == '+') || (str[i] == '*') || (str[i] == '/')) {
				rpn(&stack, str[i]);
				continue;
			}
			if (((str[i] == ' ') || (i == (len))) && atoi(tmp) != 0) {
				push(&stack, atoi(tmp));
				memset(tmp, 0 , sizeof(char) * (j+1));
				j = 0;

			} else {
				memcpy(&tmp[j], &str[i], sizeof(char));
				j++;
			} 
		
		}
		printf("%s = %hhd\n", str, pop(&stack));

		memset(str, 0 , sizeof(char) * len);
		stack.size=0;
		j = 0;

	}
}

