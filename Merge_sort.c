// merge sort is best as all worst best and avg tme complexity is same i.e. nlogn
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
    mergesort(a, p, r);

    printf("The sorted array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
    getch();
}

void merge(int *a, int p, int q, int r)
{
    int i, j;
    int n1 = q - p + 1;
    int n2 = r - q;
    int b[50], c[50];
    for (i = 0; i < n1; i++)
    {
        b[i] = a[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        c[j] = a[q + 1 + j];
    }
    i = 0;
    j = 0;
    int k = p;
    while (i < n1 && j < n2)
    {
        if (b[i] <= c[j])
        {
            a[k] = b[i];
            k++;
            i++;
        }
        else
        {
            a[k] = c[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        a[k] = b[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        a[k] = c[j];
        k++;
        j++;
    }
}

void mergesort(int *a, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(a, p, q);
        mergesort(a, q + 1, r);
        merge(a, p, q, r);
    }
}