#include <stdio.h>

int IsSumFound(int *arr, int sum,size_t size);

enum 
{
	FALSE,
	TRUE
};


int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int sum = 10;
	int result = 0;
	size_t size = sizeof(arr) / sizeof(int);
	
	
	result = IsSumFound(arr,sum,size);
	
	printf("%d\n",result);

	return 0;
}


int IsSumFound(int *arr, int sum,size_t size)
{
	
	int *arr_end = arr + size -1;
	
	
	while(arr < arr_end)
	{
		
		if((*arr + *(arr_end)) > sum )
		{
			--arr_end;
		}
		
		if((*arr + *(arr_end)) < sum )
		{
			

			++arr;
		}
		
		if((*arr + *(arr_end)) == sum )
		{

			return TRUE;
		}
		
	}
	

	return FALSE;
}












