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

struct node* findNode(struct node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    }

    struct node* foundLeft = findNode(root->left, data);
    if (foundLeft != NULL) {
        return foundLeft;
    }
    
    return findNode(root->right, data);
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
    int choice, data, parentData;
    char direction;

    while (true) {
        printf("\n--- General Binary Tree Menu ---\n");
        printf("1. Insert (Create) Node\n");
        printf("--- Traversal ---\n");
        printf("2. Print Pre-Order (Root, Left, Right)\n");
        printf("3. Print In-Order (Left, Root, Right)\n");
        printf("4. Print Post-Order (Left, Right, Root)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for new node: ");
                scanf("%d", &data);
                
                struct node* newNode = createNode(data);
                if (newNode == NULL) {
                    break;
                }

                if (root == NULL) {
                    root = newNode;
                    printf("-> Created root node with data %d.\n", data);
                    break;
                }

                printf("Enter parent node's data: ");
                scanf("%d", &parentData);
                
                struct node* parentNode = findNode(root, parentData);
                if (parentNode == NULL) {
                    printf("-> ERROR: Parent node with data %d not found.\n", parentData);
                    free(newNode);
                    break;
                }

                printf("Insert as (L)eft or (R)ight child?: ");
                scanf(" %c", &direction);

                if (direction == 'L' || direction == 'l') {
                    if (parentNode->left != NULL) {
                        printf("-> ERROR: Left child already exists.\n");
                        free(newNode);
                    } else {
                        parentNode->left = newNode;
                        printf("-> Inserted %d as left child of %d.\n", data, parentData);
                    }
                } else if (direction == 'R' || direction == 'r') {
                    if (parentNode->right != NULL) {
                        printf("-> ERROR: Right child already exists.\n");
                        free(newNode);
                    } else {
                        parentNode->right = newNode;
                        printf("-> Inserted %d as right child of %d.\n", data, parentData);
                    }
                } else {
                    printf("-> Invalid direction.\n");
                    free(newNode);
                }
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