#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
} Node;

Node *head = NULL;

void createnode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    else
    {
        p->data = val;
        p->next = NULL;
        p->prev = NULL;

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
            p->prev = q;
        }
    }
}

void insert(int val1, int loc)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val1;

    if (loc == 1)
    {
        p->next = head;
        head->prev = p;
        p->prev = NULL;
        head = p;
    }
    else
    {
        Node *q = head, *r;
        for (int i = 1; i < loc - 1 && q != NULL; i++)
        {
            q = q->next;
        }
        if (q->next == NULL)
        {
            p->next = NULL;
            q->next = p;
            p->prev = q;
        }
        else
        {
            r = q->next;
            q->next = p;
            p->prev = q;
            p->next = r;
            r->prev = p;
        }
    }
}

int deletebydata(int val1)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        exit(1);
    }

    Node *q = head, *r, *s;

    if (head->data == val1)
    {
        int item = head->data;
        head = head->next;
        head->prev = NULL;
        free(q);
        return item;
    }
    else
    {
        while (q != NULL && q->data != val1)
        {
            r = q;
            q = q->next;
        }
        int item = q->data;
        s = q->next;
        r->next = s;
        s->prev = r;
        free(q);
        return item;
    }
}

int deletebylocation(int loc)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        exit(1);
    }

    if (loc == 1)
    {
        Node *q = head;
        int item = head->data;
        head = head->next;
        head->prev = NULL;
        free(q);
        return item;
    }
    else
    {
        Node *q = head, *r = NULL, *s;
        for (int i = 1; i <= loc - 1 && q->next != NULL; i++)
        {
            r = q;
            q = q->next;
        }
        if (q->next == NULL)
        {
            r = q;
            int item = q->data;
            q = q->prev;
            free(r);
            q->next = NULL;
            return item;
        }
        else
        {
            int item = q->data;
            s = q->next;
            r->next = s;
            s->prev = r;
            free(q);
            return item;
        }
    }
}

void printforward(Node *r)
{
    if (r == NULL)
    {
        printf("No DATA found!\n");
        exit(1);
    }
    else
    {
        Node *q = r;
        while (q != NULL)
        {
            printf("%d ", q->data);
            q = q->next;
        }
        printf("\n");
    }
}

void printbackword(Node *r)
{
    if (r == NULL)
    {
        printf("No DATA found\n");
        exit(1);
    }
    else
    {
        Node *q = r;
        while (q->next != NULL)
        {
            q = q->next;
        }
        while (q != NULL)
        {
            printf("%d ", q->data);
            q = q->prev;
        }
        printf("\n");
    }
}

int main()
{
    int n, count = 0;
    printf("Enter number of nodes to be created: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Enter data in new node: ");
        scanf("%d", &val);
        createnode(val);
        count++;
    }

    printf("The list printed forward is: ");
    printforward(head);

    printf("The list printed backward is: ");
    printbackword(head);

    int t;
    printf("Enter the number of test cases: ");
    scanf("%d", &t);
    while (t--)
    {
        printf("1. Insert\n2. Delete\nEnter the operation to be performed: ");
        int operation;
        scanf("%d", &operation);
        int val1, loc, item;
        switch (operation)
        {
        case 1:
            printf("Enter data for new node: ");
            scanf("%d", &val1);
            printf("Enter the location at which element has to be inserted: ");
            scanf("%d", &loc);
            if (loc > count + 1)
            {
                printf("INVALID Location!\n");
            }
            else
            {
                insert(val1, loc);
                printf("The list printed forward is: ");
                count++;
                printforward(head);
                printf("The list printed backward is: ");
                printbackword(head);
            }
            break;
        case 2:
            printf("1. Delete by data\n2. Delete by location\nEnter the sub-operation to be performed: ");
            int delop;
            scanf("%d", &delop);
            switch (delop)
            {
            case 1:
                printf("Enter the data to be deleted: ");
                scanf("%d", &val1);
                item = deletebydata(val1);
                count--;
                printf("Item deleted from the list: %d\n", item);

                printf("The list printed forward is: ");
                printforward(head);

                printf("The list printed backward is: ");
                printbackword(head);
                break;
            case 2:
                printf("Enter the location of the node to be deleted: ");
                scanf("%d", &loc);
                if (loc > count)
                {
                    printf("INVALID Location!\n");
                }
                else
                {
                    item = deletebylocation(loc);
                    printf("Item deleted from the list: %d\n", item);
                    count--;
                    printf("The list printed forward is: ");
                    printforward(head);

                    printf("The list printed backward is: ");
                    printbackword(head);
                }
                break;
            default:
                printf("INVALID INPUT\n");
                break;
            }
            break;
        default:
            printf("INVALID INPUT\n");
            break;
        }
    }

    return 0;
}