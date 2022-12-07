#include <stdio.h>
#include <stdlib.h>
#include "proba.h"

#define PREFIX "tab"
#define SIZE_PREFIX 3

/*char* mystrtok(char* str, char* delim)
{
	static char * end_word = 0;

	if(str) 
	{
		end_word = str;
	}
	if((end_word==0)||(*end_word == 0))
	{
		return NULL;
	}

	char* index = end_word;
	while(mystrchr(delim,index))
	{
		++index;
	}
	if(*index == 0)
	{
		return NULL;
	}
	char * start = index;
	while(*index && (mystrchr(delim, *index)==0))
	{
		++index;
	}
	if(*index == 0)
	{
		end_word = index;
		return start;
	}
	*index = 0;
	end_word = index+1;
	return start;
}*/
/*char* mystrtok(char* str, char* delim)
{
	static int current_index = 0;
	static char* ptr = str;
	int i = current_index;
	if(!str || !delim || str[current_index]=='\0')
	{
		return NULL;
	}
	while(mystrchr(delim, ptr[i])==NULL)
	{
		i++;
	}
	char*start = *ptr[i];

	while((*ptr[i])&&(mystrchr(delim, ptr[i])==NULL))
	{
		i++;
	}
	ptr[i] = '\0';
	current_index = i+1;
	return start;

}*/
char* mystrchr(char* str, int symbol)
{

	while(*str!='\0')
	{
		if (symbol==*str)
		{
			return str;
		}
		str++;
	}
	return NULL;
}
/*char* mystrtok(char* str, char* delim)
{
	static int current_index = 0;
	static char* ptr = 0;
	ptr = str;
	int i = current_index;
	if(!str || !delim || str[current_index]=='\0')
	{
		return NULL;
	}
	while(mystrchr(delim, ptr[i])==NULL)
	{
		i++;
	}
	char*start = ptr[i];

	while((ptr[i])&&(mystrchr(delim, ptr[i])==NULL))
	{
		i++;
	}
	ptr[i] = '\0';
	current_index = i+1;
	return start;

}*/

/*char* mystrtok(char* str, char* delim)
{
	static char * end_word = 0;

	if(str) 
	{
		end_word = str;
	}
	if((end_word==0)||(*end_word == 0))
	{
		return NULL;
	}

	char* index = end_word;
	while(mystrchr(delim,index))
	{
		++index;
	}
	if(*index == 0)
	{
		return NULL;
	}
	char * start = index;
	while(*index && (mystrchr(delim, *index)==0))
	{
		++index;
	}
	if(*index == 0)
	{
		end_word = index;
		return start;
	}
	*index = 0;
	end_word = index+1;
	return start;
}*/

/*int mystrspn(char* str1, char* str2)
{
	int i;
	for(i = 0;str1[i]!='\0';i++)
	{
		if(mystrchr(str2, str1[i])!=NULL)
		{
			i++;
		}
		else
		{
			return i;
		}
	}
	return i-1;
}*/
size_t mystrspn(char* str, char* chars)
{
	size_t i = 0;
	while(str[i] && mystrchr(chars, str[i]))
	{
		i++;
	}
	return i;
}
char* mystrtok(char* str, char* delim)
{
	static char*nxt;
	static int size;
	int i;
	if(str !=NULL)
	{
		nxt = str;
		size= mystrlen(str);
	}
	else if(size>0)
	{
		nxt++;
		size--;
		str = nxt;
	}
	else
	{
		str = NULL;
	}

	while(*nxt)
	{
		i = mystrspn(nxt, delim);
		while(i>1)
		{
			*nxt = '\0';
			nxt++;
			size--;
			i--;
		}
		if(1==i)
		{
			*nxt = '\0';
			if(size>1)
			{
				nxt--;
				size++;
			}
		}
		nxt++;
		size--;
	}
	return str;

}

char* mymemcpy(char* destanation, char * origin, int num)
{
	for(int i = 0; i<num;i++)
	{
		destanation[i] = origin[i];
	}
	return destanation;
}

char* mystrdup(char* str)
{
	int lenght = mystrlen(str)+1;
	char* res = (char*) malloc(lenght*sizeof(char));
	if(res == NULL)
	{
		return NULL;
	}
	else
	{
		res = (char*) mymemcpy(res, str, lenght);
		return res;
	}
}

char* mystrcat(char* first, char* last)
{
	int common_len = mystrlen(first)+mystrlen(last)+1;;
	char* add_sign = first+mystrlen(first);

	while(*last != '\0')
	{
		*add_sign++ = *last++;
	}
	*add_sign = '\0';
	return first;
}

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
			int chunk_len = mystrlen(buffer);
			int str_len = lenght + chunk_len;

			result = (char*)realloc(result, str_len+1);//единица для \0
			memcpy(result+lenght, buffer, chunk_len);
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

int mystrlen(char* str)
{
	int counter = 0;
	for(int i = 0; str[i]!='\0';i++)
	{
		counter+=1;
	}
	return counter;
}


