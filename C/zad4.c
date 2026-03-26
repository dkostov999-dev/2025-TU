#include <stdio.h>

int main() {
    int n, k;

    printf("Enter length: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Value for K: ");
    scanf("%d", &k);


    for (int step = 0; step < k; step++) {
        
        int last = arr[n - 1];

        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = last;
    }

    printf("Result: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}