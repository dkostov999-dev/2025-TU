#include <stdio.h>

int main() {
    int n, k_sum;
    printf("N: "); scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("Required sum: "); scanf("%d", &k_sum);

    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum == k_sum) {
                printf("Found range: ");
                for (int m = i; m <= j; m++) printf("%d ", arr[m]);
                return 0; 
            }
        }
    }
    printf("No such sum existing.\n");
    return 0;
}