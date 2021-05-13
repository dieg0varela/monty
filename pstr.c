#include "monty.h"

/**
 * pstr - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp)
	{
		if (temp->n == 0)
		{
			break;
		}
		if (isascii(temp->n))
		{
			printf("%c", temp->n);
		}
		else
			break;
		temp = temp->prev;
	}
	putchar(10);
}
