#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int *arr = NULL;
    int size = 0;
    int command, x;

    printf("Commands: 1 (Add), 2 (Delete), 3 (Smallest), 0 (Exit)\n");

    while (scanf("%d", &command) && command != 0) {
        if (command == 1) { 
            scanf("%d", &x);
            arr = realloc(arr, (size + 1) * sizeof(int));
            arr[size++] = x;
            printf("Added %d\n", x);
        } 
        else if (command == 2) { 
            scanf("%d", &x);
            int newSize = 0;
            for (int i = 0; i < size; i++) {
                if (arr[i] != x) {
                    arr[newSize++] = arr[i];
                }
            }
            if (newSize < size) {
                size = newSize;
                arr = realloc(arr, size * sizeof(int));
                printf("Deleted all occurrences of %d\n", x);
            }
        } 
        else if (command == 3) { 
            scanf("%d", &x);
            if (x > 0 && x <= size) {
                qsort(arr, size, sizeof(int), compare);
                printf("%d-th smallest is: %d\n", x, arr[x - 1]);
            } else {
                printf("No such element!\n");
            }
        }
    }

    free(arr);
    return 0;
}