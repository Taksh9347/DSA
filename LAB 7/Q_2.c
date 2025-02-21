#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX_SIZE 100
int stack_arr[MAX_SIZE];
char postfix[MAX_SIZE];
int top = -1;
void push(int value)
{
    if(top==MAX_SIZE-1)
    {
        printf("STACK OVERFLOW");
        exit(1);
    }
    stack_arr[++top] = value; // push string onto stack
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
int pop()
{
    if(isEmpty())
    {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    return stack_arr[top--];
}
int postfix_to_infix()
{
    int j=0;
    for(int i=0;i<strlen(postfix);i++)
    {
        char symbol = postfix[i];
        if(symbol>='0'&&symbol<='9')
        {
            push(symbol-'0'); // -'0' converts char to int
        }
        else if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
        {
            int operand1=pop();
            int operand2=pop();
            switch(symbol)
            {
                case '+':
                push(operand2+operand1);
                break;

                case '-':
                push(operand2-operand1);
                break;

                case '*':
                push(operand2*operand1);
                break;

                case '/':
                if(operand1==0)
                {
                    printf("ZeroDivisionERROR");
                    exit(0);
                }
                else
                {
                    push(operand2/operand1);
                }
                break;

                case '^':
                push(pow(operand2,operand1));
                break;

                default:
                printf("Invalid Operator encountered");
                break;
            }
        }
    }
    return pop();
}
int main()
 {
    printf("Enter postfix expression\n");
    fgets(postfix,sizeof(postfix),stdin);
    printf("%d",postfix_to_infix());
    return 0;
}