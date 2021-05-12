#include "monty.h"

/**
 * free_dlistint - function that frees a dlistint_t list
 * @head: pointer to list
 *
 */

void free_dlistint(stack_t *head)
{
	stack_t *tmp = head, *tmp_next;

	if (head)
	{
		tmp_next = head->next;
		while (tmp_next)
		{
			free(tmp);
			tmp = tmp_next;
			tmp_next = tmp_next->next;
		}
		free(tmp);
	}
}
