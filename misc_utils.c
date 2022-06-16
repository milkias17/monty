#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
	* _strdup - duplicate a string
	* @str: string we want duplicated
	* Description: duplicate a string
	* Return: duplicated string
*/
char *_strdup(char *str)
{
	int i = 0;
	char *new_str;

	new_str = malloc(sizeof(char) * strlen(str));
	if (new_str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (; str[i] != '\0'; i++)
	{
		new_str[i] = str[i];
	}

	return (new_str);
}
