#include <stdio.h>

void swap(int *x, int *y);
void SortArr(int *arr, int size);
void Print(int * arr,int size);

int main()
{

	int arr[] = {0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1};
	int size = sizeof(arr) / sizeof(int);
	SortArr(arr,size);
	Print(arr,size);

	return 0;
}

void SortArr(int *arr, int size)
{

	int *s = arr;
	int *e = arr + size - 1;
	
	while(s < e)
	{	
		if(*s == 0 )
		{
			++s;
		}
	
		if(*e == 1)
		{
			--e;
		}
		
		if(*e == 0 && *s == 1)
		{
			swap(s,e);
		}
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


void Print(int * arr,int size)
{
    int i = 0;       	
	for(i = 0; i < size; ++i)
	{
		printf("%d ",arr[i]);
	}
	
	printf("\n");

}












