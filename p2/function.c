#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

#define PREFIX "tab"
#define SIZE_PREFIX 3
void add_prefix(char*str)
{
	char* consonants = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM";
	printf("Начальная строка: \"%s\"\n", str);
	char* res = mystrdup("\0");
	char *word = mystrtok(str, " ");

	while(word!=NULL)
        {
		if(mystrchr(consonants, word[0])!=NULL)
		{
		        size_t result_len = mystrlen(word) + mystrlen(res) + SIZE_PREFIX + 2;//т.к strlen считает без \0, то +1 для него. ещё +1 для пробела
			res = (char*)realloc(res, result_len*sizeof(char));

			mystrcat(res, PREFIX);
		        mystrcat(res,word);
		        mystrcat(res, " ");
		}
		else
		{
			
		        size_t result_len = mystrlen(word) + mystrlen(res) + 2;
			res = (char*)realloc(res, result_len*sizeof(char));

		        mystrcat(res,word);
		        mystrcat(res, " ");
		}
		word = mystrtok(NULL, " ");
	}
	
	if(res[0]==' ')
	{
		res[0]= "";
	}
	res[mystrlen(res)-1] = '\0';// избавляемся от последнего пробела
	printf("\"%s\"\n", res);
	
	free(res);
	free(word);
}
char* myreadline()
{
	char buffer[71] = { 0 };
	char* result = NULL;
	int lenght = 0, scanf_index;

	do
	{
		scanf_index = scanf("%70[^\n]", buffer);

		if(scanf_index<0)
		{
			return NULL;
		}
		else if(scanf_index>0)
		{
			size_t chunk_len = mystrlen(buffer);
			size_t str_len = lenght + chunk_len;

			result = (char*)realloc(result, str_len+1);//единица для \0
			mymemcpy(result+lenght, buffer, chunk_len);
			lenght = str_len;
		}
		else
		{
			scanf("%*c");
		}
	} while(scanf_index>0);

	if (lenght>0)
	{
		result[lenght] = '\0';
	}		
	else
	{
	        result = (char*)calloc(1, sizeof(char));
	}

	return result;
}

