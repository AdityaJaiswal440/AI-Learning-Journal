#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("OVERFLOW: Could not allocate memory!\n");
    } else {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        printf("-> Inserted %d.\n", data);
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        printf("-> %d already exists in the tree.\n", data);
    }
    return root;
}

void printInOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

void freeTree(struct node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct node *root = NULL;
    int choice, data;

    while (true) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert Node(s)\n");
        printf("2. Print Tree (In-Order)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("--- Begin Insertion (Enter -1 to stop) ---\n");
                while (true) {
                    printf("Enter data (-1 to stop): ");
                    scanf("%d", &data);
                    
                    if (data == -1) {
                        break;
                    }
                    
                    root = insert(root, data);
                }
                printf("--- Insertion Done ---\n");
                printf("CURRENT TREE: ");
                printInOrder(root);
                printf("\n");
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("TREE (In-Order Traversal): ");
                    printInOrder(root);
                    printf("\n");
                }
                break;
                
            case 3:
                printf("\nFreeing all memory...\n");
                freeTree(root);
                printf("Memory freed.\n");
                printf("Exiting. !\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}