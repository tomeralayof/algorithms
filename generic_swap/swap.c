#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int *x,int *y);
void SwapPtr(int **x, int **y);
void StupidSwap(int *a, int *b);
void GenSwap(void * data1, void * data2, size_t size);


int main()
{
	
	int x = 10;
	int y = 20;
	
	
    int k = 3, z = 7;
	
	char a = 'a';
	char b = 'b';
	
	void * data1 = &x;
	void *data2 = &y;
	
	void *data3 = &a;
	void *data4 = &b;
	
	printf("x = %d, y = %d\n",x,y);
	
	
    StupidSwap(&x, &y);
    printf("x is: %d, y is: %d\n", x, y);
    
    StupidSwap(&k, &z);
    printf("k is: %d, z is: %d\n", k, z);	
    
    GenSwap(data1,data2,4);
    GenSwap(data3,data4,1);
    printf("x = %d, y = %d\n",x,y);
    printf("a = %c, b = %c\n",a,b);
    
	return 0;
}



void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void SwapPtr(int **x, int **y)
{
	int *temp = *x;
	*x = *y;
	*y = temp;
}


void StupidSwap(int *a, int *b)
{
    int *tmp = a;
    *a = *b;
    *b = *tmp;
}


void GenSwap(void * data1, void * data2, size_t size)
{

	void * temp = (void *)malloc(sizeof(size));

	
	memcpy(temp,data1,size);
	memcpy(data1,data2,size);
	memcpy(data2,temp,size);
		
	free(temp);

}

















