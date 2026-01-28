#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

int front=-1,rear=-1;
int linear_queue[MAX_SIZE];
int Enq_count=0,Deq_count=0;

void Enqueue(int val) {
    if(rear == MAX_SIZE-1) {
        printf("\n Condition of Overflow !!. Can't Enqueue %d\n", val);
    }
    else if(front==-1 && rear == -1) {
    front=0;
    rear=0;
    linear_queue[rear] = val;
    printf("Enqueued: %d\n",val);
    Enq_count++;
    printf("\nNow front = %d and rear = %d\n", front ,rear);
    }
    else {
        rear++;
        linear_queue[rear] = val;
        printf("Enqueued: %d\n",val);
        Enq_count++;
        printf("\nNow front = %d and rear = %d", front ,rear);
    }
}

void Dequeue() {
    if ((front == -1 && rear == -1)|| front > rear) {
        printf("\nQueue Underflow !! Cannot dequeue.\n");
        if (front > rear) {
             front = -1;
             rear = -1;
        }
    } else {
        linear_queue[front];
        printf("\nDequeued: %d\n", linear_queue[front]);
        front++;
        Deq_count++;
        if (front > rear) {
             front = -1;
             rear = -1;
        }
        printf("\nNow front = %d and rear = %d", front ,rear);
    }
}

void display() {
    if(front == -1) {
        printf("Queue is Empty !!");
    }
    for(int i = front;i<=rear;i++) {
        printf("\t %d",linear_queue[i]);
    }
    printf("\n");
}

int main() {
    int val,choice; 
    while(1) {
        printf("\n--- Queue Operations ---\n");
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