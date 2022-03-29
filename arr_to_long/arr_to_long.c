#include <stdio.h>
#include <stdlib.h>



long *SumIntPairsToLong(int *arr,size_t size);

int main()
{
	int arr[] = {1,6,456,-3,8,12};
	int size = sizeof(arr)/sizeof(int);
	int i = 0;
	long *result = SumIntPairsToLong(arr,size);

	for (i = 0; i < size; ++i)
	{
		printf("%ld ",*(result + i));
	}

	printf("\n");

	return 0;
}



long *SumIntPairsToLong(int *arr,size_t size)
{
	size_t i = 0;

	long *result = (long *)arr;

	for (i = 0; i < size; i++)
	{
		result[i] = arr[i];
	}

	return result;
}