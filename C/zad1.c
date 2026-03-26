#include <stdio.h>

int main() {
    int n;

    
    printf("Enter a value for length N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid length.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d sorted numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    int max_len = 1;      
    int max_start = 0;    

    int current_len = 1;  
    int current_start = 0; 

    
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            
            current_len++;
        } else {
            
            current_len = 1;
            current_start = i;
        }

    
        if (current_len > max_len) {
            max_len = current_len;
            max_start = current_start;
        }
    }

    
    printf("\nThe longest playground:\n");
    printf("First index: %d\n", max_start);
    printf("Length: %d\n", max_len);
    printf("The number in it is: %d\n", arr[max_start]);

    return 0;
}