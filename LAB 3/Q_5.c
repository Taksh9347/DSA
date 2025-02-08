#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
int main ()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 12;
    second->next = third;
    
    third->data = 8;
    third->next = fourth;

    fourth->data = 13;
    fourth->next = NULL;
    
    int arr[4];
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = head;
    int i=0;
    while(ptr!=NULL)
    {
        arr[i++] = ptr->data;
        ptr = ptr->next;
    }
    
    printf("Converted Linked List to Array\n");
    for(int j=0;j<4;j++)
    {
        printf("%d ",arr[j]);
    }
	free(head);
	free(second);
	free(third);
	free(ptr);
    return 0;
}