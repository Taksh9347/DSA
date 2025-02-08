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
struct Node * mult_pol(struct Node * head1,struct Node * head2,struct Node * head3)
{
    struct Node * p1 = head1;
    struct Node * p2 = head2;
    while(p1!=NULL)
    {
        while(p2!=NULL)
        {
            head3 = insert(head3,p1->coeff * p2->coeff,p1->expo + p2->expo);
            p2 = p2->next;
        }
        p1 = p1->next;
        p2 = head2;
    }
   return head3;
}
struct Node * std_form(struct Node * head)
{
    struct Node * temp = head;
    struct Node * temp2;
    
    if(head == NULL)
    {
        return NULL;
    }
    
    while(temp != NULL && temp->next != NULL)
    {
        if(temp->expo == temp->next->expo) 
        {
            temp->coeff += temp->next->coeff;  
            temp2 = temp->next;                
            temp->next = temp2->next;           // Skip over temp2
            free(temp2);                       
        }
        else
        {
            temp = temp->next; 
        }
    }
    return head;
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
    head1 = std_form(head1);
    print_poly(head1);
    head2 = std_form(head2);
    printf("P2 : ");
    print_poly(head2);
    struct Node * head3 = NULL;
    head3 = mult_pol(head1,head2,head3);
    printf("P1*P2 : ");
    head3 = std_form(head3);
    print_poly(head3);
    return 0;
}