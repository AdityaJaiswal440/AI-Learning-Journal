#include <stdio.h>

int stack[100], top = -1, MAX;
int pushcount = 0, popcount = 0;

// Push function
void push(int val) {
    if(top == MAX - 1) {
        printf("\nStack Overflow -- Can't push %d\n", val);
    } else {
        stack[++top] = val;
        // increment top and insert value
        pushcount++;
        printf("\nPushed: %d\n", val);
        printf("Stack now: ");
        for(int i = top; i >= 0; i--) {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

// Pop function
void pop() {
    if(top == -1) {
        printf("\nStack Underflow -- Stack is empty!\n");
    } else {
        printf("\nPopped: %d\n", stack[top--]);
        popcount++;
        if(top >= 0) {
            printf("Stack after pop: ");
            for(int i = top; i >= 0; i--) {
                printf("%d\t", stack[i]);
            }
            printf("\n");
        } else {
            printf("Now the stack is empty\n");
        }
    }
}

void peek() {
    if(top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nTop element: %d\n", stack[top]);
    }
}

void display() {
    if(top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("\nStack elements (top to bottom): ");
        for(int i = top; i >= 0; i--) {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, val;
    printf("Enter the maximum size of stack: ");
    scanf("%d", &MAX);

    while(1) {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting program...\n");
                printf("Total push operations: %d\n", pushcount);
                printf("Total pop operations: %d\n", popcount);
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
}
