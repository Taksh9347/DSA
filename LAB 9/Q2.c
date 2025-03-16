#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int dq[MAX];
int f = -1;
int r = -1;

int isFull()
{
    return ((r + 1) % MAX == f);
}

int isEmpty()
{
    return (f == -1 && r == -1);
}

int ins_at_front(int data)
{
    if (isFull())
    {
        printf("Overflow\n");
        return 0;
    }
    if (isEmpty())
        f = r = 0;
    else if (f == 0)
        f = MAX - 1;
    else
        f--;
    
    dq[f] = data;
    return 1;
}

int ins_at_rear(int data)
{
    if (isFull())
    {
        printf("Overflow\n");
        return 0;
    }
    if (isEmpty())
        f = r = 0;
    else if (r == MAX - 1)
        r = 0;
    else
        r++;

    dq[r] = data;
    return 1;
}

void del_at_front()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        return;
    }
    printf("DELETED ELEMENT %d from front\n", dq[f]);

    if (f == r)
        f = r = -1;
    else
        f = (f + 1) % MAX;
}

void del_at_rear()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        return;
    }
    printf("DELETED ELEMENT %d from rear\n", dq[r]);

    if (f == r)
        f = r = -1;
    else if (r == 0)
        r = MAX - 1;
    else
        r--;
}

void Display()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    int x = f;
    printf("Queue: ");
    while (1)
    {
        printf("%d ", dq[x]);
        if (x == r)
            break;
        x = (x + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    printf("1. Insert at front\n");
    printf("2. Insert at rear\n");
    printf("3. Delete at front\n");
    printf("4. Delete at rear\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    while (1)
    {
        int choice, data;
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                ins_at_front(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                ins_at_rear(data);
                break;

            case 3:
                del_at_front();
                break;

            case 4:
                del_at_rear();
                break;

            case 5:
                Display();
                break;

            case 6:
                printf("Exiting..\n");
                return 0;

            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
