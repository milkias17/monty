#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
	* push_to_head - adds an element to the head of a stack
	* @head: head of stack(linked list)
	* @n: value of new node
	* Description: adds an element to the head of a stack
	* Return: pointer to new head of stack
*/
stack_t *push_to_head(stack_t **head, int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = n;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	node->next = *head;
	(*head)->prev = node;
	*head = node;

	return (node);
}

/**
	* push - pushes a new value onto the stack
	* @stack: stack to operate on
	* @line_number: line number of current operation
	* Description: pushes a new value onto the stack
	* Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	stack_t *node;
	char **tokenized_line;
	int n;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	tokenized_line = get_tokenized_line();
	n = atoi(tokenized_line[1]);
	node->n = n;

	if (*stack == NULL)
	{
		*stack = node;
		return;
	}

	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = node;
	node->prev = current;
}

/**
	* pall - prints all values in the stack
	* @stack: stack to operate on.
	* @line_number: line number where operation is located.
	* Description: prints all values in the stack
	* Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current->next != NULL)
		current = current->next;

	while (current->prev != NULL)
	{
		printf("%i\n", current->n);
		current = current->prev;
	}
}





