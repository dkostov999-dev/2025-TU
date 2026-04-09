#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    printf("Rows N: ");
    scanf("%d", &N);
    printf("Columns M: ");
    scanf("%d", &M);

    int **matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int *)malloc(M * sizeof(int));
    }

    printf("Enter elements:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maxVal = matrix[0][0];
    int minVal = matrix[0][0];
    int maxRow = 0;
    int minRow = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
            }
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minRow = i;
            }
        }
    }

    if (maxRow != minRow) {
        int *temp = matrix[maxRow];
        matrix[maxRow] = matrix[minRow];
        matrix[minRow] = temp;
        printf("\nThe rows are exchanged successfully.\n");
    } else {
        printf("\nThe biggest and the smallest elements are on the same row.\n");
    }

    printf("\nThe result of the matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}