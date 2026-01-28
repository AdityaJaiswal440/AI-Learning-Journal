#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_V 10

int adjMatrix[MAX_V][MAX_V];
int V;

void createGraph(int numVertices){
    V=numVertices;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            adjMatrix[i][j]=0;
        }
    }
    printf("Graph initialized with %d vertices\n",V);
}

void addEdge(int u, int v) {
    if (u >= 0 && u < V && v >= 0 && v < V) {
        adjMatrix[u][v] = 1; 
        adjMatrix[v][u] = 1; 
        printf("Edge added: %d -- %d\n", u, v);
    } else {
        printf("Error: Invalid vertex index to be added.\n");
    }
}

void printGraph() {
    printf("\nAdjacency Matrix (%dx%d):\n", V, V);
    printf("  ");
    for(int k=0; k<V; k++) {
        printf(" %d", k);
    }
    printf("\n");
    
    for (int i = 0; i < V; i++) {
        printf("%d |", i);
        for (int j = 0; j < V; j++) {
            printf(" %d", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numNodes = 5;
    createGraph(numNodes); 

    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);

    printGraph();
    

    printf("\nEdge from 1 to 4 exists: %s\n", (adjMatrix[1][4] == 1 ? "Yes" : "No"));

    return 0;
}