#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_ALPHABET 26

int epsilonClosure[MAX_STATES][MAX_STATES];
int nfa[MAX_STATES][MAX_ALPHABET][MAX_STATES];
int newNFA[MAX_STATES][MAX_ALPHABET][MAX_STATES];
int numStates, numAlphabet;
char alphabet[MAX_ALPHABET];

// Array to store the epsilon closure of each state
int closure[MAX_STATES][MAX_STATES];
int closureSize[MAX_STATES];

// Function to find the epsilon closure of a given state
void findEpsilonClosure(int state, int visited[]) {
    visited[state] = 1;
    closure[state][closureSize[state]++] = state;

    for (int next = 0; next < numStates; next++) {
        if (epsilonClosure[state][next] && !visited[next]) {
            findEpsilonClosure(next, visited);
        }
    }
}

// Function to build epsilon closures for all states
void computeEpsilonClosures() {
    for (int i = 0; i < numStates; i++) {
        int visited[MAX_STATES] = {0};
        closureSize[i] = 0;
        findEpsilonClosure(i, visited);
    }
}

// Function to convert NFA with epsilon transitions to NFA without epsilon transitions
void convertNFA() {
    for (int state = 0; state < numStates; state++) {
        for (int a = 0; a < numAlphabet; a++) {
            int symbol = alphabet[a] - 'a';

            // Use epsilon closure to determine the new transitions
            for (int i = 0; i < closureSize[state]; i++) {
                int epsilonState = closure[state][i];

                // Check transitions from the epsilon closure state
                for (int nextState = 0; nextState < numStates; nextState++) {
                    if (nfa[epsilonState][symbol][nextState]) {
                        for (int j = 0; j < closureSize[nextState]; j++) {
                            int targetState = closure[nextState][j];
                            newNFA[state][symbol][targetState] = 1;
                        }
                    }
                }
            }
        }
    }
}

// Function to print the NFA
void printNFA(int nfa[MAX_STATES][MAX_ALPHABET][MAX_STATES]) {
    printf("State\tInput\tNext States\n");
    for (int state = 0; state < numStates; state++) {
        for (int a = 0; a < numAlphabet; a++) {
            int symbol = alphabet[a] - 'a';
            printf("%d\t%c\t", state, alphabet[a]);
            for (int nextState = 0; nextState < numStates; nextState++) {
                if (nfa[state][symbol][nextState]) {
                    printf("%d ", nextState);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int numTransitions;
    printf("Enter the number of states: ");
    scanf("%d", &numStates);
    printf("Enter the alphabet size: ");
    scanf("%d", &numAlphabet);
    printf("Enter the alphabet (e.g., a b c): ");
    for (int i = 0; i < numAlphabet; i++) {
        scanf(" %c", &alphabet[i]);
    }

    // Initialize the NFA and epsilon closure
    memset(nfa, 0, sizeof(nfa));
    memset(epsilonClosure, 0, sizeof(epsilonClosure));

    printf("Enter the number of transitions: ");
    scanf("%d", &numTransitions);
    printf("Enter transitions in the form (from_state input to_state), use 'e' for epsilon:\n");
    for (int i = 0; i < numTransitions; i++) {
        int from, to;
        char input;
        scanf("%d %c %d", &from, &input, &to);
        if (input == 'e') {
            epsilonClosure[from][to] = 1;
        } else {
            int symbol = input - 'a';
            nfa[from][symbol][to] = 1;
        }
    }

    // Compute epsilon closures
    computeEpsilonClosures();

    // Convert NFA with epsilon transitions to NFA without epsilon transitions
    convertNFA();

    // Print the equivalent NFA without epsilon transitions
    printf("\nEquivalent NFA without epsilon transitions:\n");
    printNFA(newNFA);

    return 0;
}
