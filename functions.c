#include "monty.h"
/**
* _pall - print all the values on the stack
* from the top of the stack.
* @stack: double linked list
* @line_number: line number of the .m file
*/
void _pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
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

	if (!h)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}

/**
* _pop - removes the top element of the stack
* @stack: double linked list
* @line_number: line number of the .m file
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack, *sig;

	if (!h)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = h->next;
	sig = h->next;
	free(h);
	if (sig)
		sig->prev = NULL;
}

/**
* _push - pushes an element to the stack
* @stack: double linked list
* @line_number: line number of the .m file
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;
	char *n;
	int num = 0;

	n = strtok(NULL, " \t");
	num = verify_digit(n);
	if (num == 0)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
		exit(EXIT_FAILURE);

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

/**
* verify_digit - verifies if the string
* is a number
* @num: string to verify
* Return: 1 if it's a number,
* otherwise return 0
*/
int verify_digit(char *num)
{
	int i = 1;

	if (!num)
		return (0);
	if ((num[0] < '0' || num[0] > '9') && num[0] != '-')
		return (0);
	while (num[i])
	{
		if (num[i] < 48 || num[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
