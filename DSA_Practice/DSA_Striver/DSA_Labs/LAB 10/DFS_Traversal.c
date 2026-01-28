#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int adj[MAX][MAX];
int status[MAX];
int n;

int stack[MAX];
int top = -1;

void push(int vertex) {
    if (top == MAX - 1) return;
    stack[++top] = vertex;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

bool isStackEmpty() {
    return top == -1;
}

void DFS(int startNode) {
    for (int i = 0; i < n; i++) {
        status[i] = 1;
    }

    push(startNode);
    status[startNode] = 2;

    printf("DFS Traversal: ");

    while (!isStackEmpty()) {
        
        int current = pop();
        status[current] = 3;
        printf("%d ", current);

        for (int neighbor = 0; neighbor < n; neighbor++) {
            
            if (adj[current][neighbor] == 1 && status[neighbor] == 1) {
                push(neighbor);
                status[neighbor] = 2;
            }
        }
    }
    printf("\n");
}

int main() {
    int startNode;

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter Adjacency Matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &startNode);

    DFS(startNode);

    return 0;
}