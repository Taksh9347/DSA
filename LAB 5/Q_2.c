#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int coeff;
    int expo;
    struct Node * next;
};
void print_poly(struct Node * head)
{
    struct Node * temp = head;
    if(head==NULL)
    {
        printf("Empty Poly\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%dx^%d",temp->coeff,temp->expo);
        if(temp->next != NULL)
        {
            printf(" + ");
        }
        else
        {
            printf("\n");
        }
        temp = temp->next;
    }
}
struct Node * insert(struct Node * head,int coeff,int expo)
{
    struct Node * ptr = malloc(sizeof(struct Node));
    struct Node * temp;
    ptr->coeff = coeff;
    ptr->expo = expo;
    ptr->next = NULL;
    if( head==NULL || expo > head->expo)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        temp = head;
        while(temp->next!=NULL && temp->next->expo > expo)
        {
            temp = temp->next;
        }
        ptr->next = temp->next; // this will also take care of adding term at last
        temp->next = ptr;
    }
    return head;
}
struct Node * create_poly(struct Node * head)
{
    printf("Enter number of terms : ");
    int n,coeff,expo;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter coeff and expo of %d  term\n",i+1);
        scanf("%d%d",&coeff,&expo);
        head = insert(head,coeff,expo);
    }
    return head;
}
struct Node * add_poly(struct Node * head1,struct Node * head2,struct Node * head3)
{
    struct Node * p1 = head1;
    struct Node * p2 = head2;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->expo==p2->expo)
        {
            head3 = insert(head3,p1->coeff+p2->coeff,p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->expo>p2->expo)
        {
            head3 = insert(head3,p1->coeff,p1->expo);
            p1 = p1->next;
        }
        else if (p1->expo<p2->expo)
        {
            head3 = insert(head3,p2->coeff,p2->expo);
            p2 = p2->next;
        }
    }
    while(p1!=NULL)
    {
        head3 = insert(head3,p1->coeff,p1->expo);
        p1 = p1->next;
    }
    while(p2!=NULL)
    {
        head3 = insert(head3,p2->coeff,p2->expo);
        p2 = p2->next;
    }
    return head3;
}
int main()
{
    struct Node * head1 = NULL;
    struct Node * head2 = NULL;
    printf("Input Poly1\n");
    head1 = create_poly(head1);
    printf("Input Poly2\n");
    head2 = create_poly(head2);
    printf("P1 : ");
    print_poly(head1);
    printf("P2 : ");
    print_poly(head2);
    struct Node * head3 = NULL;
    head3 = add_poly(head1,head2,head3);
    printf("P1+P2 : ");
    print_poly(head3);
    return 0;
}