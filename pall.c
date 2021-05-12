#include "monty.h"

/**
 * pall - pall prints all the values on the stack, starting from the top
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = NULL;

       	if (!stack || !*stack)
		return;
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
	}
}
