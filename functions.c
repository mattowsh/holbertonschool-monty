#include "monty.h"
/**
* _pall - print all the values on the stack
* from the top of the stack.
* @stack: double linked list
* @line_number: line number of the .m file
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	int count = 0;
	stack_t *h = *stack;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
}

/**
* _pint - prints the value at the top
* of the stack.
* @stack: double linked list
* @line_number: line number of the .m file
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	// verificar si es numero antes de printear
	printf("%d\n", h->n);
}

/**
* _pop - removes the top element of the stack
* @stack: double linked list
* @line_number: line number of the .m file
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(h);
}

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	char *n;

	n = strtok(NULL, " \t");
	newnode = malloc(sizeof(stack_t));

	if (!(*stack))
	{
		newnode->n = atoi(n);
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	else
	{
		newnode->n = atoi(n);
		newnode->prev = NULL;
		newnode->next = *stack;
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}
