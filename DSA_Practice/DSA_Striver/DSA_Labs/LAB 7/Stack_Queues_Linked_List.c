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

void printStack(struct node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct node *ptr = top;
    printf("STACK (Top to Bottom): ");
    while (ptr != NULL) {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void printQueue(struct node *front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node *ptr = front;
    printf("QUEUE (Front to Rear): ");
    while (ptr != NULL) {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct node* push(struct node *top, int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) {
        return top;
    }

    newNode->next = top;
    top = newNode;

    printf(" Pushed %d onto the stack.\n", data);
    return top;
}

struct node* pop(struct node *top) {
    if (top == NULL) {
        printf("UNDERFLOW: Stack is empty. Cannot pop.\n");
        return NULL;
    }

    struct node *temp = top;
    top = top->next;
    
    printf(" Popped %d from the stack.\n", temp->data);
    free(temp);
    
    return top;
}

void enqueue(struct node **front, struct node **rear, int data) {
    struct node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }

    if (*rear == NULL) {
        *front = newNode;
        *rear = newNode;
        printf(" Enqueued %d (first item).\n", data);
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
    
    printf(" Enqueued %d to the queue.\n", data);
}

struct node* dequeue(struct node *front, struct node **rear) {
    if (front == NULL) {
        printf("UNDERFLOW: Queue is empty. Cannot dequeue.\n");
        return NULL;
    }

    struct node *temp = front;
    front = front->next;

    if (front == NULL) {
        *rear = NULL;
    }
    
    printf(" Dequeued %d from the queue.\n", temp->data);
    free(temp);
    
    return front;
}

void freeList(struct node *head) {
    struct node *ptr = head;
    struct node *temp;
    
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}

int main() {
    struct node *stackTop = NULL;
    struct node *queueFront = NULL;
    struct node *queueRear = NULL;
    
    int choice, data;

    while (true) {
        printf("--- Stack ---\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Display Stack\n");
        printf("--- Queue ---\n");
        printf("4. Enqueue (Insert)\n");
        printf("5. Dequeue (Delete)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                stackTop = push(stackTop, data);
                printStack(stackTop);
                break;

            case 2: 
                stackTop = pop(stackTop);
                printStack(stackTop);
                break;

            case 3:
                printStack(stackTop);
                break;

            case 4:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queueFront, &queueRear, data);
                printQueue(queueFront);
                break;
            
            case 5:
                queueFront = dequeue(queueFront, &queueRear);
                printQueue(queueFront);
                break;

            case 6:
                printQueue(queueFront);
                break;
                
            case 7:
                printf("\nFreeing all memory...\n");
                freeList(stackTop);
                freeList(queueFront);
                printf("Memory freed. Exiting. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}