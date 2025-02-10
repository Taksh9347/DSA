#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3
int stack_arr[MAX_SIZE];
int top = -1;
void push(int value)
{
    if(top==MAX_SIZE-1)
    {
        printf("STACK OVERFLOW");
        exit(1);
    }
    stack_arr[++top] = value;
    printf("Pushed %d into stack \n",stack_arr[top]);
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void pop()
{
    if(isEmpty())
    {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    printf("Popped element is %d \n",stack_arr[top]);
    top = top-1;
}
void peek()
{
    if(isEmpty())
    {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    printf("Top Element is %d\n",stack_arr[top]);
}
void show()
{
    if(isEmpty())
    {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    int x = top;
    while(x>=0)
    {
        printf("%d ",stack_arr[x]);
        x--;
    }
    printf("\n");
}
int main()
{
    printf("1.Push\n2.Pop\n3.Peek\n4.Show\n5.Exit\n");
    while(1)
    {
        int choice;
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            printf("Enter element to push: ");
            int val;
            scanf("%d",&val);
            push(val);
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
            break;
        }
    }
    return 0;
}