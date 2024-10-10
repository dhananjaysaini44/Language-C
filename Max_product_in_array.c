#include<stdio.h>
#include<conio.h>
int main()
{
    int a[50],max = 0, i, n;
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
    printf("\n");
    printf("The maximum product of 3 consicutive elements of the array is :-\n");
    for (i=0; i<n-2; i++)
    {
        if (max <= a[i] * a[i+1] * a[i+2])
        {
            max = a[i] * a[i+1] * a[i+2];
        }
    }
    printf("%d\t",max);
    return 0;
    getch();
}