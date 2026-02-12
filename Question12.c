#include <stdio.h>

int main() {
    int m, n;

    // Input number of rows and columns
    scanf("%d %d", &m, &n);

    // If not square matrix, directly not symmetric
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    int matrix[m][n];

    // Input matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check symmetric condition
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix\n");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix\n");

    return 0;
}