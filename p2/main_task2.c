#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mystring.h"
#include "function.h"

#define PREFIX "tab"
#define SIZE_PREFIX 3
int main()
{
        while(1)
	{
		clock_t time_start = clock();
		printf("Enter a line: ");
		char * str = myreadline();
		if(str == NULL)
		{
			printf("\n");
			return 0;
		}
		else if(str[0] == '\0')
		{
			printf("\"\"\n");
		}
		else
		{
			add_prefix(str);
		}
		free(str);
                clock_t time_end = clock() - time_start;
		printf("Затраченное время: %lf\n\n", (double)time_end / CLOCKS_PER_SEC);
	}
	
	return 0;
}
