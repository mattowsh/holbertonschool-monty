#include "monty.h"

/* possible global variable? check... */

/* main.c - Coordinates the execution of opcodes
 * using our interpreter for Monty ByteCodes files
 *
 * Return:
 */

int main(int ac, char **av)
{
	char *result, **token;

	if (ac != 2)
	{
		write(STDERR_FILENO,"USAGE: monty file\n", 19);
		exit(EXIT_FAILURE); /* return a int always != 0 */
	}

	result = openfile(av[1]);
	token = set_strtok(result);


	return (0);
}
