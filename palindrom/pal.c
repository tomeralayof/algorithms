#include <stdio.h>
#include <stdlib.h>

typedef struct Node node_t;

int IsPalindrom(node_t * head);

static node_t *SetupList();
static size_t CountElements(node_t * head);
static node_t *GetMiddle(node_t * head,size_t count);
static node_t *ReverseSecondHalf(node_t *head);
static int CheckPalindrom(node_t *head,node_t *middle,node_t *tail);
static node_t *ReverseBack(node_t *middle,node_t *tail);
static void Destroy(node_t *head);

struct Node
{
    int data;
    node_t *next;
};

int main()
{    
   node_t *head = SetupList();
   int result = IsPalindrom(head);
   printf("is palindrom: %d\n",result);
   Destroy(head);

    return 0;
}

static void Destroy(node_t *head)
{
    node_t *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;

        free(temp);
        temp = NULL;
    }
}

int IsPalindrom(node_t *head)
{
    size_t count = CountElements(head);
    node_t *middle = GetMiddle(head,count/2);
    node_t *tail = ReverseSecondHalf(middle);
    int is_pal = CheckPalindrom(head,middle,tail);

    middle = ReverseBack(middle, tail);

    return is_pal;
}

static node_t *ReverseBack(node_t *middle,node_t *tail)
{
    node_t *temp1 = tail;
    node_t *temp2 = tail->next;
    node_t *temp3 = temp2->next;
    
    tail->next = NULL;

    while (temp1 != middle)
    {
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
    }

    middle->next = temp2;

    return middle;
}

static node_t *ReverseSecondHalf(node_t *head)
{
    node_t *temp1 = head;
    node_t *temp2 = head->next;
    node_t *temp3 = temp2->next;

    while (temp3 != NULL)
    {
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
    }

    temp2->next = temp1;

    return temp2;
}

static int CheckPalindrom(node_t *head,node_t *middle,node_t *tail)
{
    while (head != middle && head->data == tail->data)
    {
        tail = tail->next;
        head = head->next;
    }

   return head->data == tail->data;
}

static node_t *GetMiddle(node_t *head,size_t count)
{
    size_t i = 0;

    for (i = 0; i < count; i++)
    {
        head = head->next;
    }

    return head;
}

static size_t CountElements(node_t * head)
{
    size_t count = 0;

    while (head != NULL)
    {
        ++count;    
        head = head->next;
    }
    
    return count;
}

static node_t *SetupList()
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    node_t *second_node = (node_t *)malloc(sizeof(node_t));
    node_t *third_node = (node_t *)malloc(sizeof(node_t));
    node_t *fourth_node = (node_t *)malloc(sizeof(node_t));
    node_t *fifth_node = (node_t *)malloc(sizeof(node_t));
    node_t *sixth_node = (node_t *)malloc(sizeof(node_t));
    node_t *tail = (node_t *)malloc(sizeof(node_t));

    head->data = 2;
    head->next = second_node;

    second_node->data = 3;
    second_node->next = third_node;

    third_node->data = 3;
    third_node->next = fourth_node;

    fourth_node->data = 5;
    fourth_node->next = fifth_node;

    fifth_node->data = 3;
    fifth_node->next = sixth_node;

    
    sixth_node->data = 3;
    sixth_node->next = tail;
    
    tail->data = 2;
    tail->next = NULL;

    return head;
}