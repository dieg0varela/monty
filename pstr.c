#include "monty.h"

/**
 * pstr - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		putchar(10);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
        while (temp)
	{
		if (!isascii(temp->n))
		{
			break;
		}
		if (temp->n == '\0')
			break;
		printf("%c\n", temp->n);
		temp = temp->prev;
	}
}
