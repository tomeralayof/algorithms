#include <stdio.h>
#include <stdbool.h>

#define MAX_CHAR 255


static size_t counters[MAX_CHAR] = {0};
void reset();
void LoopForever(char ch);

int main()
{

	char ch = 'k';
	LoopForever(ch);	
	
	return 0;

}

void LoopForever(char ch)
{

	static size_t max = 0;
	
	while(true)
	{
	
		scanf("%c",&ch);
		
		if(ch == '0')
		{
			printf("%c",(char)max);
			max = 0;
			
			reset(counters);
		}		
		else
		{
			++counters[(int)ch];
			
			if(counters[(int)ch] > counters[(int)max])
			{
				max = ch;
			}
		}
	}
}


void reset()
{
	int i = 0;
	for(i = 0; i < MAX_CHAR ; ++i )
	{
		counters[i] = 0;
	}
}







