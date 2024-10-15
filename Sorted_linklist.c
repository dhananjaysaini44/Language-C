//sorting a linked list using bubble sort
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void createnode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));

    if (p == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    else
    {
        p->data = val;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            Node *q = head;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
        }
    }
}

Node *sort(Node *r, int n)
{
    Node *q = r, *s, *t;

    for (int i = 0; i < n - 1; i++)
    {
        s = q;
        t = q->next;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (s->data > t->data)
            {
                int temp = s->data;
                s->data = t->data;
                t->data = temp;
            }
            s = s->next;
            t = t->next;
        }
    }
    return r;
}

void print(Node *r)
{
    Node *q = r;

    if (q == NULL)
    {
        printf("List is Empty\n");
        exit(1);
    }
    else
    {
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
    int n;
    printf("Enter the number of nodes to be created: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Enter data in new node: ");
        scanf("%d", &val);
        createnode(val);
    }

    printf("The list is: ");
    print(head);

    Node *sorted = sort(head, n);

    printf("The sorted list is: ");
    print(sorted);

    return 0;
}