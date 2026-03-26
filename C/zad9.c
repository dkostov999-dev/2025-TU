#include <stdio.h>

int main() {
    int n;
    printf("Enter length: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter an element");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int max_len = 1, current_len = 1;
    int best_value = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            current_len++;
        } else {
            current_len = 1;
        }

        if (current_len > max_len) {
            max_len = current_len;
            best_value = arr[i];
        }
    }

    printf("End: ");
    for (int i = 0; i < max_len; i++) {
        printf("%d ", best_value);
    }
    printf("\n");

    return 0;
}