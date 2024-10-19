#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head1 = NULL, *head2 = NULL;

void newNode1(int val)
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

        if (head1 == NULL)
        {
            head1 = p;
        }
        else
        {
            Node *q = head1;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
        }
    }
}

Node *print(Node *r)
{
    Node *p = r;

    if (p == NULL)
    {
        printf("No DATA Found\n");
        return 0;
    }

    printf("The data in linked list is: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return r;
}

void newNode2(int val)
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

        if (head2 == NULL)
        {
            head2 = p;
        }
        else
        {
            Node *q = head2;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
        }
    }
}

int commonNode(Node *r, int count)
{
    int item = -1;
    if (head1 == NULL || head2 == NULL)
    {
        printf("INVALID Operation.\n");
        exit(1);
    }
    else
    {
        Node *q = r;
        while (count--)
        {
            q = q->next;
            item = q->data;
        }
    }
    return item;
}

int commonNode1(Node *r, Node *s)
{
    int item = -1;
    if (head1 == NULL || head2 == NULL)
    {
        printf("INVALID Operation.\n");
        exit(1);
    }
    else
    {
        Node *p = r, *q = s;
        while (p != NULL)
        {
            q = s;
            while(q != NULL)
            {
                if (p->next == q->next)
                {
                    item = q->data;
                    break;
                }
                q = q->next;
            }
            p = p->next;
        }
    }
    return item;
}

void connect(Node *r, Node *s, int loc)
{
    if (r == NULL || s == NULL || loc <= 0)
    {
        printf("INVALID Operation.\n");
        exit(1);
    }
    else
    {
        Node *q = r, *p = s;
        while (p->next != NULL)
        {
            p = p->next;
        }
        for (int i = 0; i < loc - 1; i++)
        {
            q = q->next;
        }
        p->next = q;
    }
}

int main()
{
    int n1, n2, count1 = 0, count2 = 0;
    printf("Enter the number of nodes to be created in list 1: ");
    scanf("%d", &n1);
    int val;
    for (int i = 0; i < n1; i++)
    {
        printf("Enter the data in new node: ");
        scanf("%d", &val);
        newNode1(val);
        count1++;
    }
    print(head1);
    printf("Enter the number of nodes to be created in list 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter the data in new node: ");
        scanf("%d", &val);
        newNode2(val);
        count2++;
    }
    print(head2);

    int loc, op, item;
    printf("1. Connect list 1 to list 2\n2. Connect list 2 to list 1\nEnter the operation to be performed: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("Enter the location where you want to connect list 1 to list 2: ");
        scanf("%d", &loc);
        if (loc > count2)
        {
            printf("INVALID Location.\n");
        }
        else
        {
            connect(head2, head1, loc);
        }
        print(head1);
        print(head2);

        item = commonNode(head1, count1);
        printf("The common item is: %d", item);
        break;
    case 2:
        printf("Enter the location where you want to connect list 2 to list 1: ");
        scanf("%d", &loc);
        if (loc > count1)
        {
            printf("INVALID Location.\n");
        }
        else
        {
            connect(head1, head2, loc);
        }
        print(head1);
        print(head2);

        item = commonNode1(head1, head2);
        printf("The common item is: %d", item);
        break;
    default:
        printf("INVALID Input.\n");
        break;
    }
    return 0;
}