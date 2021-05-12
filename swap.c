#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
                fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
                free_dlistint(monty.stack);
                fclose(monty.fp);
                exit(EXIT_FAILURE);
        }
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->next = temp->prev;
	temp->prev = temp->prev->prev;
	temp->prev->prev = temp;

}
