#include "monty.h"

/**
 * set_strtok - Tokenizes a string based in separators:
 * space, newline, tab or NULL character at the end of the string
 * @s: string to be tokenized
 * @delimiter: delimiters
 * Return: a pointer to an array tokenized
 */
char **set_strtok(char *s, char *delimeter)
{
	char **args;
	int i = 0;
	int length = 0;
	char *s_tmp;
	char *token;

	s_tmp = strdup(s);
	token = strtok(s_tmp, delimeter);
	for (length = 0; token; length++)
	{
		token = strtok(NULL, delimeter);
	}
	free(s_tmp);
	args = malloc(sizeof(char *) * (length + 1));
	if (args == NULL)
	{
		return (NULL);
	}

	s_tmp = strdup(s);
	token = strtok(s_tmp, delimeter);
	for (i = 0; token; i++)
	{
		args[i] = strdup(token);
		token = strtok(NULL, delimeter);
	}
	args[i] = NULL;
	free(s_tmp);
	return (args);
}
