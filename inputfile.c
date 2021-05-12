#include "monty.h"
monty_t monty;

/**
 * logic - Entry point
 * @sentence: argument count
 * @line: argument variables
 *
 */

void logic(char *sentence, int line)
{
	char *word;
	int i = 0;
	instruction_t arr[] = {
		{"push", push}, {"pall", pall}, {NULL, NULL}
	};
	if(sentence)
		word = strtok(sentence, " \n");
	if (!word)
		return;
	if(word[0] == '#' || strcmp(word,"\n") == 0)
	{
		return;
	}
	while (arr[i].opcode != NULL)
	{
		if (strcmp(word, arr[i].opcode) == 0)
		{
			monty.data = strtok(NULL, " \n");
			arr[i].f(&monty.stack, line);
			break;
		}
		i++;
	}
	if(arr[i].opcode == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line, word);
		free_dlistint(monty.stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument variables
 *
 * Return: success or failure.
 *
 */

int main(int argc, char**argv)
{
	FILE *fp;
	int i = 0;
	char sentence[1024];
	char *res, *file;

	if(argc != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = argv[1];
	fp = fopen(file, "r");
	if(fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	res = fgets(sentence, 1024, fp);
	for (i = 1 ; res != NULL ; i++ )
	{
		if (strcmp(sentence, "\n") != 0)
			logic(sentence, i);
		res = fgets(sentence, 1024, fp);
	}
	if(monty.stack)
		free_dlistint(monty.stack);
	if(res)
		free(res);
	fclose(fp);

	return (0);
}
