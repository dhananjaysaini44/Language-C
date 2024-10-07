#include <conio.h>
#include <stdio.h>
int main()
{
    int n, a[50], i, flag, j;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j <= n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                flag = a[j];
                a[j] = a[j+1];
                a[j+1] = flag;
            }
        }
    }
    
    printf("The sorted array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
    getch();
}