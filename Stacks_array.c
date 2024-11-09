#include <stdlib.h>
#include <stdio.h>

#define MAX 4
int stack[MAX];
int top = -1;

void PUSH(int item)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    else
    {
        top++;
        stack[top] = item;
        printf("%d is entered in the stack\n", item);
    }
}

int POP()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    else
    {
        int popped = stack[top];
        top--;
        printf("%d popped from the stack\n", popped);
        return popped;
    }
}

void Peek()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d  ", stack[i]);
    }
}

int main()
{
    int a;
    do
    {
        int item;
        printf("1. Push\n2. POP\n3. Peek\n4. Exit\nEnter the operation to br performed: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the item to Push : ");
            scanf("%d", &item);
            PUSH(item);
            break;
        case 2:
            POP();
            break;
        case 3 : 
            Peek();
            break;
        case 4 :
            printf("Exiting...");
            exit(1);
            break;
        default:
            printf("Invalid Operation\n");
            break;
        }
    } while (a != 4);
    return 0;
}