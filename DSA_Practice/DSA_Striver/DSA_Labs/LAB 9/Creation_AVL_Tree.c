#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 1. THE STRUCTURE
// Unlike a normal BST, we store 'height' to allow O(1) access
// during balancing checks.
struct node {
    int data;
    struct node *left;
    struct node *right;
    int height; 
};

// 2. HELPER FUNCTIONS

// Returns height of a node safely.
// Handles the case where 'n' is NULL (height is 0).
int getHeight(struct node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

// Simple utility to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Calculates Balance Factor = Height(Left) - Height(Right)
// Range allowed: {-1, 0, 1}
// If > 1: Left Heavy
// If < -1: Right Heavy
int getBalance(struct node *n) {
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Creates a new node with height initialized to 1 (Leaf Node)
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("OVERFLOW: Could not allocate memory!\n");
    } else {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1; // New nodes are always leaves initially
    }
    return newNode;
}

// 3. ROTATION LOGIC

// RIGHT ROTATE (Fixes Left-Heavy Imbalance / LL Case)
// 'critical' is the unbalanced node (e.g., 30)
// 'newRoot' will be its left child (e.g., 20)
struct node *rightRotate(struct node *critical) {
    struct node *newRoot = critical->left;
    struct node *bag = newRoot->right; // The "Bag" is the right child of newRoot (e.g., 25)

    // PERFOM ROTATION
    newRoot->right = critical; // 20 takes 30 as its right child
    critical->left = bag;      // 30 adopts 25 (the orphan) as its left child

    // UPDATE HEIGHTS
    // Must update 'critical' (old root) first, then 'newRoot' (new root)
    critical->height = max(getHeight(critical->left), getHeight(critical->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    // Return the new root to link it back to the upper tree
    return newRoot;
}

// LEFT ROTATE (Fixes Right-Heavy Imbalance / RR Case)
// Mirror image of Right Rotate
struct node *leftRotate(struct node *critical) {
    struct node *newRoot = critical->right;
    struct node *bag = newRoot->left; // The "Bag" is the left child of newRoot

    // PERFORM ROTATION
    newRoot->left = critical; // newRoot takes critical as left child
    critical->right = bag;    // critical adopts the bag

    // UPDATE HEIGHTS
    critical->height = max(getHeight(critical->left), getHeight(critical->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}


// 4. THE INSERT FUNCTION (The Brain)
struct node* insert(struct node* root, int data) {

    // STEP 1: STANDARD BST INSERTION
    // This part recursively goes down to find the NULL spot
    if (root == NULL) {
        printf("-> Inserted %d.\n", data);
        return createNode(data);
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else {
        printf("-> %d already exists in the tree.\n", data);
        return root; // No duplicates allowed
    }

    // ---------------------------------------------------------
    // STEP 2: UPDATE HEIGHT (During Recursion Unwinding)
    // As we return up the stack, we update the height of ancestors
    // ---------------------------------------------------------
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // ---------------------------------------------------------
    // STEP 3: CHECK BALANCE FACTOR
    // ---------------------------------------------------------
    int balanceFactor = getBalance(root);

    // ---------------------------------------------------------
    // STEP 4: CHECK FOR 4 IMBALANCE CASES
    // ---------------------------------------------------------

    // Case 1: LL Case (Left Heavy, Inserted in Left)
    // BF > 1 means Left Heavy. data < left->data means inserted to the Left.
    if (balanceFactor > 1 && data < (root->left->data))
        return rightRotate(root);

    // Case 2: RR Case (Right Heavy, Inserted in Right)
    // BF < -1 means Right Heavy. data > right->data means inserted to the Right.
    if (balanceFactor < -1 && data > (root->right->data))
        return leftRotate(root);

    // Case 3: LR Case (Left Heavy, Inserted in Right)
    // BF > 1, but data > left->data.
    // Solution: Rotate Child LEFT, then Root RIGHT.
    if (balanceFactor > 1 && data > (root->left->data)) {
        root->left = leftRotate(root->left); // Convert LR -> LL
        return rightRotate(root);            // Fix LL
    }

    // Case 4: RL Case (Right Heavy, Inserted in Left)
    // BF < -1, but data < right->data.
    // Solution: Rotate Child RIGHT, then Root LEFT.
    if (balanceFactor < -1 && data < (root->right->data)) {
        root->right = rightRotate(root->right); // Convert RL -> RR
        return leftRotate(root);                // Fix RR
    }

    // If balanced, return the pointer unchanged
    return root;
}

// 5. STANDARD TRAVERSALS
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

// 6. MAIN MENU
int main() {
    struct node *root = NULL;
    int choice, data;

    while (true) {
        printf("\n--- AVL Tree Menu ---\n");
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
                    
                    // Crucial: Update root! 
                    // Insert might change the root due to rotations.
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
                printf("\nFreeing memory!\n");
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