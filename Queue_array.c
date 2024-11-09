#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int q[MAX], fr = -1, re = -1;

void enqueue(int item)
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
}

int dequeue()
{
    int item;
    if (fr == -1 && re == -1)
    {
        printf("Queue is Empty\n");
        return 0;
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

void print()
{
    printf("Items in the Queue are: ");
    if (fr == -1 && re == -1)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        for (int i = fr; i <= re; i++)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main()
{
    int a, item;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\nEnter the operation to be perfrmed: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter item into Queue : ");
            scanf("%d", &item);
            enqueue(item);
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
            printf("INVALID OPERATION!");
            break;
        }
    } while (a != 4);
    return 0;
}