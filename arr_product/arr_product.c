#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void ProductArr(int * arr, size_t size);
static void PrintArr(int *arr,size_t size);
static void UpdateTargetArr(int *arr,int *target_arr, size_t size);

int main()
{
	int arr[] = {1,2,3,4,5};
	size_t size = sizeof(arr)/sizeof(int);
	
	ProductArr(arr,size);
	
	PrintArr(arr,size);
	
	return 0;
} 

void ProductArr(int * arr, size_t size)
{	
	int *target_arr = (int *)malloc(sizeof(int) * size);
	
	UpdateTargetArr(arr,target_arr,size);
	
	memcpy(arr,target_arr,sizeof(int) * size);
	
	free(target_arr);
}

static void UpdateTargetArr(int *arr,int *target_arr, size_t size)
{
	size_t i = 0; 
	size_t k = 0; 
	size_t j = 0;

	int iter_result = 1;

	for(i = 0; i < size; ++i)
	{
		for(j = size - 1; j > i ; --j)
		{
			iter_result*= arr[j];	
		}
		
		for(k = 0; k < i ; ++k)
		{
			iter_result*=arr[k];	
		}
	
		target_arr[i] = iter_result;
		
		iter_result = 1;
	}
}


static void PrintArr(int *arr,size_t size)
{
	
	size_t i = 0;

	for(i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	
	printf("\n");
} 








