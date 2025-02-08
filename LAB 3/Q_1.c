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

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data=11;
    head->next=second;

    second->data = 112;
    second->next=third;
    
    third->data=8;
    third->next=NULL;
    
	printf("Linked List\n");
    printf("%d ",head->data);
    printf("%d ",second->data);
    printf("%d ",third->data);
	
	free(head);
	free(second);
	free(third);
	
    return 0;
}