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
			double time_start = ((double)clock())/CLOCKS_PER_SEC;
			add_prefix(str);
                        double time_end = ((double)clock())/CLOCKS_PER_SEC;
		        printf("Затраченное время: %lf\n\n", time_end - time_start);
		}
		free(str);
	}
	
	return 0;
}
