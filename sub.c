#include "monty.h"

/**
* sub - Substract the top two elements of the stack
* @stack: pointer to stack
* @line_number: line number
*
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
	}

	temp->prev->n -= temp->n;
	pop(stack, line_number);
}
