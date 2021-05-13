#include "monty.h"

/**
 * rotr - rotates the top to the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void rotr(stack_t **stack, unsigned int line_numbe __attribute__((unused)))
{
	stack_t *temp = NULL, *temp2 = NULL;
	int n = 0;

	if (!stack || !*stack)
	{
		return;
	}
	if ((*stack)->next == NULL)
	{
		return;
	}
	temp = *stack;
	temp2 = (*stack)->next;
	while (temp2->next)
	{
		temp = temp->next;
		temp2 = temp2->next;
	}
	while (temp2->prev)
        {
		n = temp2->n;
		temp2->n = temp->n;
		temp->n = n;
		temp = temp->prev;
		temp2 = temp2->prev;
	}
}
