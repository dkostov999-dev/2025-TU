#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    printf("Enter the number of elements n: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *primes = NULL; 
    int primeCount = 0;
    int remainingCount = 0;

    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            primeCount++;
            primes = (int *)realloc(primes, primeCount * sizeof(int));
            primes[primeCount - 1] = arr[i];
        } else {
            arr[remainingCount] = arr[i];
            remainingCount++;
        }
    }

    if (remainingCount > 0) {
        arr = (int *)realloc(arr, remainingCount * sizeof(int));
    } else {
        free(arr);
        arr = NULL;
    }

    printf("\nOriginal array (without simple numbers): ");
    for (int i = 0; i < remainingCount; i++) printf("%d ", arr[i]);

    printf("\nArray with simple numbers: ");
    for (int i = 0; i < primeCount; i++) printf("%d ", primes[i]);
    printf("\n");

    free(arr);
    free(primes);

    return 0;
}