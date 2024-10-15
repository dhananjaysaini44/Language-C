#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
}Node;

Node *head = NULL;  

void newNode(int val) 
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;

    if (head == NULL) 
    {
        head = p;  
    } else 
    {
        Node *q = head;
        while (q->next != NULL) 
        {  
            q = q->next;
        }
        q->next = p;  
    }
}

void insertatfront(int val1) 
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val1;
    p->next = head;
    head = p;  
}

void insertatmid(int val1, int loc) 
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val1;

    if (loc == 1) 
    {  
        insertatfront(val1);
        return;
    }

    Node *q = head;
    for (int i = 1; i < loc - 1 && q != NULL; i++) 
    { 
        q = q->next;
    }

    if (q != NULL) 
    {
        p->next = q->next;
        q->next = p;  
    } else 
    {
        printf("Invalid location!\n");
    }
}

int deletebydata(int val1) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return -1;
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

    if (q == NULL) 
    {
        printf("Item not found\n");
        return -1;
    }

    int item = q->data;
    r->next = q->next; 
    free(q);
    return item;
}

int deletefromfront() 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return -1;
    }

    Node *q = head;
    int item = head->data;
    head = head->next;  
    free(q);
    return item;
}

int deletefrommid(int loc) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return -1;
    }

    if (loc == 1) 
    {  
        return deletefromfront();
    }

    Node *q = head, *r = NULL;
    for (int i = 1; i < loc - 1 && q->next != NULL; i++) 
    { 
        q = q->next;
    }

    if (q->next == NULL) 
    {
        printf("Invalid location!\n");
        return -1;
    }

    r = q->next;
    int item = r->data;
    q->next = r->next;  
    free(r);
    return item;
}

int deletefromend() 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return -1;
    }

    Node *q = head;

    if (head->next == NULL) 
    {  
        int item = head->data;
        free(head);
        head = NULL;
        return item;
    }

    while (q->next->next != NULL) 
    {  
        q = q->next;
    }

    int item = q->next->data;
    free(q->next);
    q->next = NULL; 
    return item;
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
    int n;
    printf("Enter the number of nodes to be created: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        int val;
        printf("Enter the data in new node: ");
        scanf("%d", &val);
        newNode(val);  
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
            printf("1. At Front\n2. At Mid\n3. At End\nEnter the sub-operation to be performed: ");
            int subop;
            scanf("%d", &subop);
            switch (subop) 
            {
            case 1:
                printf("Enter data for new node: ");
                scanf("%d", &val1);
                insertatfront(val1);
                print();
                break;
            case 2:
                printf("Enter data for new node: ");
                scanf("%d", &val1);
                printf("Enter the location at which element has to be inserted: ");
                scanf("%d", &loc);
                insertatmid(val1, loc);
                print();
                break;
            case 3:
                printf("Enter data for new node: ");
                scanf("%d", &val1);
                newNode(val1);
                print();
                break;
            default:
                printf("INVALID INPUT\n");
                break;
            }
            break;
        case 2:
            printf("1. Delete by data\n2. Delete by location\nEnter the sub-operation to be performed: ");
            int delop;
            scanf("%d", &delop);
            switch (delop) {
            case 1:
                printf("Enter the data to be deleted: ");
                scanf("%d", &val1);
                item = deletebydata(val1);
                if (item != -1) printf("Item deleted from the list: %d\n", item);
                print();
                break;
            case 2:
                printf("1. From Front\n2. From Mid\n3. From End\nEnter the sub-operation to be performed: ");
                int subdel;
                scanf("%d", &subdel);
                switch (subdel) {
                case 1:
                    item = deletefromfront();
                    if (item != -1) printf("Item deleted from the list: %d\n", item);
                    print();
                    break;
                case 2:
                    printf("Enter the location of the node to be deleted: ");
                    scanf("%d", &loc);
                    item = deletefrommid(loc);
                    if (item != -1) printf("Item deleted from the list: %d\n", item);
                    print();
                    break;
                case 3:
                    item = deletefromend();
                    if (item != -1) printf("Item deleted from the list: %d\n", item);
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