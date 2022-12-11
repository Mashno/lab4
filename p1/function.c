#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>

#define PREFIX "tab"
#define SIZE_PREFIX 3

void add_prefix(char*str)
{
	char* consonants = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM";
	printf("Начальная строка: \"%s\"\n", str);
	char *res =strdup("\0");
	char *word = strtok(str, " ");

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
	
	if(res[0]!='\0')
	{
		res[strlen(res)-1] = '\0';// избавляемся от последнего пробела
	}
	printf("\"%s\"\n", res);
	
	free(res);
	free(word);
}


