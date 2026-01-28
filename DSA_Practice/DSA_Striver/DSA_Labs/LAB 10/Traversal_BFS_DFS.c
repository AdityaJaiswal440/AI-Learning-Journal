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

int stack[MAX_V];
int top = -1;

void enqueue(int vertex) {
    if (rear == MAX_V - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

bool isQueueEmpty() {
    return front == -1 || front > rear;
}

void push(int vertex) {
    if (top == MAX_V - 1) return;
    stack[++top] = vertex;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

bool isStackEmpty() {
    return top == -1;
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
    front = -1; rear = -1;

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

void DFS(int startNode) {
    for (int i = 0; i < V; i++) {
        status[i] = 1;
    }
    top = -1;

    push(startNode);
    status[startNode] = 2; 

    printf("DFS Traversal: ");

    while (!isStackEmpty()) {
        int N = pop();
        status[N] = 3; 
        printf("%d -> ", N);

        for (int neighbor = V - 1; neighbor >= 0; neighbor--) {
            if (adjMatrix[N][neighbor] == 1 && status[neighbor] == 1) {
                push(neighbor);
                status[neighbor] = 2; 
            }
        }
    }
    printf("END\n");
}

int main() {
    int startNode, numNodes, choice, u, v;

    printf("--- Graph Traversal Implementation ---\n");
    printf("Enter number of vertices (max %d): ", MAX_V);
    scanf("%d", &numNodes);

    if (numNodes <= 0 || numNodes > MAX_V) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    createGraph(numNodes);

    printf("\n--- Edge Input ---\n");
    printf("Enter edges (u v). Enter -1 -1 to stop.\n");
    while (true) {
        printf("Edge: ");
        if (scanf("%d %d", &u, &v) != 2 || (u == -1 && v == -1)) {
            break;
        }
        if (u >= 0 && u < numNodes && v >= 0 && v < numNodes) {
            addEdge(u, v);
        } else {
            printf("Invalid vertex index entered.\n");
        }
    }

    printf("\nEnter starting vertex (0 to %d): ", numNodes - 1);
    scanf("%d", &startNode);

    if (startNode < 0 || startNode >= numNodes) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    printf("\n--- Traversal Results ---\n");
    
    BFS(startNode);
    
    DFS(startNode);

    return 0;
}