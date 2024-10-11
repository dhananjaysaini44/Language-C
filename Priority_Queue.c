#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int q[100], p[100], fr = -1, re = -1;

void inqueue(int *q, int *p, int *fr, int *re, int n, int item, int prior)
{
    if (*re == n - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (*re == -1)
    {
        (*re)++;
        (*fr)++;
    }
    else
    {
        (*re)++;
    }
    q[*re] = item;
    p[*re] = prior;
}

int dequeue(int *q, int *fr, int *re)
{
    int item;
    if (*fr == -1)
    {
        printf("Queue is Empty\n");
        exit(0);
    }
    item = q[*fr];
    if (*fr == *re)
    {
        *fr = -1;
        *re = -1;
    }
    else
    {
        (*fr)++;
    }
    return item;
}

void sortQueue(int *q, int *p, int *fr, int *re, int n)
{
    if (*fr == -1)
    {
        return;
    }
    int i, j, flag, size;

    if (*fr <= *re)
    {
        size = *re - *fr + 1;
    }
    else
    {
        size = n - *fr + *re + 1;
    }

    for (i = 0; i < size - 1; i++)
    {
        for (j = *fr; j < *re; j++)
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

int main()
{
    int n, i;
    printf("Enter the size of Queue : ");
    scanf("%d", &n);
    int item, prior;

    for (i = 0; i < n; i++)
    {
        printf("Enter item and their priority into Queue : ");
        scanf("%d%d", &item, &prior);
        inqueue(q, p, &fr, &re, n, item, prior);
    }

    int m;
    printf("Enter the number of items to be dequeued : ");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        int temp = dequeue(q, &fr, &re);
        printf("Dequeued item : %d\n", temp);
    }

    if (fr == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        sortQueue(q, p, &fr, &re, n);

        printf("Queue contents : ");
        for (i = fr; i <= re; i++)
        {
            printf("%d ", q[i]);
        }

        printf("\nTheir Priority : ");
        for (i = fr; i <= re; i++)
        {
            printf("%d ", p[i]);
        }
    }
    return 0;
}
