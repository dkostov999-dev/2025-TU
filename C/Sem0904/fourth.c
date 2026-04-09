#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    int *friendsCount = (int*)calloc(N + 1, sizeof(int));

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        friendsCount[u]++;
        friendsCount[v]++;
    }

    int queryPerson;
    printf("Enter the number of the person to see their friends: ");
    while (scanf("%d", &queryPerson) != EOF) {
        if (queryPerson >= 1 && queryPerson <= N) {
            printf("The person %d has %d friends.\n", queryPerson, friendsCount[queryPerson]);
        } else {
            printf("Invalid number.\n");
        }
        printf("Enter the next number: ");
    }

    free(friendsCount);
    return 0;
}