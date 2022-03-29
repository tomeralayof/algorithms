#include <stdio.h>

int MaxSubArray(int *arr, size_t size);

int main()
{
	int arr[] = {-2,1,-3,4,-1,2,3,-5,4};
	size_t size = 9;
	
	int result = MaxSubArray(arr,size);
	printf("%d\n",result);
}

int MaxSubArray(int *arr, size_t size)
{
	int max_so_far = 0;
	int max_end_here = 0;
	size_t i =0;
	
	for(i = 0; i < size; ++i)
	{
		max_end_here+= arr[i];
		
		if(max_end_here < 0)
		{
			max_end_here = 0;
		}
		
		if(max_so_far < max_end_here )
		{
			max_so_far = max_end_here;
		}
	}
	
	return max_so_far;
}






