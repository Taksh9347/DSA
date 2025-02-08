#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
struct Node * insert_end(struct Node *ptr,int data)
{
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    ptr->next = temp;
    return temp;
}
void Print_Linked_List(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main ()
{
    int n;
	printf("Enter number of Elements of array\n");
	scanf("%d",&n);
	printf("Enter elements\n");
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
    struct Node *head,*ptr;
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            ptr1->data = arr[i];
            ptr1->next = NULL;
            head = ptr1;
            ptr = head;
        }
        else
        {
            ptr = insert_end(ptr,arr[i]);
        }
    }
    printf("Converted Array to Linked List\n");
    Print_Linked_List(head);
	free(ptr1);
	free(ptr);
	free(head);
    return 0;
}