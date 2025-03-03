#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
struct queue 
{
    int size;
    int f, r;
    int *arr;
};
int isEmpty(struct queue *q) 
{
    return q->f == -1;
}
int isFull(struct queue *q) 
{
    return (q->r + 1) % MAX_SIZE == q->f;
}
void Enqueue(struct queue *q, int value) 
{
    if (isFull(q)) 
    {
        printf("Queue is full. Please try again later.\n");
        return;
    }
    if (q->f == -1 && q->r == -1) // CQ is Empty
    {
        q->f = q->r = 0;
    } 
    else // if CQ is non-empty then insert using circular increament
    {
        q->r = (q->r + 1) % MAX_SIZE;
    }
    q->arr[q->r] = value; 
}
int Dequeue(struct queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is Empty\n");
        exit(0);
    }
    int value = q->arr[q->f];
    if (q->f == q->r) // if CQ becomes empty after this deletion then reset f=b=-1
    { 
        q->f = q->r = -1;
    }
    else // if CQ is non empty after deletion then increament front
    {
        q->f = (q->f + 1) % MAX_SIZE;
    }
    printf("Dequeued element is : %d\n", value);
    return value;
}

void display_Q(struct queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->f;
    while (i != q->r) 
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->arr[q->r]);  
}
int peek(struct queue * q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty");
        exit(0);
    }
    return q->arr[q->f];
}
int main() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = MAX_SIZE;  
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);

    display_Q(q);
    Dequeue(q);
    display_Q(q);

    int x = peek(q);
    printf("Peeked element is %d ",x);
    free(q->arr);
    free(q);

    return 0;
}
