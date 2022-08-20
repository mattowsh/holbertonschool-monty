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
	char *buffer, maxread[1024];
	int recorre_buffer = 1024, length = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO,"Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	while (recorre_buffer == 1024)
	{
		recorre_buffer = read(fd, maxread, 1024);
		if (recorre_buffer == -1)
		{
			dprintf(STDERR_FILENO,"Error: Can't open file %s\n", filename);
			exit(EXIT_FAILURE);
		}
		length += recorre_buffer;
	}

	buffer = malloc(sizeof(char) * length + 1);
	if (!buffer)
	{
		write(STDERR_FILENO,"Error: malloc failed\n", 21);
		exit(EXIT_FAILURE);
	}
	close(fd);

	fd = open(filename, O_RDONLY);
	read(fd, buffer, length);
	close(fd);

	return (buffer);
}
