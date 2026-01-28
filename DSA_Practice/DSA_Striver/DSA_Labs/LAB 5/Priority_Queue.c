#include <stdio.h>
#include <stdlib.h>

#define Priority_Level 3 
#define MAX_SIZE 5 

int priority_queues[Priority_Level][MAX_SIZE];
int front_pointers[Priority_Level];
int rear_pointers[Priority_Level];
int Enq_count = 0;
int Deq_count = 0;

void InitializeQueues() {
    for (int i = 0; i < Priority_Level; i++) {
        front_pointers[i] = -1;
        rear_pointers[i] = -1;
    }
}

void Enqueue(int val, int priority) {
    if (priority < 0 || priority >= Priority_Level) {
        printf("\nError: Invalid priority level %d.\n", priority);
        return;
    }

    int front = front_pointers[priority];
    int rear = rear_pointers[priority];

    if ((rear + 1) % MAX_SIZE == front) {
        printf("\nPriority Queue Overflow for priority %d! Cannot enqueue %d.\n", priority, val);
    }

    else if (front == -1) {
        front_pointers[priority] = 0;
        rear_pointers[priority] = 0;
        priority_queues[priority][rear_pointers[priority]] = val;
        printf("Enqueued %d with priority %d.\n", val, priority);
        Enq_count++;

        printf("Now front[%d]=%d, rear[%d]=%d\n", priority, front_pointers[priority], priority, rear_pointers[priority]);
    }

    else {
        rear_pointers[priority] = (rear + 1) % MAX_SIZE;
        priority_queues[priority][rear_pointers[priority]] = val;
        printf("Enqueued %d with priority %d.\n", val, priority);
        Enq_count++;
        printf("Now front[%d]=%d, rear[%d]=%d\n", priority, front_pointers[priority], priority, rear_pointers[priority]);
    }
}

void Dequeue() {
    int dequeued_val = -1; 
    int dequeued_priority = -1;

    for (int i = 0; i < Priority_Level; i++) {
        if (front_pointers[i] != -1) { 
            int front = front_pointers[i];
            int rear = rear_pointers[i];

            dequeued_val = priority_queues[i][front];
            dequeued_priority = i;
            Deq_count++;

            if (front == rear) {
                front_pointers[i] = -1; 
                rear_pointers[i] = -1;
            } else {
                
                front_pointers[i] = (front + 1) % MAX_SIZE;
            }
            printf("\nDequeued %d (from priority %d).\n", dequeued_val, dequeued_priority);
            printf("Now front[%d]=%d, rear[%d]=%d\n", i, front_pointers[i], i, rear_pointers[i]);
            return; 
        }
    }

    printf("\nPriority Queue Underflow! Cannot dequeue.\n");
}

void display() {
    printf("\n--- Priority Queue Contents ---\n");
    int empty_flag = 1; 

    for (int i = 0; i < Priority_Level; i++) {
        printf("Priority %d: ", i);
        int front = front_pointers[i];
        int rear = rear_pointers[i];

        if (front == -1) {
            printf("[Empty]\n");
        } else {
            empty_flag = 0;
            int current = front;
            printf("[ ");
            while (1) {
                printf("%d ", priority_queues[i][current]);
                if (current == rear) {
                    break;
                }
                current = (current + 1) % MAX_SIZE;
            }
            printf("]\n");
        }
    }
    if (empty_flag) {
        printf("All priority queues are currently empty.\n");
    }
    printf("-----------------------------\n");
}

// Main Function
int main() {
    int val, choice, priority;
    InitializeQueues(); 

    while (1) {
        printf("\n--- Priority Queue Operations ---\n");
        printf("(Priorities: 0=High, 1=Medium, 2=Low)\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to enqueue: ");
                scanf("%d", &val);
                printf("Enter priority (0-%d): ", Priority_Level - 1);
                scanf("%d", &priority);
                Enqueue(val, priority);
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting program...\n");
                printf("Total Enqueues: %d\n", Enq_count);
                printf("Total Dequeues: %d\n", Deq_count);
                exit(0);

            default:
                printf("\nInvalid choice !! Please try again.\n");
        }
    }
    return 0;
}