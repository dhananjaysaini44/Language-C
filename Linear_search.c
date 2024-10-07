#include <conio.h>
#include <stdio.h>
int main()
{
    int item, a[10], n, i, flag;
    printf("enter the size of array\n");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The array is:-\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nEnter the item to search for : ");
    scanf("%d", &item);
    flag = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            flag = 1;
            break;
        }
    }
    if (flag = 1)
    {
        printf("\n%d found at %d location", item ,i+1);
    }
    else
    {
        printf("\nItem not found");
    }
    return 0;
    getch();
}