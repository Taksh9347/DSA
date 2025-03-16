#include<stdio.h>
#include<stdlib.h>
int n = 0; // number of nodes in PQ
struct Node 
{
    int data;
    int prio;
    struct Node *next;
};
struct Queue 
{
    struct Node *f;
    struct Node *r;
};
void initializeQueue(struct Queue *pq) 
{
    pq->f = pq->r = NULL;
}
int isEmpty(struct Queue *pq) 
{
    return pq->f == NULL;
}
void peek(struct Queue *pq) 
{
    if (isEmpty(pq)) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        printf("Max = %d and Min = %d \n", pq->f->data, pq->r->data);
    }
}
void extract_max_min(struct Queue *pq)
{
    if (isEmpty(pq)) 
    {
        printf("Underflow\n");
        return;
    }
    int max_data = pq->f->data;
    int min_data = pq->r->data;
    if(pq->f == pq->r)
    {
        free(pq->f);
        pq->f=pq->r=NULL;
    }
    else 
    {
        struct Node *temp = pq->f;
        pq->f = pq->f->next;
        free(temp);
        struct Node * prev=NULL;
        temp = pq->f;
        while (temp != NULL && temp->next != NULL) 
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        pq->r = prev;
        free(temp);
    }
    n-=2; 
    printf("Max = %d and Min = %d are extracted from the queue\n", max_data, min_data);
}
void Enqueue(struct Queue *pq, int data, int prio) 
{
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prio = prio;
    ptr->next = NULL;

    if (isEmpty(pq)) // First element to be added
    { 
        pq->f = pq->r = ptr;
    } else if (prio > pq->f->prio) 
    { // Highest priority, insert at front
        ptr->next = pq->f;
        pq->f = ptr;
    } 
    else if (prio <= pq->r->prio) 
    { // Lowest priority, insert at rear
        pq->r->next = ptr;
        pq->r = ptr;
    } 
    else 
    { // Insert in the middle
        struct Node *temp = pq->f;
        while (temp->next != NULL && temp->next->prio >= prio) 
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
    n++;
}
void Dequeue(struct Queue *pq, int pos) 
{
    if (isEmpty(pq)) 
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = pq->f;
    struct Node *temp2;
    int deq_data, deq_prio;

    if (pos == 0) 
    { // Deletion from the front
        deq_data = pq->f->data;
        deq_prio = pq->f->prio;
        pq->f = pq->f->next;
        free(temp);
    } 
    else if (pos == n - 1) 
    { // Deletion from the rear
        deq_data = pq->r->data;
        deq_prio = pq->r->prio;
        while (temp->next != pq->r) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(pq->r);
        pq->r = temp;
    } 
    else 
    { // Deletion in between
        while (pos > 1) 
        {
            temp = temp->next;
            pos--;
        }
        temp2 = temp->next;
        deq_data = temp2->data;
        deq_prio = temp2->prio;
        temp->next = temp2->next;
        free(temp2);
    }
    printf("Dequeued element with data=%d and priority=%d\n",deq_data,deq_prio);
    n--;
}
void Display_PQ(struct Queue *pq) 
{
    if (isEmpty(pq))
    {
        printf("Underflow\n");
        return;
    }
    struct Node *temp = pq->f;
    while (temp != NULL) {
        printf("[%d,%d] -> ", temp->data, temp->prio);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() 
{
    struct Queue pq;
    initializeQueue(&pq);
    Enqueue(&pq, 20, 4);
    Enqueue(&pq, 10, 3);
    Enqueue(&pq, 50, 8);
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    printf("4.PEEK\n");
    printf("5.Extract MAX and MIN\n");
    printf("6.EXIT\n");
    while(1)
    {
        int choice,pos;
        printf("Enter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            {
                int value,prio;
                printf("Enter value and priority: ");
                scanf("%d%d",&value,&prio);
                Enqueue(&pq,value,prio);
                break;
            }

            case 2:
            printf("Enter position to dequeue : ");
            scanf("%d",&pos);
            Dequeue(&pq,pos-1);
            break;

            case 3:
            Display_PQ(&pq);
            break;
             
            case 4:
            peek(&pq);
            break;

            case 5:
            extract_max_min(&pq);
            break;

            case 6:
            printf("EXITING...");
            return 0;
            break;
        }
    }
    return 0;
}