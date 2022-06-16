#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
	* is_valid_op - checks if op_code is valid
	* @op_type: op_type string
	* Description: checks if op_code is valid
	* Return: int
*/
int is_valid_op(char *op_type)
{
	char *valid_op_codes[] = {"push", "pall"};
	int i = 0;
	int size = 2;

	for(; i < size; i++)
	{
		if (strcmp(op_type, valid_op_codes[i]) == 0)
			return (1);
	}
	return (0);
}

/**
	* get_op - returns the function for the given op
	* @line_number: line number where call is
	* Description: returns the function for the given op
	* Return: function
*/
void (*get_op_func(int line_number))(stack_t **stack, unsigned int line_number)
{
	char **sep_cmd = get_tokenized_line();
	instruction_t op_mappers[2] = {
		{"push", push},
		{"pall", pall}
	};
	int i = 0;
	void (*fo)(stack_t **stack, unsigned int line_number);

	if (is_valid_op(sep_cmd[0]) == 0)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, sep_cmd[0]);
		exit(EXIT_FAILURE);
	}

	for(; i < 2; i++)
	{
		if(strcmp(sep_cmd[0], op_mappers[i].opcode) == 0)
		{
			return (op_mappers[i].f);
		}
	}

	return (NULL);
}
















