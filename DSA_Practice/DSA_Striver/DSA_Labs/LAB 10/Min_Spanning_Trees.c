#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 10
#define INF 99999 

struct Edge {
    int src, dest, weight;
};

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void sortEdges(struct Edge edges[], int n) {
    struct Edge temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskalMST(int graph[MAX][MAX], int n) {
    struct Edge edges[MAX * MAX];
    int k = 0;
    int minCost = 0;

    // 1. Convert Adjacency Matrix to Edge List
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) {
                edges[k].src = i;
                edges[k].dest = j;
                edges[k].weight = graph[i][j];
                k++;
            }
        }
    }

    // 2. Sort all edges by weight
    sortEdges(edges, k);

    // 3. Initialize disjoint sets (Union-Find)
    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("\n--- Kruskal's MST ---\n");
    printf("Edge \tWeight\n");

    // 4. Iterate through sorted edges and check for cycles
    int count = 0;
    for (int i = 0; i < k; i++) {
        int u = find(edges[i].src);
        int v = find(edges[i].dest);

        // If leaders are different, no cycle is formed
        if (u != v) {
            printf("%d - %d \t%d\n", edges[i].src, edges[i].dest, edges[i].weight);
            minCost += edges[i].weight;
            unionSets(u, v);
            count++;
        }
    }
    printf("Total Minimum Cost: %d\n", minCost);
}

int minKey(int key[], bool mstSet[], int n) {
    int min = INF, min_index;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void primMST(int graph[MAX][MAX], int n) {
    int parentMST[MAX];
    int key[MAX];
    bool mstSet[MAX];
    int minCost = 0;

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parentMST[0] = -1;

    // The MST has V vertices, so loop V-1 times
    for (int count = 0; count < n - 1; count++) {
        // Step 1: Select the vertex 'u' with minimum key value from the outside set (Fringe)
        int u = minKey(key, mstSet, n); 
        mstSet[u] = true;

        // Step 2: Update key values and parent array of adjacent vertices
        for (int v = 0; v < n; v++) {
            // Check: 1. Edge exists, 2. Not in MST, 3. Is cheaper than current key
            if (graph[u][v] != INF && mstSet[v] == false && graph[u][v] < key[v]) {
                parentMST[v] = u;
                key[v] = graph[u][v]; 
            }
        }
    }

    printf("\n--- Prim's MST ---\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parentMST[i], i, graph[i][parentMST[i]]);
        minCost += graph[i][parentMST[i]];
    }
    printf("Total Minimum Cost: %d\n", minCost);
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter Adjacency Matrix (Enter weight, 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Weight %d to %d: ", i, j);
            scanf("%d", &graph[i][j]);
            
            // Convert 0 (no connection) to INF for proper algorithm function
            if (graph[i][j] == 0) {
                graph[i][j] = INF; 
            }
        }
    }

    primMST(graph, n);
    kruskalMST(graph, n);
    return 0;
}