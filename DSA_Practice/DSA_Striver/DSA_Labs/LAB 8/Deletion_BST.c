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
        printf(" Inserted %d.\n", data);
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        printf(" %d already exists in the tree.\n", data);
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

struct node* findLargestNode(struct node* root) {
    struct node* ptr = root;
    while (ptr != NULL && ptr->right != NULL) {
        ptr = ptr->right;
    }
    return ptr;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) {
        printf(" %d not found in the tree.\n", data);
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } 
    // when data==root->data
    else {
        struct node *temp;

        if (root->left == NULL && root->right == NULL) {
            printf(" Deleting node %d (Case 1: No children).\n", data);
            temp = root;
            root = NULL;
            free(temp);
        }

        else if (root->left == NULL) {
            printf(" Deleting node %d (Case 2: One right child).\n", data);
            temp = root;
            root = root->right;
            free(temp);
        } 
        
        else if (root->right == NULL) {
            printf(" Deleting node %d (Case 2: One left child).\n", data);
            temp = root;
            root = root->left;
            free(temp);
        }
        
        else {
            printf(" Deleting node %d (Case 3: Two children).\n", data);
            temp = findLargestNode(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
    }
    return root;
}

int main() {
    struct node *root = NULL;
    int choice, data;

    while (true) {
        printf("\n--- Binary Search Tree ---\n");
        printf("1. Insert Node(s) (Creation)\n");
        printf("2. Delete Node (All Cases)\n");
        printf("3. Print Tree (In-Order)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("--- Begin Insertion ---\n");
                while (true) {
                    printf("Enter data (Enter -1 to stop): ");
                    scanf("%d", &data);
                    
                    if (data == -1) {
                        break;
                    }
                    
                    root = insert(root, data);
                }
                printf("\n--- Insertion Complete ---\n");
                printf("CURRENT TREE: ");
                printInOrder(root);
                printf("\n");
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty. Cannot delete.\n");
                } else {
                    printf("Enter data to delete: ");
                    scanf("%d", &data);
                    root = deleteNode(root, data);
                    printf("CURRENT TREE: ");
                    printInOrder(root);
                    printf("\n");
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("TREE (In-Order Traversal): ");
                    printInOrder(root);
                    printf("\n");
                }
                break;
                
            case 4:
                printf("\nFreeing all memory...\n");
                freeTree(root);
                printf("Memory freed.\n");
                printf("Exiting....!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}