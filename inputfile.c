#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
typedef struct op
	{	
		char *op;
		void (*f)(int a);
	} op_t;

void print_push(int i)
{
	printf("Push : %d\n", i);
}
void print_pall(int i)
{
	printf("Pall : %i\n", i);
}
int isNum(char *num)
{
	int pos = 0;

	for(pos = 0 ; num[pos] != '\0' ; pos++)
	{
		if(isdigit(num[pos]) == 0)
			return (0);
	}
	return (1);
}
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
	op_t arr[] = {
		{"push", print_push}, {"pall", print_pall}, {NULL, NULL}
	};

	word = strtok(sentence, " \n");
		while (arr[i].op != NULL)
		{
			if (strcmp(word, arr[i].op) == 0)
			{
				word = strtok(NULL, " \n");
				printf("WO: %s\n", word);
				if(!isNum(word))
					printf("ERROR AQUI");
				arr[i].f(atoi(word));
				break;
			}
			i++;
		}
		if(arr[i].op == NULL)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line, word);
			exit(EXIT_FAILURE);
		}
}
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
		printf("SE: %s\n", sentence);
		res = fgets(sentence, 1024, fp);
	}
	fclose(fp);

	return (0);
}
