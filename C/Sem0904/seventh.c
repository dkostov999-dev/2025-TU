#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Enter rows (n): ");
    scanf("%d", &n);
    printf("Enter columns (m): ");
    scanf("%d", &m);

    if (n < 3 || m < 3) {
        printf("The matrix must be at least 3x3!\n");
        return 1;
    }

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    long long maxSum; 
    int startRow = 0;
    int startCol = 0;
    int firstTime = 1; 

    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            
            long long currentSum = 0;
            for (int r = i; r < i + 3; r++) {
                for (int c = j; c < j + 3; c++) {
                    currentSum += matrix[r][c];
                }
            }

            if (firstTime || currentSum > maxSum) {
                maxSum = currentSum;
                startRow = i;
                startCol = j;
                firstTime = 0;
            }
        }
    }

    printf("\nPodmatrica 3x3 with maximal sum (%lld) is:\n", maxSum);
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}