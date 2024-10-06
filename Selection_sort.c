// merge sort is best as all worst best and avg tme complexity is same i.e. nlogn
#include <conio.h>
#include <stdio.h>
int main()
{
    int n, a[50], i, temp, t, j;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int min;
    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                temp = j;
            }
        }
        if (min != a[i])
        {
            t = a[i];
            a[i] = a[temp];
            a[temp] = t;
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