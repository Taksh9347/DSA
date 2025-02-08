#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
struct Node * create_first_node(int data)
{
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = ptr;
    return ptr;
}
struct Node * insert_at_end(struct Node * tail,int data)
{
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->next = tail->next;
    tail->next = ptr;
    tail = tail->next;
    return tail;
}
void print_CLL(struct Node * tail)
{
    if(tail == NULL)
    {
        printf("List is Empty");
    }
    else 
    {
        struct Node * temp = tail->next;
        do
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }while(temp!=tail->next);
    }
}
struct Node * del_at_beg(struct Node * tail)
{
    struct Node * temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}
struct Node * del_at_end(struct Node * tail)
{
    struct Node * temp = tail->next;
    if(tail->next==tail)
    {
        free(tail);
        tail = NULL;
    }
    else
    {
        while(temp->next!=tail)
        {
            temp = temp->next;
        }
        temp->next = tail->next;
        free(tail);
        tail = temp;
    }
    return tail;
}
struct Node * del_at_pos(struct Node * tail,int pos)
{
    struct Node * temp , * temp2;
    temp = tail->next;
    while(pos>2)
    {
        temp = temp->next;
        pos--;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    return tail;
}
int main()
{
    struct Node * tail = malloc(sizeof(struct Node));
    int n;
    printf("Number of elements ");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(int i=0;i<n;i++)
    {
        int data;
        scanf("%d",&data);
        if(i==0)
        {
            tail = create_first_node(data);
        }
        else
        {
            tail = insert_at_end(tail,data);
        }
    }
    print_CLL(tail);
    printf("\n");
    while(1)
    {
        int pos;
        printf("\nEnter positon to delete a node (or -1 to exit) -> ");
        scanf("%d",&pos);
        if(pos<=0 || pos>n)
        {
            printf("Invalid Position or Exiting\n");
            return 0;
        }
        if (pos==1 && n!=1)
        {
            tail = del_at_beg(tail);
        }
        else if (pos==n)
        {
            tail = del_at_end(tail);
        }
        else
        {
            tail = del_at_pos(tail,pos);
        }
        n--; // update number of nodes after each successful deletion
        print_CLL(tail);
        if(n==0)
        {
            return 0;
        }
    }
    return 0;
}