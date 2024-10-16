#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void newNode(int val)
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

void insert(int val1, int loc)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val1;

    if (loc == 1)
    {
        p->next = head;
        head = p;
    }
    else
    {
        Node *q = head;
        for (int i = 1; i < loc - 1 && q != NULL; i++)
        {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
}

int deletebydata(int val1)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        exit(1);
    }

    Node *q = head, *r = NULL;

    if (head->data == val1)
    {
        int item = head->data;
        head = head->next;
        free(q);
        return item;
    }

    while (q != NULL && q->data != val1)
    {
        r = q;
        q = q->next;
    }
    int item = q->data;
    r->next = q->next;
    free(q);
    return item;
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
        free(q);
        return item;
    }
    else
    {
        Node *q = head, *r = NULL;
        for (int i = 1; i < loc - 1 && q->next != NULL; i++)
        {
            q = q->next;
        }
        r = q->next;
        int item = r->data;
        q->next = r->next;
        free(r);
        return item;
    }
}

void print()
{
    Node *p = head;

    if (p == NULL)
    {
        printf("No DATA Found\n");
        return;
    }

    printf("The data in linked list is: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int n, count = 0;
    printf("Enter the number of nodes to be created: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Enter the data in new node: ");
        scanf("%d", &val);
        newNode(val);
        count++;
    }

    print();

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
                count++;
                print();
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
                print();
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
                    print();
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