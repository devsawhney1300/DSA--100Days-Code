/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int range = max - min + 1;
    int *freq = calloc(range, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        freq[arr[i] - min]++;
    }

    for (int i = 0; i < range; i++)
    {
        if (freq[i] > 0)
        {
            printf("%d:%d ", i + min, freq[i]);
        }
    }

    free(arr);
    free(freq);
    return 0;
}