//Intersection of two sorted arrays
#include <stdio.h>
#include <conio.h>
int main()
{
    int a[50], b[50], c[50], i, n1, n2, j, k;
    printf("enter the size of 1 array\n");
    scanf("%d", &n1);
    printf("enter the elements\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The array is:-\n");
    for (i = 0; i < n1; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    printf("Enter the size of 2 array\n");
    scanf("%d", &n2);
    printf("Enter elements of 2 array\n");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("2 array is\n");
    for (i = 0; i < n2; i++)
    {
        printf("%d\t", b[i]);
    }
    printf("\n");
    printf("Intersection of the arrays is :-\n");

    i = 0;
    j = 0;
    k = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] == b[j])
        {
            c[k] = a[i];
            i++;
            j++;
            k++;
        }
        //else if (a[i] > b[j])
        //{
            //c[k] = b[j];
            //k++;
            //j++;
        //}
        else
        {
            //c[k] = a[i];
            //k++;
            i++;
            j++;
        }
    }
    for (i = 0; i < k; i++)
    {
        printf("%d\t", c[i]);
    }
    return 0;
    getch();
}