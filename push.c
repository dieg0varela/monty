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
	if (!head)
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
