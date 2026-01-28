#include <stdio.h>
#include <stdlib.h>

// 1. The Linked List Node (Stores the Neighbor)
struct Node {
    int dest;
    struct Node* next;
};

// 2. The Graph Structure
struct Graph {
    int V; 
    struct Node** array; 
};

// Helper: Create a new Linked List Node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // FIX 1: Check if malloc failed before accessing newNode
    if (newNode == NULL) {
        printf("Error: Memory allocation failed for a new node.\n");
        return NULL;
    }
    
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Helper: Create the Graph (Initialize the Array)
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Error: Memory allocation failed for graph structure.\n");
        return NULL;
    }
    
    graph->V = V;

    // Allocate memory for the "Extra Array" of size V
    graph->array = (struct Node**)malloc(V * sizeof(struct Node*));
    if (graph->array == NULL) {
        printf("Error: Memory allocation failed for adjacency array.\n");
        free(graph); // Clean up the structure memory
        return NULL;
    }

    // Initialize every slot in the array to NULL
    for (int i = 0; i < V; ++i)
        graph->array[i] = NULL;

    return graph;
}

// Function to add an edge (Uses the Array for Speed!)
void addEdge(struct Graph* graph, int src, int dest) {
    // Check for valid indices
    if (src >= graph->V || dest >= graph->V || src < 0 || dest < 0) {
        printf("Error: Invalid vertex index in addEdge.\n");
        return;
    }

    // 1. Create the new node for the destination
    struct Node* newNodeDest = createNode(dest);
    if (newNodeDest == NULL) return; 

    // 2. Add the new node to the front of the source's list
    newNodeDest->next = graph->array[src];
    graph->array[src] = newNodeDest;

    // 3. Since graph is undirected, add src to dest's list too
    struct Node* newNodeSrc = createNode(src);
    if (newNodeSrc == NULL) return; 
    
    // Add the new node to the front of the destination's list
    newNodeSrc->next = graph->array[dest];
    graph->array[dest] = newNodeSrc;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (graph->array[v]->next!=NULL) {
            printf("-> %d", graph->array[v]->dest);
            graph->array[v] = graph->array[v]->next;
        }
        printf("\n");
    }
}

// FIX 2: Function to free the entire graph structure
void freeGraph(struct Graph* graph) {
    if (graph == NULL) return;

    for (int v = 0; v < graph->V; ++v) {
        struct Node* pCrawl = graph->array[v];
        struct Node* temp;
        // Free the linked list (all the nodes) for this vertex
        while (pCrawl) {
            temp = pCrawl;
            pCrawl = pCrawl->next;
            free(temp);
        }
    }
    
    // Free the array of pointers
    free(graph->array);
    
    // Free the graph structure itself
    free(graph);
    printf("\nMemory cleanup complete.\n");
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    
    if (graph == NULL) return 1; // Check if creation failed

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    // Call the cleanup function before exiting
    freeGraph(graph); 

    return 0;
}