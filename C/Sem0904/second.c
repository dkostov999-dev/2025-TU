#include <stdio.h>
#include <stdlib.h>
int getValue(int r, int c, int N, int M, int** matrix) {
    if (r >= 0 && r < N && c >= 0 && c < M) {
        return matrix[r][c];
    }
    return 0; 
}

int main() {
    int N, M;
    printf("Enter N:  ");
    scanf("%d", &N);
    printf("Enter M: ");
    scanf("%d", &M);


    int** matrix = (int**)malloc(N * sizeof(int*));

if(matrix == NULL) {
    exit (1);
}

for(int i = 0; i < N; i++) {
    matrix[i] = (int*)malloc(M * sizeof(int));
    if(matrix[i] == NULL) {
        for(int T = 0; T < N; T++) {
            free(matrix[i]);
        }
        free(matrix);

        exit (1);
    }

}
printf("Enter the elements of the matrix (%dx%d):\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]); 
        }
    }
    
    int bestX = 0, bestY = 0;
    long long maxSum = -2000000000;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            long long currentSum = 0;
            currentSum += getValue(i-1, j-1, N, M, matrix); 
            currentSum += getValue(i-1, j,   N, M, matrix); 
            currentSum += getValue(i-1, j+1, N, M, matrix); 
            currentSum += getValue(i,   j-1, N, M, matrix); 
            currentSum += getValue(i,   j+1, N, M, matrix); 
            currentSum += getValue(i+1, j-1, N, M, matrix); 
            currentSum += getValue(i+1, j,   N, M, matrix); 
            currentSum += getValue(i+1, j+1, N, M, matrix); 

            if (currentSum > maxSum) {
                maxSum = currentSum;
                bestX = i;
                bestY = j;
            }
        }
    }

    printf("The number with the sum of the neighbours: %d  %lld\n", matrix[bestX][bestY], maxSum);
    for(int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}