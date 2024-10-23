#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL, *tail = NULL;

void newNode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
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

void insert(int val1, int loc)
{
    if (head == NULL && loc != 1)
    {
        printf("Invalid location! The list is empty, you can only insert at position 1.\n");
        return;
    }

    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    p->data = val1;

    if (loc == 1)
    {
        p->next = head;
        tail->next = p;
        head = p;
    }
    else
    {
        Node *q = head;
        for (int i = 1; i <= loc - 2; i++)
        {
            q = q->next;
        }
        if (q == tail)
        {
            q->next = p;
            tail = p;
            tail->next = head;
        }
        else
        {
            p->next = q->next;
            q->next = p;
        }
    }
}

int deletebydata(int val1)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return -1;
    }

    int item;
    Node *q = head, *r = NULL;

    if (head->data == val1)
    {
        if (head == tail)
        {
            item = head->data;
            free(head);
            head = NULL;
            tail = NULL;
        }
        else
        {
            item = head->data;
            tail->next = head->next;
            Node *temp = head;
            head = head->next;
            free(temp);
        }
        return item;
    }

    do
    {
        r = q;
        q = q->next;
    } while (q != head && q->data != val1);

    if (q == head)
    {
        printf("Item not found.\n");
        return -1;
    }

    if (q == tail)
    {
        r->next = head;
        tail = r;
        item = q->data;
        free(q);
        return item;
    }

    r->next = q->next;
    item = q->data;
    free(q);
    return item;
}

int deletebylocation(int loc, int count)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return -1;
    }

    if (loc < 1 || loc > count)
    {
        printf("Invalid location!\n");
        return -1;
    }

    int item;
    Node *q = head, *r = NULL;

    if (loc == 1)
    {
        if (head == tail)
        {
            item = head->data;
            free(head);
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *temp = head;
            tail->next = head->next;
            item = head->data;
            head = head->next;
            free(temp);
        }
        return item;
    }

    for (int i = 1; i < loc - 1; i++)
    {
        q = q->next;
    }
    r = q->next;

    if (r == tail)
    {
        q->next = head;
        tail = q;
        item = r->data;
    }
    else
    {
        q->next = r->next;
        item = r->data;
    }

    free(r);
    return item;
}

void print()
{
    if (head == NULL)
    {
        printf("No DATA found.\n");
        return;
    }

    Node *p = head;
    printf("The data in the linked list is: ");
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
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

    int operation = 0;
    do
    {
        printf("1. Insert\n2. Delete\n3. Exit\nEnter the operation to be performed: ");
        scanf("%d", &operation);
        int val1, loc, item;
        switch (operation)
        {
        case 1:
            printf("Enter data in new node: ");
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
            int delOp;
            scanf("%d", &delOp);
            switch (delOp)
            {
            case 1:
                printf("Enter the data to be deleted: ");
                scanf("%d", &val1);
                item = deletebydata(val1);
                if (item != -1)
                {
                    count--;
                    printf("Item deleted from the list: %d\n", item);
                    print();
                }
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
                    item = deletebylocation(loc, count);
                    if (item != -1)
                    {
                        count--;
                        printf("Item deleted from the list: %d\n", item);
                        print();
                    }
                }
                break;
            default:
                printf("INVALID INPUT!\n");
                break;
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("INVALID INPUT!\n");
            break;
        }
    } while (operation != 3);

    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        if (head == tail->next)
            break;
    }

    return 0;
}
