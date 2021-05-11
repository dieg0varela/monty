#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
void print_push(int i)
{
	printf("Push : %d\n", i);
}
void print_pall(int i)
{
	printf("Pall : %i\n", i);
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
int main(void)
{
	int fd = open("./test.m", O_RDONLY);
	char content[1024];
	int conti = 0;
	char *word;
	int i= 0;
	int j = 0;
	int strings = 0;
	typedef struct op
	{	
		char *op;
		void (*f)(int a);
	} op_t;

	op_t arr[] = {
		{"push", print_push}, {"pall", print_pall}, {NULL, NULL}
	};
	read(fd, content, 1024);
	strings = count_sep(content,'\n');
	word = strtok(content, " \n");
	for (j = 1; j <= strings ; j++)
	{
		conti = 0;
		while (arr[i].op != NULL)
		{
			if (strcmp(word, arr[i].op) == 0)
			{
				word = strtok(NULL, " \n");
				arr[i].f(atoi(word));
			}
			i++;
		}
		i = 0;
		if (j != strings)
		{
			word = strtok(NULL, " \n");
			while (conti == 0)
			{
				while (arr[i].op != NULL)
				{
					if (strcmp(word, arr[i].op) == 0)
					{
						conti = 1;
						break;
					}
					i++;
				}
				if (conti == 0)
					word = strtok(NULL, " \n");
				i = 0;
			}
		}
	}
	

	return (0);
}
