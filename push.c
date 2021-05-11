#include "monty.h"
#include "data.h"

/**
 * push - opcode push, pushes an element to the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	new = malloc(stack_t);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(*stack == NULL)
	{
		new->n = data;
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		new->n = data;
		new->next = NULL;
		new->prev = *stack;
		*stack->next = new;
		*stack = new;
	}
}
