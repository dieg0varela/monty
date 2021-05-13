#include "monty.h"

/**
 * rotr - rotates the top to the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void rotr(stack_t **stack, unsigned int line_numbe)
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
	if (temp2->next == NULL)
		swap(stack, line_number);
	while (temp2->next)
	{
		n = temp2->n;
                temp2->n = temp->n;
                temp->n = n;
		temp = temp->next;
		temp2 = temp2->next;
	}
}
