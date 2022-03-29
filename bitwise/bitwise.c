#include <stdio.h>

#define four_bits_on 15
#define MAX_NIBBLE 16

enum
{
	SUCCESS,
	FAILURE
};

int SetBitsCount(int num);
void swap1(int *x, int *y);
int swap2(int *x, int *y);
void swap3(int *x, int *y);

int main()
{

	int num = 255;
	int result = 0;	
	
	int num_1 = 10;
	int num_2 = 5;
	

	swap3(&num_1,&num_2);
	printf("num_1 = %d, num_2 = %d\n",num_1,num_2);
	
	result = SetBitsCount(num);
	
	printf("%d\n",result);
	return 0;
}
	

int SetBitsCount(int num)
{


	static int lut[MAX_NIBBLE] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};	
	int count = 0;
	
	while(num > 0)
	{
		count += lut[num & four_bits_on];
		num = num >> 4;
	}

	return count;
}


void swap1(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int swap2(int *x, int *y)
{
	
	if(*x == *y)
	{
		return FAILURE;
	}

	*x = *x ^ *y;	
	*y = *x ^ *y;
	*x = *x ^ *y;
	
	return SUCCESS;
	
}

void swap3(int *x, int *y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}











