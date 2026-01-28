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
        printf("OVERFLOW: Can't allocate memory!\n");
    } else {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

struct node* createTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct node* root = createNode(data);
    if (root == NULL) {
        return NULL;
    }

    printf("Enter left child for %d:\n", data);
    root->left = createTree();

    printf("Enter right child for %d:\n", data);
    root->right = createTree();

    return root;
}

void printPreOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

void printPostOrder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
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
    int choice;

    while (true) {
        printf("\n--- Binary Tree Traversal ---\n");
        printf("1. Create New Tree\n");
        printf("2. Print Pre-Order (Root, Left, Right)\n");
        printf("3. Print In-Order (Left, Root, Right)\n");
        printf("4. Print Post-Order (Left, Right, Root)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (root != NULL) {
                    printf("Freeing existing tree\n");
                    freeTree(root);
                    root = NULL;
                }
                printf("--- Begin Tree Creation ---\n");
                root = createTree();
                printf(" New tree created.\n");
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Pre-Order Traversal: ");
                    printPreOrder(root);
                    printf("\n");
                }
                break;
                
            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("In-Order Traversal: ");
                    printInOrder(root);
                    printf("\n");
                }
                break;
                
            case 4:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Post-Order Traversal: ");
                    printPostOrder(root);
                    printf("\n");
                }
                break;
                
            case 5:
                printf("\nFreeing all memory...\n");
                freeTree(root);
                printf("Memory freed.\n");
                printf("Exiting. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}