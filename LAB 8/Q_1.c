#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node * next;
};
struct Queue 
{
    struct Node * f;
    struct Node * r;
};
void initializeQueue(struct Queue * q) 
{
    q->f = q->r = NULL;
}
int isEmpty(struct Queue* q) 
{
    return (q->f == NULL);
}
void enqueue(struct Queue * q, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->r == NULL) 
    {
        q->f = q->r = newNode;
        return;
    }

    q->r->next = newNode;
    q->r = newNode;
}
int dequeue(struct Queue* q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return 0;  
    }
    struct Node * temp = q->f;
    int dequeuedValue = temp->data;
    q->f = q->f->next;
    if (q->f == NULL) 
    {
        q->r = NULL;  
    }
    free(temp);
    return dequeuedValue;
}
int peek(struct Queue * q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty");
        return 0;
    }
    return q->f->data;
}
void displayQueue(struct Queue * q)
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty!\n");
        return;
    }
    struct Node * temp = q->f;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    struct Queue q;
    initializeQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Initail queue\n");
    displayQueue(&q);
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    printf("4.PEEK\n");
    printf("5.EXIT\n");
    while(1)
    {
        int choice;
        printf("Enter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            {
                int value;
                printf("Enter value : ");
                scanf("%d",&value);
                enqueue(&q,value);
                break;
            }

            case 2:
            printf("Dequeued value: %d\n", dequeue(&q));
            break;

            case 3:
            displayQueue(&q);
            break;
             
            case 4:
            printf("Peeked element is %d\n",peek(&q));
            break;

            case 5:
            printf("EXITING...");
            return 0;
            break;
        }
    }
    return 0;
}