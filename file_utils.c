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
	* get_tokenized_line - returns an array of line sep by space
	* Description: returns an array of line sep by space
	* Return: char
*/
char **get_tokenized_line()
{
	const char *delims = " ";
	char **res;
	char *token;
	int pos = 0;
	char *tmp = strdup(line);

	res = malloc(sizeof(char *) * 3);
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
