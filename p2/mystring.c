#include <stdio.h>
#include <stdlib.h>


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


int mystrlen(char* str)
{
	int counter = 0;
	for(int i = 0; str[i]!='\0';i++)
	{
		counter+=1;
	}
	return counter;
}


