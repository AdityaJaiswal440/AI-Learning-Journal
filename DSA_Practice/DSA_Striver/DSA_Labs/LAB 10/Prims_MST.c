#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 20
#define INF 99999

int minKey(int key[], bool mstSet[], int V) {
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }

    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int V) {
    int totalWeight = 0; 
    printf("\n--- Minimum Spanning Tree(Prim's) ---\n");
    printf("Edge \t\tWeight\n");
    
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t\t%d \n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total Minimum Cost: %d\n", totalWeight); 
}

void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V; count++) { 
        int u = minKey(key, mstSet, V);

        if (u == -1) break; 
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V;
    int graph[MAX][MAX];

    printf("Prim's algorithm-------\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("\n--- Enter Weights ---\n");
    printf("Enter 0 (no edge between two vertices)\n");

    for (int i = 0; i < V; i++) {
        for (int j = i; j < V; j++) { 
            
            if (i == j) {
                graph[i][j] = 0; 
                continue;
            }

            printf("Weight %d to %d: ", i, j);
            scanf("%d", &graph[i][j]);


            graph[j][i] = graph[i][j]; 
            
            
            if (graph[i][j] == 0) {
                graph[i][j] = INF;
                graph[j][i] = INF;
            }
        }
    }

    primMST(graph, V);
    return 0;
}