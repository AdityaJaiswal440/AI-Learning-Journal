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
        printf("OVERFLOW: Could not allocate memory!\n");
    } else {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

struct node* insertAtEnd(struct node *head, int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }
    
    if (head == NULL) {
        printf("List was empty. Inserted %d.\n", data);
        return newNode;
    }

    struct node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    printf("Inserted %d at the end.\n", data);
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
    
    printf("\nFreeing all memory...\n");
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    printf("Memory freed.\n");
}

struct node* deleteAtBeginning(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    struct node *temp = head;
    head = head->next;
    
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
    
    return head;
}

struct node* deleteAtEnd(struct node *head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        printf("Deleted %d (the last node) from the end.\n", head->data);
        free(head);
        return NULL;
    }

    struct node *ptr = head;
    struct node *preptr = NULL;
    
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;
    printf("Deleted %d from the end.\n", ptr->data);
    free(ptr);
    
    return head;
}

struct node* deleteAfter(struct node *head, int targetData) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    struct node *ptr = head;

    while (ptr != NULL && ptr->data != targetData) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with data %d not found.\n", targetData);
        return head;
    }

    if (ptr->next == NULL) {
        printf("No node exists after %d to delete.\n", targetData);
        return head;
    }

    struct node *temp = ptr->next;
    ptr->next = temp->next;
    
    printf("Deleted %d (the node after %d).\n", temp->data, targetData);
    free(temp);
    
    return head;
}

int main() {
    struct node *head = NULL;
    int choice, data, targetData;

    while (true) {
        printf("\n--- Singly Linked List Deletion ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete After a Given Node\n");
        printf("5. Print List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printList(head);
                break;

            case 2:
                head = deleteAtBeginning(head);
                printList(head);
                break;

            case 3:
                head = deleteAtEnd(head);
                printList(head);
                break;

            case 4:
                printf("Enter data of the node to delete AFTER: ");
                scanf("%d", &targetData);
                head = deleteAfter(head, targetData);
                printList(head);
                break;
                
            case 5:
                printList(head);
                break;

            case 6:
                freeList(head);
                printf("Exiting.!\n");
                return 0;

            default:
                printf("Invalid choice.!!\n");
        }
    }
    return 0;
}