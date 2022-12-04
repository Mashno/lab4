#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>
#include <time.h>
#define PREFIX "tab"
#define NUMBER_CONSONANTS 40

void add_prefix(char*str)
{
	char* consonants = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM";
	printf("Начальная строка: \"%s\"\n", str);
	char * word = strtok(str, " ");
	printf("\"");


	while(word!=NULL)
        {
		//int length_word = strlen(word);
		//int length_res = 1;
		//length_res = length_res+length_word+1;

		if(strchr(consonants, word[0])!=NULL)
		{
		        /*word = (char*)realloc(word,(length_word+3)*sizeof(char));
			word = strcat(PREFIX, word);
			res = (char*)realloc(res, length_res*sizeof(char));
			res = strcat(res,word);
			res = strcat(res, " ");
			*/
		       printf("%s%s ", PREFIX,word);	
			
		}
		else
		{
			/*res = (char*)realloc(res, length_res*sizeof(char));
			res = strcat(res, word);
		        res = strcat(res, " ");*/
			printf("%s ", word);
		}
		word = strtok(NULL, " ");
	}
	printf("\"\n");
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
			printf("Затраченное время: %lf\n", (double)time_end / CLOCKS_PER_SEC);
		}
	}
	return 0;
}
