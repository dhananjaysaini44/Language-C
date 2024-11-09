#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue *next;
} queue;

queue *fr = NULL, *re = NULL;

void enqueue(int item)
{
    queue *p = (queue *)malloc(sizeof(queue));
    p->data = item;
    p->next = NULL;
    if (fr == NULL && re == NULL)
    {
        fr = p;
        re = p;
    }
    else
    {
        re->next = p;
        re = p;
    }
}

int dequeue()
{
    int item;
    if (fr == NULL && re == NULL)
    {
        printf("Queue is Empty\n");
        return 0;
    }
    item = fr->data;
    if (fr == re)
    {
        free(fr);
        fr = NULL;
        re = NULL;
    }
    else
    {
        queue *q = fr;
        fr = fr->next;
        free(q);
    }
    return item;
}

void print()
{
    printf("Items in the Queue are: ");
    if (fr == NULL && re == NULL)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        queue *q = fr;
        while (q != NULL)
        {
            printf("%d ", q->data);
            q = q->next;
        }
        printf("\n");
    }
}

int main()
{
    int a, item;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\nEnter the operation to be performed: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter item into Queue: ");
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