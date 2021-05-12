#include "monty.h"
monty_t monty;

int count_sep(char *str, char sep)
{
	int count = 0, i = 0;

	for (i = 0 ; str[i] != '\0' ; i++)
	{
		if (str[i] == sep)
			count++;
	}
	return (count);
}

void logic(char *sentence, int line)
{
	char *word;
	int i = 0;
	instruction_t arr[] = {
		{"push", push}, {"pall", pall}, {NULL, NULL}
	};
	sentence[strlen(sentence) - 1] = '\0';
	word = strtok(sentence, " ");
	if(word[0] == '#' || strcmp(word, "\n") == 0 || word == NULL)
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
			fprintf(stderr, "L%i: unknown instruction %s", line, word);
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
		logic(sentence, i);
		res = fgets(sentence, 1024, fp);
	}
	free(res);
	fclose(fp);

	return (0);
}
