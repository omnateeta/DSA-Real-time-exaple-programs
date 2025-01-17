#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100  // Maximum number of nodes

// Global variables
int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix representation
bool visited[MAX_NODES];         // Array to track visited nodes
int n;                           // Number of nodes in the graph

// DFS function
void DFS(int node) {
	int i;
    printf("%d ", node);      // Print the current node
    visited[node] = true;     // Mark the current node as visited

    // Traverse all adjacent nodes
    for (i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) { // Check for an edge and unvisited node
            DFS(i);        // Recursively call DFS for the adjacent node
        }
    }
}

// Main function
int main() {
	int i,j;
    int edges, u, v, start;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the adjacency matrix and visited array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }

    // Read edges of the graph
    printf("Enter the edges (u v):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;  // Mark edge u -> v
        graph[v][u] = 1;  // Mark edge v -> u (for undirected graph)
    }

    // Input starting node
    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("DFS Traversal starting from node %d:\n", start);
    DFS(start);

    return 0;
}

