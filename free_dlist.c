#include "monty.h"

/**
 * free_dlistint - Frees a dlistint_t list
 * @head : the first node
 */

void free_dlistint(stack_t *head)
{
	stack_t *aux = head;

	if (!head)
	{
		free(aux);
		return;
	}

	while (aux->next)
		free(aux), aux = aux->next;

	free(aux);
}
