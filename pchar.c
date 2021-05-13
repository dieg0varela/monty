#include "monty.h"

/**
 * pall - pall prints all the values on the stack, starting from the top
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp)
	{
		if (temp->n < 31 && temp->n > 126)
		{
			fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
			free_dlistint(monty.stack);
			fclose(monty.fp);
			exit(EXIT_FAILURE);
		}
		printf("%c\n", temp->n);
		temp = temp->prev;
	}
}
