// Circular Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head, *tail;

void newNode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;

    if (head == NULL)
    {
        head = p;
        tail = p;
        tail->next = head;
    }
    else
    {
        tail->next = p;
        tail = p;
        tail->next = head;
    }
}

void insertatfront(int val1)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val1;
    p->next = head;
    tail->next = p;
    head = p;
}

void insertatmid(int val1, int loc)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val1;
    Node *q = head;
    for (int i = 1; i <= loc - 2; i++)
    {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
}

void insertatend(int val1)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val1;
    tail->next = p;
    tail = p;
    tail->next = head;
}

int deletebydata(int val1)
{
    int item;
    if (head == NULL)
    {
        printf("List is empty!\n");
        exit(1);
    }

    Node *q = head, *r;
    if (head->data == val1)
    {
        if (head == tail)
        {
            item = head->data;
            free(head);
            head = NULL;
            tail = NULL;
            return item;
        }
        else
        {
            q = head;
            item = head->data;
            tail->next = head->next;
            head = head->next;
            free(q);
            return item;
        }
    }

    do
    {
        r = q;
        q = q->next;
    } while (q != head && q->data != val1);

    if (q == head)
    {
        printf("Item not found\n");
        return 0;
    }

    if (q == tail)
    {
        r->next = head;
        tail = r;
        item = q->data;
    }
    else
    {
        r->next = q->next;
        item = q->data;
    }

    free(q);
    return item;
}

int deletefromfront()
{
    int item;
    if (head == tail)
    {
        item = head->data;
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node *q = head;
        tail->next = head->next;
        item = head->data;
        head = head->next;
        free(q);
    }
    return item;
}

int deletefrommid(int loc)
{
    int item;
    Node *q = head;
    Node *r;
    for (int i = 1; i <= loc - 2; i++)
    {
        q = q->next;
    }
    r = q->next;
    item = r->data;
    q->next = r->next;
    free(r);
    return item;
}

int deletefromend()
{
    int item;
    Node *q = head;
    while (q->next->next != head)
    {
        q = q->next;
    }
    item = tail->data;
    q->next = head;
    free(tail);
    tail = q;
    tail->next = head;
    return item;
}

void print()
{
    Node *p;
    p = head;

    if (p == NULL)
    {
        printf("No DATA Found\n");
        exit(1);
    }
    else
    {
        printf("The data in linked list is: ");
        do
        {
            printf("%d ", p->data);
            p = p->next;
        } while (p != head);
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes to be created: ");
    scanf("%d", &n);

    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        int val;
        printf("Enter the data in new node: ");
        scanf("%d", &val);
        newNode(val);
        count++;
    }

    print();

    int t;
    printf("Enter the number of test casses: ");
    scanf("%d", &t);
    while (t--)
    {
        printf("1. Insert\n2. Delete\nEnter the operation to be performed: ");
        int n;
        scanf("%d", &n);
        int val1, n1, loc, n2, item;
        switch (n)
        {
        case 1:
            printf("1. At Front\n2. At mid\n3. At End\nEnter the sub-operation to be performed: ");
            scanf("%d", &n1);
            switch (n1)
            {
            case 1:
                printf("Enter data in new node: ");
                scanf("%d", &val1);
                insertatfront(val1);
                count++;
                print();
                break;
            case 2:
                printf("Enter data in new node: ");
                scanf("%d", &val1);
                printf("Enter the location at which element has to be inserted: ");
                scanf("%d", &loc);
                if (loc > count)
                {
                    printf("INVALID INPUT\n");
                }
                else
                {
                    insertatmid(val1, loc);
                    count++;
                }
                print();
                break;
            case 3:
                printf("Enter data in new node: ");
                scanf("%d", &val1);
                insertatend(val1);
                count++;
                print();
                break;
            default:
                printf("INVALID INPUT\n");
                break;
            }
            break;
        case 2:
            printf("1. Delete by data\n2. Delete by location\nEnter the sub-operation to be performed: ");
            scanf("%d", &n1);
            switch (n1)
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
                printf("1. From Front\n2. From Mid\n3. From End\nEnter the sub-operation to be performed: ");
                scanf("%d", &n2);
                switch (n2)
                {
                case 1:
                    item = deletefromfront();
                    count--;
                    printf("Item deleted from the list: %d\n", item);
                    print();
                    break;
                case 2:
                    printf("Enter the location of the node to be deleted: ");
                    scanf("%d", &loc);
                    if (loc < count)
                    {
                        item = deletefrommid(loc);
                        count--;
                        printf("Item deleted from the list: %d\n", item);
                    }
                    else
                    {
                        printf("INVALID INPUT\n");
                    }
                    print();
                    break;
                case 3:
                    item = deletefromend();
                    count--;
                    printf("Item deleted from the list: %d\n", item);
                    print();
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
            break;
        default:
            printf("INVALID INPUT\n");
            break;
        }
    }
    return 0;
}