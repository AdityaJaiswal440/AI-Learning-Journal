// first index comes right after last index.
// this concept introduced to avoid wastage of memory.
// A circular queue is full, only when front = 0 and rear = Max – 1.

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

int front=-1,rear=-1;
int Circular_queue[MAX_SIZE];
int Enq_count=0,Deq_count=0;

void Enqueue(int val) {
    if((rear+1) % MAX_SIZE == front) {
        printf("\n Condition of Overflow !!. Can't Enqueue %d\n", val);
    }
    else if (front == -1){
        front = 0;
        rear = 0 ;
        Circular_queue[rear] = val;
        printf("Enqueued: %d\n", val);
        printf("Now front = %d and rear = %d\n", front, rear);
        Enq_count++;

    }
    else {
        rear = (rear + 1) % MAX_SIZE;
        Circular_queue[rear] = val;
        printf("Enqueued: %d\n", val);
        Enq_count++;
        printf("Now front = %d and rear = %d\n", front, rear);
    }
}

void Dequeue() {
    if (front == -1) {
        printf("\nCircular Queue Underflow !! Cannot dequeue.\n");
    }
    else {
        Circular_queue[front];
        printf("\nDequeued: %d\n",Circular_queue[front]);
        Deq_count++;
        if (front == rear) {
            // Reset the queue to empty
            front = -1;
            rear = -1;
        }

        else {
            front = (front + 1) % MAX_SIZE;
            // updates index of front using modulus.
        }
        printf("Now front = %d and rear = %d\n", front, rear);
    }
}

void display() {
    if(front == -1) {
        printf("\nCircular Queue is Empty !!");
    }
    else {
        printf("\nCircular Queue elements (Front to Rear):\n");
        int i = front;

        while (1) {
            printf("\t%d", Circular_queue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
    }
    printf("\n");
}

int main() {
    int val,choice; 

    while(1) {
        printf("\n---Circular Queue Operations ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit \n");
        printf("Enter your choice: \t");
        scanf("%d", &choice);

        switch(choice) {
            case 1 : 
                printf("\nEnter the value to enqueue:");
                scanf("%d",&val);
                Enqueue(val);
                break;
            case 2 :
                Dequeue();
                break;
            case 3:
                printf("\nThe Queue is as follow : \n");
                display();
                break;
            case 4:
                printf("\n Exiting program...\n");
                printf("Total Enqueue counts: %d\n",Enq_count);
                printf("Total Dequeue counts: %d\n",Deq_count);
                exit(0);
            default: 
                printf("Invalid choice !!");
                break;
        }
    }
    return 0;
}