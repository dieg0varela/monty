#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if ((*stack)->next == NULL)
	{
		free(temp);
		*stack = NULL;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->prev->next = NULL;
		free(temp);
	}
}
