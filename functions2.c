#include "monty.h"

/*
 * _swap - Swaps the top two elements of the stack
 * @stack : double linked list
 * @line_number : line number of the .m file
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int counter = 0, tmp = 0;
	stack_t *h = *stack, *current;

	if (!h)
	{	
		dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n", line_number);
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
		dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	current = h->next;
	tmp = current->n;
	current->n = h->n;
	h->n = tmp;
}
	
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
    {
        dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

	/* to count number of nodes */
	while (!h->next)
	{
		counter++;
		h = h->next;
	}

	if (counter < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
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
