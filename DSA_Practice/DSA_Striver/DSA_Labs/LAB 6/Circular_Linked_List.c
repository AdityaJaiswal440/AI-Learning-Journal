#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory Overflow !!\n");
    } else {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void printList(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = head;
    printf("CURRENT LIST: ");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("(ptr back to %d)\n", head->data);
}

void freeList(struct node *head) {
    if (head == NULL) {
        printf("\nList is already empty.\n");
        return;
    }

    struct node *ptr = head;
    struct node *last = head;
    struct node *temp;

    while (last->next != head) {
        last = last->next;
    }
    last->next = NULL;

    printf("\nFreeing the pointers !\n");
    ptr = head;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    printf("Pointers freed !\n");
}

struct node* insertAtBeginning(struct node *head, int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        printf("Inserted %d at the beginning.\n", data);
        return head;
    }

    struct node *ptr = head;
    while (ptr->next != head) {
        ptr = ptr->next;
    }
    
    ptr->next = newNode;
    newNode->next = head;
    head = newNode;
    
    printf("Inserted %d at the beginning.\n", data);
    return head;
}

struct node* insertAtEnd(struct node *head, int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        printf("Inserted %d at the end.\n", data);
        return head;
    }

    struct node *ptr = head;
    while (ptr->next != head) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->next = head;
    
    printf("-> Inserted %d at the end.\n", data);
    return head;
}

struct node* insertAfter(struct node *head, int targetData, int newData) {
    if (head == NULL) {
        printf("List is empty. Cannot insert.\n");
        return NULL;
    }

    struct node *ptr = head;

    do {
        if (ptr->data == targetData) {
            struct node* newNode = createNode(newData);
            if (newNode == NULL) {
                return head;
            }
            
            newNode->next = ptr->next;
            ptr->next = newNode;
            
            printf("Inserted %d after %d.\n", newData, targetData);
            return head;
        }
        ptr = ptr->next;
    } while (ptr != head);

    printf("Node with data %d not found.\n", targetData);
    return head;
}

struct node* insertBefore(struct node *head, int targetData, int newData) {
    if (head == NULL) {
        printf("List is empty. Cannot insert.\n");
        return NULL;
    }

    if (head->data == targetData) {
        return insertAtBeginning(head, newData);
    }

    struct node *ptr = head;
    
    do {
        if (ptr->next->data == targetData) {
            struct node* newNode = createNode(newData);
            if (newNode == NULL) {
                return head;
            }
            
            newNode->next = ptr->next;
            ptr->next = newNode;
            
            printf("Inserted %d before %d.\n", newData, targetData);
            return head;
        }
        ptr = ptr->next;
    } while (ptr != head);

    printf("Node with data %d not found.\n", targetData);
    return head;
}

struct node* deleteAtBeginning(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    if (head->next == head) {
        printf("Deleted %d. List - now empty.\n", head->data);
        free(head);
        return NULL;
    }

    struct node *ptr = head;
    struct node *temp = head;

    while (ptr->next != head) {
        ptr = ptr->next;
    }

    head = head->next;
    ptr->next = head;
    
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
    
    return head;
}

struct node* deleteAtEnd(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    if (head->next == head) {
        printf("Deleted %d. List is now empty.\n", head->data);
        free(head);
        return NULL;
    }

    struct node *ptr = head;
    struct node *preptr = NULL;

    while (ptr->next != head) {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = head;
    printf("Deleted %d from the end.\n", ptr->data);
    free(ptr);
    
    return head;
}

struct node* deleteSpecific(struct node *head, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->data == data) {
        return deleteAtBeginning(head);
    }

    struct node *ptr = head->next;
    struct node *preptr = head;

    while (ptr != head) {
        if (ptr->data == data) {
            preptr->next = ptr->next;
            printf("Deleted specific node %d.\n", ptr->data);
            free(ptr);
            return head;
        }
        preptr = ptr;
        ptr = ptr->next;
    }

    printf("Node with data %d not found.\n", data);
    return head;
}

int main() {
    struct node *head = NULL;
    int choice, data, targetData;

    while (true) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("\n--- Insertion ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Insert Before a Node\n");
        printf("\n--- Deletion ---\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete Specific Node\n");
        printf("8. Print List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

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