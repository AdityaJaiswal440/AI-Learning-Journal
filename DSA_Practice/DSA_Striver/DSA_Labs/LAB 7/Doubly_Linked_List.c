#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("OVERFLOW: Could not allocate memory!\n");
    } else {
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    return newNode;
}

struct node* insertAtBeginning(struct node *head, int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }

    if (head != NULL) {
        head->prev = newNode;
    }
    newNode->next = head;
    head = newNode;

    printf("-> Inserted %d at the beginning.\n", data);
    return head;
}

struct node* insertAtEnd(struct node *head, int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }
    
    if (head == NULL) {
        printf(" List was empty. Inserted %d at the end.\n", data);
        return newNode;
    }

    struct node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->prev = ptr;
    
    printf(" Inserted %d at the end.\n", data);
    return head;
}

struct node* insertAfter(struct node *head, int targetData, int newData) {
    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->data == targetData) {
            struct node* newNode = createNode(newData);
            if (newNode == NULL) {
                return head;
            }

            newNode->next = ptr->next;
            newNode->prev = ptr;

            if (ptr->next != NULL) {
                ptr->next->prev = newNode;
            }
            ptr->next = newNode;
            
            printf(" Inserted %d after %d.\n", newData, targetData);
            return head;
        }
        ptr = ptr->next;
    }
    
    printf(" Node with data %d not found.\n", targetData);
    return head;
}

struct node* insertBefore(struct node *head, int targetData, int newData) {
    if (head == NULL) {
        printf("-> List is empty, cannot insert before.\n");
        return NULL;
    }

    if (head->data == targetData) {
        return insertAtBeginning(head, newData);
    }

    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->data == targetData) {
            struct node* newNode = createNode(newData);
            if (newNode == NULL) {
                return head;
            }
            
            newNode->next = ptr;
            newNode->prev = ptr->prev;

            if (ptr->prev != NULL) {
                ptr->prev->next = newNode;
            }
            ptr->prev = newNode;
            
            printf("-> Inserted %d before %d.\n", newData, targetData);
            return head;
        }
        ptr = ptr->next;
    }

    printf("-> Node with data %d not found.\n", targetData);
    return head;
}

struct node* deleteAtBeginning(struct node *head) {
    if (head == NULL) {
        printf("-> List is already empty.\n");
        return NULL;
    }

    struct node *temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }
    
    printf("-> Deleted %d from the beginning.\n", temp->data);
    free(temp);
    
    return head;
}

struct node* deleteAtEnd(struct node *head) {
    if (head == NULL) {
        printf("-> List is already empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        printf("-> Deleted %d (the last node).\n", head->data);
        free(head);
        return NULL;
    }

    struct node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->prev->next = NULL;
    printf("-> Deleted %d from the end.\n", ptr->data);
    free(ptr);
    
    return head;
}

struct node* deleteSpecific(struct node *head, int data) {
    if (head == NULL) {
        printf("-> List is empty.\n");
        return NULL;
    }

    if (head->data == data) {
        return deleteAtBeginning(head);
    }

    struct node *ptr = head;
    while (ptr != NULL && ptr->data != data) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("-> Node with data %d not found.\n", data);
        return head;
    }

    ptr->prev->next = ptr->next;
    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }
    
    printf("-> Deleted specific node %d.\n", ptr->data);
    free(ptr);
    
    return head;
}

void printList(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = head;
    printf("CURRENT LIST: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void freeList(struct node *head) {
    struct node *ptr = head;
    struct node *temp;
    
    printf("\nFreeing memory!\n");
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    printf("Memory freed.\n");
}

int main() {
    struct node *head = NULL;
    int choice, data, targetData;

    while (true) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("--- Insertion ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Insert Before a Node\n");
        printf("--- Deletion ---\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete Specific Node\n");
        printf("8. Print List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); 
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printList(head);
                break;

            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printList(head);
                break;

            case 3:
                printf("Enter the node to insert after: ");
                scanf("%d", &targetData);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAfter(head, targetData, data);
                printList(head);
                break;

            case 4:
                printf("Enter the node to insert before: ");
                scanf("%d", &targetData);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertBefore(head, targetData, data);
                printList(head);
                break;
            
            case 5:
                head = deleteAtBeginning(head);
                printList(head);
                break;

            case 6:
                head = deleteAtEnd(head);
                printList(head);
                break;

            case 7:
                printf("Enter data of node to delete: ");
                scanf("%d", &data);
                head = deleteSpecific(head, data);
                printList(head);
                break;
                
            case 8:
                printList(head);
                break;

            case 9:
                freeList(head);
                printf("Exiting. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}