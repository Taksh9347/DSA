#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node * prev;
    int data;
    struct Node * next;
};
struct Node * create(struct Node * head,int data)
{
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    head = ptr;
    return head;
}
int len_list(struct Node * head)
{
    int count=0;
    struct Node * ptr = head;
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
struct Node * insert_at_beg(struct Node * head,int data)
{
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}
struct Node * insert_at_end(struct Node *head,int data)
{
    struct Node * ptr = malloc(sizeof(struct Node));
    struct Node * temp;
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    temp=head;
    if(head == NULL)
    {
        head = ptr;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->prev = temp;
    return head;
}
struct Node * insert_at_pos(struct Node * head,int data,int pos)
{
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    struct Node * temp,* temp2;
    temp = head;
    int i=0;
    while(i!=pos-2)
    {
        temp = temp->next;
        i++;
    }
    temp2 = temp->next;
    temp->next = ptr;
    temp2->prev = ptr;
    ptr->prev = temp;
    ptr->next = temp2;
    return head;
}  
int main()
{
    struct Node * head = malloc(sizeof(struct Node));
    head = create(head,120);
    head = insert_at_beg(head,260);
    head = insert_at_end(head,340);
    struct Node * temp2;
    temp2 = head;
    printf("Initial Linked List\n");
    while(temp2!=NULL)
    {
        printf("%d ",temp2->data);
        temp2 = temp2->next;
    }
    int size = len_list(head);
    int new_data;
    printf("\nEnter data of node : ");
    scanf("%d",&new_data);
    int p;
    printf("Enter position : ");
    scanf("%d",&p);
    
    if(p<=0 || p>size+1)
    {
        printf("ERROR! Invalid Position");
        return 0;
    }
    if(p==1)
    {
        head = insert_at_beg(head,new_data);
    }
    else if(p==size+1)
    {
        head = insert_at_end(head,new_data);
    }
    else
    {
        head = insert_at_pos(head,new_data,p);
    }
    
    temp2 = head;
    printf("Updated Linked List\n");
    while(temp2!=NULL)
    {
        printf("%d ",temp2->data);
        temp2 = temp2->next;
    }
    temp2 = head;
    while(temp2!=NULL)
    {
        struct Node * next_node = temp2->next;
        free(temp2);
        temp2 = next_node;
    }
    head = NULL;
    return 0;
}