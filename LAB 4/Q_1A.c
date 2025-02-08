#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
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
struct Node *insert_at_beg(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}
struct Node *insert_at_end(struct Node *head, int data)
{
    struct Node *ptr = head;
    struct Node *ptr2 = (struct Node *)malloc(sizeof(struct Node));
    if(head == NULL)
    {
        ptr2->data = data;
        ptr2->next = NULL;
        head = ptr2;
        return head;
    }
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr2->data = data;
    ptr2->next = NULL;
    ptr->next = ptr2;  
    return head;
}
struct Node * insert_at_pos(struct Node *head,int data,int pos)
{
    struct Node * p = head;
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    int i=0;
    while(i != pos-2) // -2 instead of -1 bcoz head is taken as first node and index starts from 0.
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main()
{
    struct Node *head  = NULL;
    head = insert_at_end(head,10);
    head = insert_at_end(head,20);
    head = insert_at_beg(head,30);

    printf("Initial Linked List : ");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    int new_data;
    printf("\nEnter data of node ");
    scanf("%d",&new_data);
    int p;
    printf("Enter position to insert element ");
    scanf("%d",&p);

    int size = len_list(head);
    
    if(p<=0 || p>size+1)
    {
        printf("ERROR: Invalid Position");
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

    printf("Updated Linked List\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
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