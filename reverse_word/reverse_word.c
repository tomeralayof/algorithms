#include <stdio.h>
#include <string.h>

#define SPACE (' ')

char * ReverseString(char *start, char *end);
void ReverseWord(char * str);

int main()
{

	char start[] = "i am student";
	
	ReverseWord(start);
	
	printf("reverse word: %s\n",start);
	
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


void ReverseWord(char * str)
{

	char *temp = str;
	char *end = str + strlen(str) - 1;
	
	ReverseString(str,end);
		
	while( '\0' != *str)
	{
	
		if(*str == SPACE)
		{
			ReverseString(temp,str - 1);
			temp = str + 1;
		}
		
		++str;
	}
}











