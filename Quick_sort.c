//quick sort is best in case of sorting large data 
#include <conio.h>
#include <stdio.h>
int main()
{
    int n, a[50], i, p, r;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    p = 0;
    r = n - 1;
    quicksort(a, p, r);
    
    printf("The sorted array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
    getch();
}

int partition(int *a, int p, int r)
{
    int x = a[r];
    int i = p - 1;
    int temp;
    for (int j = p; j <= r-1; j++)
    {
        if (a[j] <= x)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;
    return (i+1);
}

void quicksort(int *a, int p,int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}