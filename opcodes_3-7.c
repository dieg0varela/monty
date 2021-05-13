#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *temp2 = NULL;
	int n = 0;

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
	temp2 = (*stack)->next;
	while (temp2->next)
	{
		temp = temp->next;
		temp2 = temp2->next;
	}

	n = temp2->n;
	temp2->n = temp->n;
	temp->n = n;

}

/**
 * add - Adds the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
	}

	temp->prev->n += temp->n;
	pop(stack, line_number);
}

/**
 * nop - removes the top element of the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

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

/**
 * _div - divides the second top element of the stack by the top ele
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
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
	temp->prev->n /= temp->n;
	pop(stack, line_number);
}
