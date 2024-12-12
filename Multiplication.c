#include <stdio.h>

int main() {
    int m, n, p;
    printf("Enter dimensions for first matrix (m n): ");
    scanf("%d %d", &m, &n);

    int a[m][n];
    printf("Enter first matrix:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter dimension for second matrix (p): ");
    scanf("%d", &p);

    int b[n][p], result[m][p];
    printf("Enter second matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &b[i][j]);

    // Multiply matrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }

    // Print result
    printf("Resultant matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    return 0;
}
