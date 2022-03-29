#include <stdio.h>
#include <string.h>


char * ReverseString(char *start, char *end);
void PrintDevide(int num);

int main()
{
	
	char str[] = "tomer";
	char *end = str + strlen(str) -1;
	int num = 15;
	
	ReverseString(str,end);
	PrintDevide(num);
	
	
	printf("reverse string: %s\n",str);
	
	return 0;
}



char * ReverseString(char *start, char *end)
{
	
	char temp = '\0';
	char * result = start;
	
	while(start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		++start;
		--end;			
	}
	
	return result;
}



void PrintDevide(int num)
{
	
	int i = 1;
	
	for(i = 1; i <= num; ++i)
	{
		
		if(i % 5 == 0 && num % 3 == 0 )
		{
			printf("TF\n");
		}
		
		else if(i % 3 == 0)
		{
			printf("T\n");
		}
		
		else if(i % 5 == 0)
		{
			printf("F\n");
		}
		
		else 
		{
			printf("%d\n",i);
		}
		
	}		
	
}









