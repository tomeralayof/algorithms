#include <stdio.h>

void Bursa(int *arr,size_t size, int *result);

int main()
{
    int i = 0;                       
	int arr[9] = {6,12,3,5,1,4,9,2,20};
	size_t size = sizeof(arr)/sizeof(int);
	int result[3] = {0};
	
	Bursa(arr,size,result);
	
	for(i = 0; i < 3; ++i)
	{
		printf("%d\n",result[i]);
	}
	
	
	return 0;
}

void Bursa(int *arr,size_t size, int *result)
{
	
	size_t i = 0;
	size_t j = 1;
	int min = arr[0];
	int cur_max = 0;
	int max = 0;
	
	while(j < size)
	{	

		cur_max = arr[j] - min;	
		
		if(arr[j] < min)
		{
			min = arr[j];
			i = j;	
		}

		if(cur_max > max)		
		{
			max = cur_max;
			result[0] = i;
			result[1] = j;
			result[2] = max;
		}

		++j;
	}		
} 