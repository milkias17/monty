#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
	* get_line - returns the current line in file
	* @fp: file stream
	* Description: returns the current line in file
	* Return: char
*/
char *get_line(FILE *fp)
{
	int size = 100;
	char *res;
	char ch;

	res = malloc(sizeof(char) * size);
	if (res == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fp)) != '\n')
	{
		if (ch == EOF)
			return (NULL);
		strncat(res, &ch, 1);
	}

	return (res);
}


/**
	* validate_line - checks whether the current line is valid
	* Description: checks whether the current line is valid
	* Return: int
*/
int validate_line()
{
	int length = 0;
	return (0);
}

/**
	* get_tokenized_line - returns an array of line sep by space
	* Description: returns an array of line sep by space
	* Return: char
*/
char **get_tokenized_line()
{
	const char *delims = " ";
	char **res = malloc(sizeof(char *) * 3);
	char *token;
	int pos = 0;
	char *tmp = strdup(line);

	if (res == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(tmp, delims);
	while (pos < 2)
	{
		res[pos++] = token;
		token = strtok(NULL, delims);
	}
	res[pos] = NULL;

	return (res);
}
