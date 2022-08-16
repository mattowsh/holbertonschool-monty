#include "monty.h"

/*
 * openfile - Opens the file passed like argument in ./monty execution
 * @filename : filename to be opened = av[1]
 *
 * Return: 0 in success, != 0 otherwise
 */

int openfile(char *filename)
{
	ssize_t fd;

	fd = open(filename, O_RDWR, 0600);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO,"Error: Can't open file <%s>\n", filename);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
