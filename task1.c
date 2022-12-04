#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>
#include <time.h>
#define PREFIX "tab"

void add_prefix(char*str)
{
	char* consonants = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM";
	printf("Начальная строка: \"%s\"\n", str);
	printf("Конечная строка: \"");

	for(int i = 1;str[i]!='\0';i++)
	{
		int flag = 0;
		if((str[i]==' ')&&(str[i+1]==' '))
		{
			continue;
		}
		if((str[i-1]=='"')||(str[i-1]==' '))
		{
			for(int j = 0;j<40;j++)
			{
			        if(str[i]==consonants[j])
				{
					flag = 1;
					
				}

			}
			if(flag == 1)
			{
				printf("%s%c", PREFIX, str[i]);
			}
			else
			{
				printf("%c", str[i]);
			}
		}
		else
		{
			printf("%c", str[i]);
		}
	}
	printf("\"\n");
	free(str);
}

int main()
{
        while(1)
	{
		clock_t time_start = clock();
		char * str = readline("Enter a line: \n");
		if(str == NULL)
		{
			return 0;
		}
		else
		{
			add_prefix(str);
			clock_t time_end = clock() - time_start;
			printf("Затраченное время: %lf\n", (double)time_end / CLOCKS_PER_SEC);
		}
	}
	return 0;
}
