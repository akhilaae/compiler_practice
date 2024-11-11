#include <stdio.h>
#include <string.h>

#define MAX_STATES 10  // Define the maximum number of states

int n;

void closure(int state, int matrix[][MAX_STATES], int visited[]) {
    // Mark the current state as visited
    visited[state] = 1;
    for (int i = 0; i < n; i++) {
        if (matrix[state][i] == 1 && !visited[i]) {
            printf(", q%d", i);
            closure(i, matrix, visited);
        }
    }
}

int main() {
    char state1[3], input[3], state2[3];
    int s1, s2, numTransitions;

    printf("Enter the number of states (<= %d): ", MAX_STATES);
    scanf("%d", &n);

    // Validate the number of states
    if (n > MAX_STATES) {
        printf("Number of states exceeds the maximum limit of %d.\n", MAX_STATES);
        return 1;
    }

    int mat[MAX_STATES][MAX_STATES];

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }

    printf("Enter the number of transitions: ");
    scanf("%d", &numTransitions);

    // Input transitions from user
    printf("Enter transitions in the format: qX <symbol> qY\n");
    for (int i = 0; i < numTransitions; i++) {
        printf("Transition %d: ", i + 1);
        scanf("%s %s %s", state1, input, state2);

        // Only consider epsilon (e) transitions for the epsilon closure
        if (strcmp(input, "e") == 0) {
            s1 = state1[0] - '0'; // Convert state1 (like "0") to integer
            s2 = state2[0] - '0'; // Convert state2 (like "1") to integer
            mat[s1][s2] = 1;      // Mark the epsilon transition in the matrix
        }
    }

    // Calculate and display the epsilon closures
    printf("\nEpsilon closure of each state:\n");
    for (int k = 0; k < n; k++) {
        int visited[MAX_STATES] = {0};  // Reset visited array for each state
        printf("q%d : q%d", k, k);
        closure(k, mat, visited);
        printf("\n");
    }

    return 0;
}