/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15*/
#include <stdio.h>
#include <stdlib.h>

int diagnolSum(int **matrix, int matrixSize, int *matrixColSize)
{
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int sum = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);

    int **matrix = malloc(m * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        matrix[i] = malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = (diagnolSum(matrix, m, &n));
    printf("%d", sum);
    free(matrix);
    return 0;
}