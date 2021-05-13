#include "monty.h"

/**
 * isNum - checks if a string is number or not
 * @num: pointer to char
 *
 * Return: 1 if not, 0 if true.
 */

int isNum(char *num)
{
	int pos = 0;

	for (pos = 0 ; num[pos] != '\0' ; pos++)
	{
		if (num[0] == '-')
			continue;
		if (isdigit(num[pos]) == 0)
			return (0);
	}
	return (1);
}

/**
 * push - opcode push, pushes an element to the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *tmp;

	tmp = *stack;
	if (!monty.data || !isNum(monty.data))
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	if (!stack)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(monty.data);
	new->next = NULL;
	if ((*stack) == NULL)
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

/**
 * pall - pall prints all the values on the stack, starting from the top
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
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

/**
 * pop - removes the top element of the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		free_dlistint(monty.stack);
		fclose(monty.fp);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if ((*stack)->next == NULL)
	{
		free(temp);
		*stack = NULL;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->prev->next = NULL;
		free(temp);
	}
}
