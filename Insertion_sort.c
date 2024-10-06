//insertion sort is the best sort if the no. of elements is minimum
#include <conio.h>
#include <stdio.h>
int main()
{
    int n, a[50], i, temp, j;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j+1] = a[j];
            j--;
        }
        j++;
        a[j] = temp;
    }
    
    printf("The sorted array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
    getch();
}