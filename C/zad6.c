#include <stdio.h>

int main() {
    int n;
    printf("N: "); scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    int max_len = 1, current_len = 1;
    int max_end_index = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            current_len++;
        } else {
            current_len = 1;
        }

        if (current_len > max_len) {
            max_len = current_len;
            max_end_index = i;
        }
    }

    printf("The longest increasing row: ");
    for (int i = max_end_index - max_len + 1; i <= max_end_index; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nLength: %d\n", max_len);

    return 0;
}