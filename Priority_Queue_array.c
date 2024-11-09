#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int q[MAX], p[MAX], fr = -1, re = -1;

void enqueue(int item, int prior)
{
    if (re == MAX - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (re == -1)
    {
        re++;
        fr++;
    }
    else
    {
        re++;
    }
    q[re] = item;
    p[re] = prior;
}

int dequeue()
{
    int item;
    if (fr == -1)
    {
        printf("Queue is Empty\n");
        exit(0);
    }
    item = q[fr];
    if (fr == re)
    {
        fr = -1;
        re = -1;
    }
    else
    {
        fr++;
    }
    return item;
}

void sortQueue()
{
    if (fr == -1)
    {
        return;
    }
    int i, j, flag, size;

    if (fr <= re)
    {
        size = re - fr + 1;
    }
    else
    {
        size = MAX - fr + re + 1;
    }

    for (i = 0; i < size - 1; i++)
    {
        for (j = fr; j < re; j++)
        {
            if (p[j] > p[j + 1])
            {
                flag = p[j];
                p[j] = p[j + 1];
                p[j + 1] = flag;
                flag = q[j];
                q[j] = q[j + 1];
                q[j + 1] = flag;
            }
        }
    }
}

void print()
{
    sortQueue();
    if (fr == -1 && re == -1)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Items in the Queue are: ");
        for (int i = fr; i <= re; i++)
        {
            printf("%d ", q[i]);
        }
        printf("\nAnd their priority are: ");
        for (int i = fr; i <= re; i++)
        {
            printf("%d ", p[i]);
        }
        printf("\n");
    }
}

int main()
{
    int a, item, prior;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\nEnter the operation to be performed: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter item and their priority into Queue: ");
            scanf("%d%d", &item, &prior);
            enqueue(item, prior);
            break;
        case 2:
            item = dequeue();
            printf("Item dequeued from the Queue: %d\n", item);
            break;
        case 3:
            print();
            break;
        case 4:
            printf("Exting...");
            exit(1);
            break;
        default:
            printf("INVALID OPERATION!\n");
            break;
        }
    } while (a != 4);
    return 0;
}