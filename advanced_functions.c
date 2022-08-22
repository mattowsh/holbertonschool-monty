#include "monty.h"

/**
 * _sub - Subtracts the top element of the stack from the
 * second top element of the stack
 * @stack : double linked list
 * @line_number : line number of the .m file
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int sub = 0, counter = 0;
	stack_t *h = *stack, *sig = NULL;

	if (!h)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* to count number of nodes */
	while (h)
	{
		counter++;
		h = h->next;
	}

	if (counter == 1)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	h = *stack;

	/* sub the two elements */
	h = h->next;
	sub = h->n;
	h = h->prev;
	sub -= h->n;
	h = h->next;
	h->n = sub;

	/* deletes the first node */
	h = h->prev;
	*stack = h->next;
	sig = *stack;
	free(h);
	if (sig)
		sig->prev = NULL;
}

/**
 * _div - Divides the second top element of the stack by the
 * top element of the stack
 * @stack : double linked list
 * @line_number : line number of the .m file
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int div = 0, counter = 0;
	stack_t *h = *stack, *sig = NULL;

	if (!h)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* to count number of nodes */
	while (h)
		counter++, h = h->next;

	if (counter == 1)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	h = *stack;

	/* divides the two elements */
	if (h->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	h = h->next;
	div = h->n;
	h = h->prev;
	div /= h->n;
	h = h->next;
	h->n = div;

	/* deletes the first node */
	h = h->prev;
	*stack = h->next;
	sig = *stack;
	free(h);
	if (sig)
		sig->prev = NULL;
}



















