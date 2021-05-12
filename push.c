#include "monty.h"

/**
 * push - opcode push, pushes an element to the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *tmp = *stack;

	if (!data || !isNum(data))
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		free(res);
		exit(EXIT_FAILURE);
	}
	new = malloc(stack_t);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(res);
		exit(EXIT_FAILURE);
	}
	new->n = data;
	new->next = NULL;
	if(*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
