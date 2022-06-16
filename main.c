#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

char *line;

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	int line_number = 0;
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (argc > 2 || argc == 1)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((line = get_line(fp)) != NULL)
	{
		line_number++;
		f = get_op_func(line_number);
		f(&stack, line_number);
	}



	return (0);
}
