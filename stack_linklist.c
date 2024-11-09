#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

stack *top = NULL;

void push(int val)
{
    stack *p = (stack *)malloc(sizeof(stack));
    if (p == NULL)
    {
        printf("Memory Allocation FAILED!");
        exit(1);
    }
    p->data = val;
    p->next = top;
    top = p;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack is empty!");
        exit(1);
    }
    stack *q = (stack *)malloc(sizeof(stack));
    q = top;
    top = top->next;
    int val = q->data;
    free(q);
    return val;
}

void peek()
{
    stack *q = (stack *)malloc(sizeof(stack));
    q = top;
    printf("Items in the stack are: ");
    while (q != NULL)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

int main()
{
    int ch, val;
    do
    {
        printf("1. PUSH\n2. POP\n3. PEEK\n4. EXIT\nEnter the opertation to be performed: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to pe pushed: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            val = pop();
            printf("Item popped from the stack is: %d\n", val);
            break;
        case 3:
            if (top == NULL)
            {
                printf("Stack is empty!");
                exit(1);
            }
            peek();
            break;
        case 4:
            printf("Exiting...");
            exit(1);
            break;
        default:
            printf("INVALID OPERATION!");
            break;
        }
    } while (ch != 4);
    return 0;
}