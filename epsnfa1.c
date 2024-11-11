#include <stdio.h>

struct adjList {
    int startNode, endNode;
    char symbol;
} adj[100];

int n, t, s, e, m;
char e_closer[100][100] = {{'\0'}};

void dfs(int index, int node, int end, int start) {
    e_closer[node][end++] = (char)(start + '0');

    for(int i = index + 1; i < m; i++)
        if(adj[i].startNode == adj[index].endNode && adj[i].symbol == 'e')
            dfs(i, node, end, adj[i].endNode);
    
}

int main()
{
    printf("Enter number of states: ");
    scanf("%d", &n);
    
    printf("Enter number of terminals: ");
    scanf("%d", &t);
    
    printf("Enter the start states: ");
    scanf("%d", &s);
    
    printf("Enter the end states: ");
    scanf("%d", &e);
    
    printf("Enter number of transitions: ");
    scanf("%d", &m);
    
    for(int i = 1; i <= n; i++)
        e_closer[i][0] = (char) i + '0';

    for(int i = 0; i < m; i++) {
        int start, endn;
        char symbol;
        
        scanf("%d %c %d", &start, &symbol, &endn);
        
        adj[i].startNode = start;
        adj[i].endNode = endn;
        adj[i].symbol = symbol;
    }

    for(int i = 1; i < m; i++) 
        if(adj[i].symbol == 'e')
            dfs(i, adj[i].startNode, 1, adj[i].endNode);

    printf("\nEpsilon-closures:\n");
    for(int i = 1; i <= n; i++) {
        printf("State %d: ", i);
        
        for(int j = 0; e_closer[i][j] != '\0'; j++)
            printf("%c ", e_closer[i][j]);
        
        printf("\n");
    }
    
    printf("\nEpsilon-NFA to NFA:\n");
    for(int i = 0; i < m; i++) {
        int start = adj[i].startNode, end = adj[i].endNode;
        
        for(int j = 0; e_closer[start][j] != '\0'; j++)
            printf("%c", e_closer[start][j]);
        
        printf(" %c ", adj[i].symbol);
        
        for(int j = 0; e_closer[end][j] != '\0'; j++)
            printf("%c", e_closer[end][j]);
        
        printf("\n");
    }
    

    return 0;
}