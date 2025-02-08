#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
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
struct Node * insert_at_end(struct Node * head, int data)
{
    struct Node *ptr = head;
    struct Node *ptr2 = (struct Node *)malloc(sizeof(struct Node));
    
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr2->data = data;
    ptr2->next = NULL;
    ptr->next = ptr2;  
    return head;
}
struct Node * del_at_end(struct Node * head)
{
    struct Node * ptr = head;
    struct Node * temp = head;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head = NULL;
    }
    else 
    {
        while(ptr->next!=NULL) // temp will point node before that of ptr
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
    }
    return head;
}
struct Node * del_at_beg(struct Node * head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node * del_at_pos(struct Node * head,int pos)
{
    struct Node * temp, * ptr;
    temp = head;
    ptr = head;
    int i=0;
    while(i!=pos-1)
    {
        temp = ptr;
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    free(ptr);
    return head;
}
int main()
{
    struct Node * head = malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;    
    head = insert_at_end(head,20);
    head = insert_at_end(head,30);
    head = insert_at_end(head,40);
    
    int size = len_list(head);
    struct Node * temp = head;
    printf("Initial Linked List\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }

    int p;
    printf("\nEnter position to delete Node : ");
    scanf("%d",&p);

    if(p<=0 || p>size)
    {
        printf("ERROR! Invalid Position");
        return 0;
    }
    else if(p==size)
    {
        head = del_at_end(head);
    }
    else if(p==1)
    {
        head = del_at_beg(head);
    }
    else
    {
        head = del_at_pos(head,p);
    }
    printf("Updated List\n");
    temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL)
    {
        struct Node * next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    head = NULL;
    return 0;
}