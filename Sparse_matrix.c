#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter the size of matrix: ");
    scanf("%d%d", &n, &m);
    int i, j, a[n][m];
    //sparse matrix is matrix in which more than 50% values are 0
    printf("Enter data in matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The Matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    int s[n*m][3];
    s[0][0] = n;
    s[0][1] = m;
    int k = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }
    s[0][2] = k - 1;

    printf("The sparse matrix is:\n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    
    int b[s[0][0]][s[0][1]];
    for (i = 0; i < s[0][0]; i++)
    {
        for (j = 0; j < s[0][1]; j++)
        {
            b[i][j] = 0;
        }
    }

    j = 0;
    for (i = 1; i <= k - 1; i++)
    {
        b[s[i][j]][s[i][j + 1]] = s[i][j + 2];
    }

    printf("The matrix from the sparse matrix is:\n");
    for (i = 0; i < s[0][0]; i++)
    {
        for (j = 0; j < s[0][1]; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}