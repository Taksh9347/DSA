#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void Traverse(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main ()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data=11;
    head->next=second;

    second->data = 112;
    second->next=third;
    
    third->data=8;
    third->next=NULL;
    
    printf("Traversing Linked List and printing its elements\n");
    Traverse(head);
    free(head);
    free(second);
    free(third);
    return 0;
}