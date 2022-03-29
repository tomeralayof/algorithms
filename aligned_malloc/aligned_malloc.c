#include <stdlib.h>
#include <stdio.h>

void *AlignedMalloc(size_t bytes,size_t align);
void FreeMalloc(void *ptr);

int main()
{
    size_t bytes = 1000;
    size_t align = 16;

    void *ptr = AlignedMalloc(bytes,align);
    printf("aligned address is: %p\n",ptr);

    FreeMalloc(ptr);

    return 0;
}

void *AlignedMalloc(size_t bytes,size_t align)
{
    void **user_ptr = NULL;
    size_t off = align - 1 + sizeof(void *);
    void *ptr = (void *)malloc(bytes+off);

    user_ptr = (void *)(((size_t)ptr + off) & ~(align - 1));

    *((void **)user_ptr - 1) = ptr;

    return user_ptr;
}

void FreeMalloc(void *ptr)
{   
    void *p = *((void **)ptr - 1);
    free(p);
}
