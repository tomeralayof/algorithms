

#include <stdio.h>

long *ArrIntToLong(int *arr,size_t length);

int main()
{

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    size_t length = sizeof(arr) / sizeof(int);
    size_t i = 0;

    ArrIntToLong(arr,length);

    printf(" long arr = [");
    for (i = 0; i < length; i+=2)
    {
        printf("%ld ",*(long *)(arr + i));
        if (i < length - 2)
        {
            printf(",");
        }
    }
    printf("]\n");

    return 0;
}


long *ArrIntToLong(int *arr,size_t length)
{
    size_t i = 0;

    for (i = 0; i < length; i+=2)
    {
        *(long *)(arr + i) = (long)arr[i] + arr[i + 1];
    }
    
    return (long *)arr;
}