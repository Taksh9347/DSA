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
struct Node * del_at_beg(struct Node * head)
{
    struct Node * ptr = head;
    struct Node * temp = head;
    temp = ptr->next;
    free(ptr);
    temp->prev = NULL;
    head = temp;
    return head;
}

struct Node * del_at_end(struct Node * head)
{
    struct Node * temp = head;
    struct Node * ptr = head;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next==NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        free(ptr);
        temp->next = NULL;
    }
    return head;
}
struct Node * del_at_pos(struct Node * head,int pos)
{
    struct Node * temp = head;
    struct Node * ptr = head;
    struct Node * temp2;
    int i=0;
    while(i!=pos-1)
    {
        temp = ptr;
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    temp2 = ptr->next;
    temp2->prev = temp;
    free(ptr);
    return head;
}

int main()
{
    struct Node * head = malloc(sizeof(struct Node));
    head = create(head,10);
    head = insert_at_beg(head,20);
    head = insert_at_beg(head,30);
    head = insert_at_beg(head,40);
    struct Node * temp2;
    temp2 = head;
    printf("Initial Linked List\n");
    while(temp2!=NULL)
    {
        printf("%d ",temp2->data);
        temp2 = temp2->next;
    }
    int size = len_list(head);

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