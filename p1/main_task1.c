#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>
#include <time.h>
#include "function.h"

#define PREFIX "tab"
#define SIZE_PREFIX 3
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
			double time_start = ((double)clock())/ CLOCKS_PER_SEC;
			add_prefix(str);
			double time_end = ((double)clock())/CLOCKS_PER_SEC;
		        printf("Затраченное время: %lf\n\n", time_end-time_start );
		}
		free(str);
	}
	
	return 0;
}
