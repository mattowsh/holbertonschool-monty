#include "monty.h"

/* main.c - Coordinates the execution of opcodes
 * using our interpreter for Monty ByteCodes files
 *
 * Return:
 */

int main(int ac, char **av)
{
	int i = 0, counterline = 1;
	char *result, **token;

	(void) av;

	if (ac != 2)
	{
		write(STDERR_FILENO,"USAGE: monty file\n", 19);
		exit(EXIT_FAILURE); /* return a int always != 0 */
	}

	result = openfile(av[1]);
	token = set_strtok(result);

	while (token[i])
	{
		// variable global dato de counterline
		get_opcode(token[i]);
		counterline++;
		i++;
	}
	// le paso cada token a mi funcion con la estructura
	// strtok de esa linea con \t y espacios
	// detecto si alguno de estos nuevos tokens estan en la estruct
	// puedo usar variable global para guardar el dato numerico luego de push



	return (0);
}
