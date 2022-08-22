#include "monty.h"

/**
 * _sub - Subtracts the top element of the stack from the
 * second top element of the stack
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
	sub = h->n;
	h = h->next;
	sub -= h->n;
	h->n = sum;

	/* deletes the first node */
	h = h->prev;
	*stack = h->next;
	sig = *stack;
	free(h);
	if (sig)
		sig->prev = NULL;
}
