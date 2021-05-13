#include "monty.h"

/**
 * mod - divides the second top element of the stack by the top ele
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	temp->prev->n %= temp->n;
	pop(stack, line_number);
}
