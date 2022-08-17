#include "monty.h"

/**
 * set_strtok - Tokenizes a string based in separators:
 * space, newline, tab or NULL character at the end of the string
 * @input: string to be tokenized
 *
 * Return: a pointer to the matrix that contains the tokens
 */

char **set_strtok(char *input)
{
	char **result;
	int i = 0, j = 0, k = 0, l = 0, letters, counter = 0;

	if (input == NULL || *input == '\0')
		return (NULL);

	while (input[i])
	{
		if ((input[i + 1] == '\n') && (input[i] != '\n'))
			counter++;
		i++;
	}
	result = malloc(sizeof(char *) * (counter + 1));
	if (result == NULL)
		return (NULL);

	for (i = 0; (i < counter) && input[j]; i++)
	{
		letters = 0;
		while (input[j] == '\n')
			j++;
		while (input[j] != '\n')
			letters++, j++;

		result[i] = malloc(letters + 1);
		if (!result[i])
			return (NULL);

		result[i][letters] = '\0';
		k = j;
		l = letters - 1;
		for (; k > (j - letters); k--, l--)
			result[i][l] = input[k - 1];
	}
	result[counter] = NULL;
	return (result);
}