#include <stdio.h>

#include "../../ds/include/stack.h"
#include "../../ds/stack/stack.c"

void IterativeStackSort();
void RecursiveStackSort();

static void SortIter(stack_t *stack,stack_t *aux);
static void RecSort(stack_t *stack);
static void SortStack(stack_t *stack,int val);

int main()
{
    IterativeStackSort();
    RecursiveStackSort();

    return 0;
}


void IterativeStackSort()
{
    size_t num_of_elements = 10;
    stack_t *stack = StackCreate(num_of_elements,sizeof(int));
    stack_t *aux = StackCreate(num_of_elements,sizeof(int));


    int x1 = 10;
    int x2 = 9;
    int x3 = 500;
    int x4 = 3;
    int x5 = 1;
    int x6 = 6;
    int x7 = 7;
    int x8 = 1000;
    int x9 = 6000;
    int x10 = 5;
    int i = 0;

    StackPush(stack,&x1);
    StackPush(stack,&x2);
    StackPush(stack,&x3);
    StackPush(stack,&x4);
    StackPush(stack,&x5);
    StackPush(stack,&x6);
    StackPush(stack,&x7);
    StackPush(stack,&x8);
    StackPush(stack,&x9);
    StackPush(stack,&x10);


    SortIter(stack,aux);

    printf("sorted stack iterative = [");    
    for (i = 0; i < 10; i++)
    {
        printf("%d ",*(int *)StackPeek(stack));
        if (i < 9)
        {
           printf(",");
        }
        
        StackPop(stack);
    }
    printf("]\n");

    StackDestroy(stack);
    StackDestroy(aux);
}



void RecursiveStackSort()
{
    size_t num_of_elements = 10;
    stack_t *stack = StackCreate(num_of_elements,sizeof(int));

    int x1 = 10;
    int x2 = 9;
    int x3 = 500;
    int x4 = 3;
    int x5 = 1;
    int x6 = 6;
    int x7 = 7;
    int x8 = 1000;
    int x9 = 6000;
    int x10 = 5;
    int i = 0;

    StackPush(stack,&x1);
    StackPush(stack,&x2);
    StackPush(stack,&x3);
    StackPush(stack,&x4);
    StackPush(stack,&x5);
    StackPush(stack,&x6);
    StackPush(stack,&x7);
    StackPush(stack,&x8);
    StackPush(stack,&x9);
    StackPush(stack,&x10);


    RecSort(stack);

    printf("sorted stack recursive = [");    
    for (i = 0; i < 10; i++)
    {
        printf("%d ",*(int *)StackPeek(stack));
        if (i < 9)
        {
           printf(",");
        }
        
        StackPop(stack);
    }
    printf("]\n");

    StackDestroy(stack);
}


static void RecSort(stack_t *stack)
{
    int val = 0;

    if (StackIsEmpty(stack))
    {
        return;
    }

    val = *(int *)StackPeek(stack);
    StackPop(stack);
    RecSort(stack);
    SortStack(stack,val);
}

static void SortStack(stack_t *stack,int val)
{
    if (StackIsEmpty(stack) || val < *(int *)StackPeek(stack))
    {
       StackPush(stack,&val);
    }
    else
    {
        int temp = *(int *)StackPeek(stack);
        StackPop(stack);
        SortStack(stack,val);
        StackPush(stack,&temp);
    }
}

static void SortIter(stack_t *stack,stack_t *aux)
{
    size_t i = 0;
    for (i = 0; i < StackSize(stack); i++)
    {
        StackPush(aux,StackPeek(stack));
        StackPop(stack);
    }
    
    while (!StackIsEmpty(aux))
    {
        int temp = *(int *)StackPeek(aux);
        StackPop(aux);

        while (!StackIsEmpty(stack) && *(int *)StackPeek(stack) < temp)
        {
            StackPush(aux,StackPeek(stack));
            StackPop(stack);
        }

        StackPush(stack,&temp);
    }
}
