#include "monty.h"

/*
 * _add - Adds the top two elements of the stack
 * @stack : double linked list
 * @line_number : line number of the .m file
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0, counter = 0;
	stack_t *h = *stack, *sig = NULL;

	if (!h)
		exit(EXIT_FAILURE);

	/* to count number of nodes */
	while (!h->next)
	{
		counter++;
		h = h->next;
	}
		
	if (counter < 2)
	{
		dprintf(STDERR_FILENO, "L<%i>: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	/* sum the two elements */
	sum += h->n;
	h = h->next;
	sum += h->n;
	h->n = sum;

	/* deletes the first node */
	h = h->prev;
	*stack = h->next;
	sig = h->next;
	free(h);
	if (sig)
		sig->prev = NULL;

	printf("%i\n", sum);
}
/*
 * _nop - Doesn’t do anything
 * @stack : double linked list
 * @line_number : line number of the .m file
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack, (void) line_number;
}
