#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int data, prior;
    struct Queue *next, *prev;
} queue;

queue *fr = NULL, *re = NULL;

void enqueue(int item, int prior)
{
    queue *p = (queue *)malloc(sizeof(queue));
    p->data = item;
    p->prior = prior;
    p->next = NULL;
    p->prev = NULL;
    if (fr == NULL && re == NULL)
    {
        fr = p;
        re = p;
    }
    else
    {
        p->prev = re;
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
    if (fr == re)
    {
        item = fr->data;
        free(fr);
        fr = NULL;
        re = NULL;
    }
    else
    {
        queue *q = fr, *p = fr;
        int m = fr->prior;
        while (q != NULL)
        {
            if (q->prior < m)
            {
                m = q->prior;
                p = q;
            }
            q = q->next;
        }
        item = p->data;
        if (p == fr)
        {
            fr = fr->next;
            fr->prev = NULL;
        }
        else if (p == re)
        {
            p->prev->next = NULL;
            re = p->prev;
        }
        else 
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
        free(q);
    }
    return item;
}

void print()
{
    if (fr == NULL && re == NULL)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Items in the Queue are: ");
        queue *q = fr;
        while (q != NULL)
        {
            printf("%d ", q->data);
            q = q->next;
        }
        printf("\nAnd their priority are: ");
        q = fr;
        while (q != NULL)
        {
            printf("%d ", q->prior);
            q = q->next;
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