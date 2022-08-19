#include "monty.h"

/**
 * set_strtok - Tokenizes a string based in separators:
 * space, newline, tab or NULL character at the end of the string
 * @s: string to be tokenized
 * @delimeter: delimiters
 *
 * Return: a pointer to an array tokenized
 */
char **set_strtok(char *s, char delimeter)
{
	char **args;
	int i = 0;
	int x = -1;
	int index = 0;
	int length = 0;

	for (i = 0; s && s[i]; i++)
	{
		if (s[i + 1] == delimeter)
		{
			length++;
		}
	}
	args = malloc(sizeof(char *) * (length + 1));
	for (i = 0; s && s[i]; i++)
	{
		if ((s[i] != delimeter || s[i + 1] == delimeter))
		{
			if (x == -1)
			{
				for (length = 0, x = i; s[x] != delimeter; x++, length++)
					;
				x = 0;
				args[index] = malloc(sizeof(char *) * length + 1);
			}
			if (s[i] != '\n')
			{
				args[index][x] = s[i];
				x++;
			}
			if (s[i + 1] == delimeter)
			{
				args[index][x] = '\0';
				x = -1;
				index++;
			}
		}
	}
	args[index] = NULL;
	return (args);
}
