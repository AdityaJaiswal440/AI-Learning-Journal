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

struct node* insertAtBeginning(struct node *head, int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) {
        return head;
    }

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
        printf("List was empty. Inserted %d at the end.\n", data);
        return newNode;
    }

    struct node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    
    printf("-> Inserted %d at the end.\n", data);
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
            ptr->next = newNode;
            
            printf("-> Inserted %d after %d.\n", newData, targetData);
            return head;
        }
        ptr = ptr->next;
    }
    
    printf("-> Node with data %d not found.\n", targetData);
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
    while (ptr->next != NULL) {
        if (ptr->next->data == targetData) {
            struct node* newNode = createNode(newData);
            if (newNode == NULL) {
                return head;
            }
            
            newNode->next = ptr->next;
            ptr->next = newNode;
            
            printf("-> Inserted %d before %d.\n", newData, targetData);
            return head;
        }
        ptr = ptr->next;
    }

    printf("-> Node with data %d not found.\n", targetData);
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
    
    printf("\nFreeing pointers! \n");
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    printf("Pointers freed.\n");
}

struct node* traversalToEnd(struct node* head){
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }
    struct node* ptr=head;
    while(ptr->next != NULL) {
        ptr=ptr->next;
    }
    printf("The last node is: %d",ptr->data);

    return ptr;
}

int main() {
    struct node *head = NULL;
    int choice, data, targetData;

    while (true) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Insert Before a Node\n");
        printf("5. Print List\n");
        printf("6. Exit\n");
        printf("7. Last Node Data- \n");
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
                printList(head);
                break;

            case 6:
                freeList(head);
                printf("Exiting. Goodbye!\n");
                return 0;
            
            case 7:
                traversalToEnd(head);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}