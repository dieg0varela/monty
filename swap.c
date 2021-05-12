#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *temp2 = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp2 = (*stack)->next;
	while (temp2->next)
	{
		temp = temp->next;
		temp2 = temp2->next;
	}
	temp->prev->next = temp2;
	temp->next = NULL;
	temp2->prev = temp->prev;
	temp->prev = temp2;
	temp2->next = temp;
}
