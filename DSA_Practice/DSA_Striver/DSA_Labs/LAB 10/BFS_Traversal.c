#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 50 

int adjMatrix[MAX_V][MAX_V]; 
int status[MAX_V]; 
int V;            

int queue[MAX_V];
int front = -1;
int rear = -1;

void enqueue(int vertex) {
    if (rear == MAX_V - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1; 
    }
    return queue[front++];
}

bool isQueueEmpty() {
    return front == -1 || front > rear;
}

void createGraph(int numVertices) {
    V = numVertices;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    if (u >= 0 && u < V && v >= 0 && v < V) {
        adjMatrix[u][v] = 1; 
        adjMatrix[v][u] = 1; 
    }
}

void BFS(int startNode) {
    for (int i = 0; i < V; i++) {
        status[i] = 1; 
    }

    enqueue(startNode);
    status[startNode] = 2; 

    printf("BFS Traversal: ");

    while (!isQueueEmpty()) {
        
        int current = dequeue();
        status[current] = 3; 
        printf("%d -> ", current); 

        for (int neighbor = 0; neighbor < V; neighbor++) {
            
            if (adjMatrix[current][neighbor] == 1 && status[neighbor] == 1) {
                
                enqueue(neighbor);
                status[neighbor] = 2; 
            }
        }
    }
    printf("END\n");
}

int main() {
    int startNode = 0;
    int numNodes = 4;
    
    createGraph(numNodes);
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);

    printf("Starting BFS from node %d :\n", startNode);
    BFS(startNode);

    return 0;
}