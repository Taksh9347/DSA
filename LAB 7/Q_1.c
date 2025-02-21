#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
char stack_arr[MAX_SIZE];
char infix[MAX_SIZE],postfix[MAX_SIZE];
int top = -1;
int priority(char symbol)
{
    switch(symbol)
    {
        case '^':
        return 4;
        break;

        case '*':
        case '/':
        return 3;
        break;

        case '+':
        case '-':
        return 2;
        break;

        default:
        return 1;
    }
}
void push(char value)
{
    if(top==MAX_SIZE-1)
    {
        printf("STACK OVERFLOW");
        exit(1);
    }
    stack_arr[++top] = value;
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
char pop()
{
    if(isEmpty())
    {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    return stack_arr[top--];
}
void infix_to_postfix()
{
    int j=0;
    for(int i=0;i<strlen(infix);i++)
    {
        char symbol,next;
        symbol = infix[i];
        switch(symbol)
        {
            case '(':
            push(symbol);
            break;

            case ')':
            while((next=pop())!='(')
            {
                postfix[j++]=next;
            }
            break;

            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
            while(!isEmpty() && priority(stack_arr[top])>=priority(symbol))
            {
                postfix[j++]=pop();
            }
            push(symbol);
            break;

            default:
            postfix[j++]=symbol;
        }
    }
    while(!isEmpty()) // adding remaining operators from stack to postfix expr
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int main()
{
    printf("Enter infix expression\n");
    gets(infix);
    infix_to_postfix();
    int i=0;
    while(postfix[i]!='\0')
    {
        printf("%c",postfix[i++]);
    }
    return 0;
}