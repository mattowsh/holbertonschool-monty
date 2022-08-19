#include "monty.h"

/*
 * openfile - Opens the file passed like argument in ./monty execution
 * @filename : filename to be opened = av[1]
 *
 * Return: 0 in success, != 0 otherwise
 */

char *openfile(char *filename)
{
	ssize_t fd;
	char *buffer = malloc(1024);
	int recorre_buffer = 1024;

	if (!buffer)
	{
		write(STDERR_FILENO,"Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		free(buffer);
		dprintf(STDERR_FILENO,"Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	while (recorre_buffer == 1024)
	{
		recorre_buffer = read(fd, buffer, 1024);
		if (recorre_buffer == -1)
		{
			free(buffer);
			dprintf(STDERR_FILENO,"Error: Can't open file %s\n", filename);
			exit(EXIT_FAILURE);
		}

	}
	
	close(fd);

	return (buffer);
}