#include <stdio.h>

int main() {
    int n, k;
    printf("N: "); scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("K: "); scanf("%d", &k);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    if (k > 0 && k <= n) {
        printf("The %d biggest number is: %d\n", k, arr[k - 1]);
    } else {
        printf("Invalid K.\n");
    }
    return 0;
}