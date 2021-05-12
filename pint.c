#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	printf("%d\n", temp->n);
}
