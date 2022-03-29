#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EMPTY_STACK 0

typedef struct stack stack_t; 

int CheckParanteses(const char * str, stack_t * my_stack);
stack_t *StackCreate(size_t num_of_elements, size_t element_size);
void StackPush(stack_t *sptr, const void *element);
void StackPop(stack_t *sptr);
int StackIsEmpty(const stack_t *sptr);
int isMatchingPair(char character1, char character2);
void StackDestroy(stack_t *sptr);
void *StackPeek(const stack_t *sptr);


enum 
{
	FALSE = 0,
	TRUE = 1
};

struct stack
{
	size_t element_size; 
	size_t curr_num_of_stored_elements; 
	size_t num_of_elements; 
	void ** arr;
};


int main()
{
	
	const char * str = "[()](){[()]()}";
	
	size_t num_of_elements = strlen(str);
	size_t element_size = 1;
	int isMatchingPair = 0;
	
	stack_t *my_stack = StackCreate(num_of_elements,element_size);
	
	isMatchingPair = CheckParanteses(str,my_stack);
	
	printf("is matching: %d\n",isMatchingPair);
	
	StackDestroy(my_stack);
	
	
	return 0;
}



stack_t *StackCreate(size_t num_of_elements, size_t element_size)
{
	stack_t *stack = malloc(sizeof(struct stack));
	
	if(NULL == stack)
	{
		return NULL;
	}
	stack -> element_size = element_size;	
	stack -> num_of_elements = num_of_elements;	
	stack -> curr_num_of_stored_elements = EMPTY_STACK;	
    stack -> arr = malloc(num_of_elements * element_size);    
    if(NULL == stack -> arr)
	{
		return NULL;
	}
   
	return stack;	
}

void StackPush(stack_t *sptr, const void *element)
{
	memcpy(sptr -> arr + sptr -> curr_num_of_stored_elements, element, sptr -> element_size);
	++(sptr -> curr_num_of_stored_elements);
}



void StackPop(stack_t *sptr)
{
	--(sptr -> curr_num_of_stored_elements);
}

int StackIsEmpty(const stack_t *sptr)
{
	return sptr -> curr_num_of_stored_elements == EMPTY_STACK;
}

void *StackPeek(const stack_t *sptr)
{
	return  sptr -> arr + sptr -> curr_num_of_stored_elements - 1;
}


void StackDestroy(stack_t *sptr)
{
	free(sptr -> arr);
	sptr -> arr = NULL;
	free(sptr);
	sptr = NULL;
}


int CheckParanteses(const char * str, stack_t * my_stack)
{

	size_t i = 0;
	
	size_t length = strlen(str);
	

	for (i = 0; i < length; ++i)
	{
		void * data = (char *)&str[i];
		
		if (str[i] == '{' || str[i] == '(' || str[i] == '[')
		{
			StackPush(my_stack,data);
		}
		
		if( isMatchingPair(*(char *)StackPeek(my_stack), str[i]) == TRUE)
		{
		
			StackPop(my_stack);
		}
	}
	
	return StackIsEmpty(my_stack) ? TRUE : FALSE;

}


int isMatchingPair(char character1, char character2)
{

	if( character1 == '(' && character2 == ')')
	{
		return TRUE;
	}
	
	if( character1 == '{' && character2 == '}')
	{
		return TRUE;
	}
	
	if(character1 == '[' && character2 == ']')
	{
		return TRUE;
	}
	
	return FALSE;
}











