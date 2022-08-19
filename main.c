#include "monty.h"

/**
 * main - Coordinates the execution of opcodes
 * using our interpreter for Monty ByteCodes files
 * @ac : argument count
 * @av : list of arguments
 *
 * Return: 0 in success, EXIT_FAILURE value otherwise
 */

int main(int ac, char **av)
{
	int i = 0;
	unsigned int counterline = 1;
	char *result, **token;
	stack_t *stack_h = NULL;
	void (*opcode)(stack_t **stack, unsigned int line_number);

	(void) av;

	if (ac != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		free_dlistint(stack_h);
		exit(EXIT_FAILURE); /* return a int always != 0 */
	}

	result = openfile(av[1]);
	token = set_strtok(result, '\n');
	while (token[i])
	{
		if (token[i][0])
		{
			opcode = get_opcode(token[i], counterline);
			opcode(&stack_h, counterline);
		}
		counterline++;
		i++;
	}
	free_grid(token);
	free(result);
	free_dlistint(stack_h);
	return (0);
}
