#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 10;
    int *arr = (int *)malloc(size * sizeof(int));
    
    printf("Enter 10 numbers: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int value, pos;
    printf("Enter 'number' and 'position' (0 for end):\n");
    
    while (1) {
        scanf("%d", &value);
        if (value == 0) break; 
        scanf("%d", &pos);

        if (pos < 0 || pos > size) {
            printf("Invalid position!\n");
            continue;
        }

        size++;
        arr = (int *)realloc(arr, size * sizeof(int));

        for (int i = size - 1; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = value;
    }

    printf("Exit: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}