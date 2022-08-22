#include "monty.h"
/**
* get_opcode - get the opcode functions
* @str: opcode found
* @counterline: line of the .m file
* Return: 0
*/

void (*get_opcode(char *str,  int counterline))(stack_t **, unsigned int)
{
	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};

	char *str_tokenized;
	int i = 0;

	str_tokenized = strtok(str, " \t");

	if (!str_tokenized)
	{
		return (_nop);
	}
	while (ins[i].opcode)
	{
		if (strcmp(str_tokenized, ins[i].opcode) == 0)
		{
			return (ins[i].f);
		}
		i++;
	}
	dprintf(STDERR_FILENO, "L%i: unknown instruction %s\n", counterline, str);
	exit(EXIT_FAILURE);
	return (0);
}
