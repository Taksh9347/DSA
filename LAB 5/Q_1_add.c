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
struct Node * insert_at_beg(struct Node * tail,int data)
{
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = tail->next;
    tail->next = ptr;
    return tail;
}
struct Node * insert_at_pos(struct Node * tail,int data,int pos)
{
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    struct Node * temp = tail->next;
    while(pos>2)
    {
        temp = temp->next;
        pos--;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    return tail; 
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
    struct Node * temp = tail->next;
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!=tail->next);
}
int main()
{
    struct Node * tail = malloc (sizeof(struct Node));
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
        printf("\nEnter positon to enter new node (or -1 to exit) -> ");
        scanf("%d",&pos);
        if(pos<=0 || pos>n+2)
        {
            printf("Invalid Position or Exiting\n");
            return 0;
        }
        int data;
        printf("Enter data of node ");
        scanf("%d",&data);
        if(pos==1)
        {
            tail = insert_at_beg(tail,data);
        }
        else if (pos==n+1)
        {
            tail = insert_at_end(tail,data);
        }
        else
        {
            tail = insert_at_pos(tail,data,pos);
        }
        n++; // update number of nodes after each successful insertion
        print_CLL(tail);
    }
    return 0;
}