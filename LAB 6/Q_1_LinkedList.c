#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
}*top = NULL ;
int isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void show()
{
    struct Node * temp = top;
    printf("STACK ELEMENTS : ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void pop()
{
    struct Node * temp = top;
    if(isEmpty())
    {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    top = top->next;
    printf("Popped Element is %d\n",temp->data);
    free(temp);
    temp = NULL;
}
void peek()
{
    if(isEmpty())
    {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    printf("Top Element is %d\n",top->data);
}
void push(int data)
{
    struct Node * ptr = malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        printf("STACK OVERFLOW"); // cant allocate memory
        exit(1);
    }
    ptr->data = data;
    ptr->next = NULL;
    ptr->next = top;
    top = ptr;
    printf("Pushed %d into the stack\n",data);
}
int main()
{
    printf("1.Push\n2.Pop\n3.Peek\n4.Show\n5.Exit\n");
    while(1)
    {
        printf("Enter choice : ");
        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter value to push : ");
            int data;
            scanf("%d",&data);
            push(data);
            break;

            case 2:
            pop();
            break;

            case 3:
            peek();
            break;

            case 4:
            show();
            break;

            case 5:
            printf("EXITING...");
            return 0;
            break;

            default:
            printf("INVALID CHOICE\n");
            return 0;
            break;
            
        }
    }
    return 0;
}