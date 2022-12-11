#include <stdio.h>
#include <stdlib.h>

size_t mystrlen(const char* str)
{
	size_t counter = 0;
	for(int i = 0; str[i]!='\0';i++)
	{
		counter+=1;
	}
	return counter;
}



char* mystrchr(const char* str, int symbol)
{

	for(int i = 0;i<mystrlen(str)+1;i++)
	{
		if (symbol==*str)
		{
			return (char*)str;
		}
		str++;
	}
	return NULL;
}

size_t mystrspn(const char* str, const char* chars)
{
	size_t i = 0;
	while(str[i] && mystrchr(chars, str[i]))
	{
		i++;
	}
	return i;
}
char* mystrtok(char* str, const char* delim)
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
		if(i==1)
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

void* mymemcpy(void* dest, const void * origin, size_t num)
{
	char* destanation = (char*)dest;
	const char* original = (char*) origin;

	for(size_t i = 0; i<num;i++)
	{
		destanation[i] = original[i];
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
		mymemcpy(res, str, lenght);
		return res;
	}
}

char* mystrcat(char* first, const char* last)
{
	char* add_sign = first+mystrlen(first);

	while(*last != '\0')
	{
		*add_sign++ = *last++;
	}
	*add_sign = '\0';
	return first;
}



