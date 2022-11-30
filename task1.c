#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>
#define PREFIX "tab"

void add_prefix(char*str)
{
	char* consonants = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM";
	printf("Начальная строка: \"%s\"\n", str);
	printf("Конечная строка: \"");

	for(int i = 1;str[i]!='\0';i++)
	{
		int flag = 0;
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
		char * str = readline("Enter a line: \n");
		if(str == NULL)
		{
			return 0;
		}
		else
		{
			add_prefix(str);
		}
	}
	return 0;
}
