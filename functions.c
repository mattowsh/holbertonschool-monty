#include "monty.h"
/**
* get_opcode - get the opcode functions
* 
* @s: opcode found
*/
void (*get_opcode(char *str))(int)
{
	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
}
