#include "monty.h"

/**
 * mul - Multiply the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
	}

	temp->prev->n *= temp->n;
	pop(stack, line_number);
}

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
	if (isascii(temp->n))
		printf("%c\n", temp->n);
	else
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
}

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
		putchar(10);
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

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = NULL, *temp2 = NULL;
	int n = 0;

	if (!stack || !*stack)
	{
		return;
	}
	if ((*stack)->next == NULL)
	{
		return;
	}
	temp = *stack;
	temp2 = (*stack)->next;
	while (temp2->next)
	{
		temp = temp->next;
		temp2 = temp2->next;
	}
	while (temp2->prev)
	{
		n = temp2->n;
		temp2->n = temp->n;
		temp->n = n;
		temp = temp->prev;
		temp2 = temp2->prev;
	}
}
