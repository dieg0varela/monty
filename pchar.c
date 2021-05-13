#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
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
	if (temp)
	{
		if (temp->n < 0 && temp->n > 127)
		{
			fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
			free_dlistint(monty.stack);
			fclose(monty.fp);
			exit(EXIT_FAILURE);
		}
		printf("%c\n", temp->n);
	}
}
