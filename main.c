#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

char *line;

int main(int argc, char *argv[])
{
	FILE *fp;
	int line_number = 0;
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
		handle_error("malloc");

	if (argc > 2 || argc == 1)
	{
		handle_error("usage");
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((line = get_line(fp)) != NULL)
	{
		if (is_valid_line(line) != 1)
			continue;

		line_number++;
		/* printf("Line number %i is now %s\n", line_number, line); */
		f = get_op_func(line_number);
		f(&stack, line_number);
	}

	free_stack(stack);
	free(line);

	return (0);
}
