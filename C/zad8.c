#include <stdio.h>

int main() {
    int arr[20];
    int current_size = 10;

    printf("Enter the first 10 numbers:\n");
    for (int i = 0; i < current_size; i++) {
        scanf("%d", &arr[i]);
    }

    int value, index;
    while (current_size < 20) {
        printf("Enter a number (or 0 for end): ");
        scanf("%d", &value);
        if (value == 0) break;

        printf("Enter an index in order to insert an element: ");
        scanf("%d", &index);

        if (index < 0 || index > current_size) {
            printf("Invalid index!\n");
            continue;
        }

        for (int i = current_size; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = value;
        current_size++;

        printf("The current list: ");
        for (int i = 0; i < current_size; i++) printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;
}