#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>
#include <time.h>
#define PREFIX "tab"
#define NUMBER_CONSONANTS 40
#define SIZE_PREFIX 3

void add_prefix(char*str)
{
	char* consonants = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM";
	printf("Начальная строка: \"%s\"\n", str);
	char *res =strdup("\0");
	char *word = strtok(str, " ");

	
	//for(char* word = strtok(str, " "); word !=NULL;word = strtok(NULL, " "))
	while(word!=NULL)
        {
		if(strchr(consonants, word[0])!=NULL)
		{
		        size_t result_len = strlen(word) + strlen(res) + SIZE_PREFIX + 2;//т.к strlen считает без \0, то +1 для него. ещё +1 для пробела
			res = (char*)realloc(res, result_len*sizeof(char));

			strcat(res, PREFIX);
		        strcat(res,word);
		        strcat(res, " ");
		}
		else
		{
			
		        size_t result_len = strlen(word) + strlen(res) + 2;
			res = (char*)realloc(res, result_len*sizeof(char));

		        strcat(res,word);
		        strcat(res, " ");
		}
		word = strtok(NULL, " ");
	}
	
	res[strlen(res)-1] = '\0';// избавляемся от последнего пробела
	printf("\"%s\"\n", res);
	
	free(res);
	free(word);
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
		        printf("Затраченное время: %lf\n\n", (double)time_end / CLOCKS_PER_SEC);
		}
		free(str);
	}
	
	return 0;
}
