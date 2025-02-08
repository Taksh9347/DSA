#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
struct Node * insert_begining(struct Node *head,int data)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;   
    ptr->data = data;    
    head = ptr;
    return head;
}
void Print_Linked_List(struct Node *ptr)
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
    
	printf("Enter data you want to insert at begining\n");
	int d;
	scanf("%d",&d);

    printf("List Before insertion\n");
    Print_Linked_List(head);
    printf("After insertion\n");
    head = insert_begining(head,d);
    Print_Linked_List(head);
	
	free(head);
	free(second);
	free(third);

    return 0;
}