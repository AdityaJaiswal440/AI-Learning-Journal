#include <stdio.h>
#include <string.h>
#include <ctype.h> // For isalnum()

#define MAX_SIZE 100

// Global stack and top pointer
char stack[MAX_SIZE];
int top = -1;

// --- Stack Functions ---

void push(char val) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = val;
    } else {
        printf("Stack Overflow!\n"); // Added overflow check feedback
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0'; // Return null if stack is empty
}

int isEmpty() {
    return top == -1;
}

// --- Helper Functions ---

// Returns the precedence of an operator
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3; // Exponentiation
        default:
            return 0; // For parentheses or other characters
    }
}

// --- Core Algorithm Functions ---

/**
 * Step 1: Reverses the infix string and swaps parentheses.
 * (A + B) * C  ->  C * )B + A(
 */
void reverseInfixAndSwapParens(char* original, char* reversed) {
    int len = strlen(original);
    int j = 0; // Index for the reversed string

    // Loop through the original string from end to beginning
    for (int i = len - 1; i >= 0; i--) {
        char c = original[i];

        // Swap parentheses
        if (c == '(') {
            reversed[j++] = ')';
        } else if (c == ')') {
            reversed[j++] = '(';
        } else {
            reversed[j++] = c;
        }
    }
    reversed[j] = '\0'; // Add null terminator to the new string
}

/**
 * Step 2: Converts the (reversed) infix string to postfix.
 * This uses the global stack and the standard Shunting-Yard algorithm.
 * C * )B + A(  ->  C B A + *
 */
void infixToPostfix(char* reversed_infix, char* postfix) {
    top = -1; // Reset the global stack for a fresh conversion
    int i = 0; // Infix scanner
    int j = 0; // Postfix writer

    while (reversed_infix[i] != '\0') {
        char c = reversed_infix[i];

        // If operand, add to postfix
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop from stack to postfix until '(' is found
        else if (c == ')') {
            while (!isEmpty() && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && stack[top] == '(') {
                 pop(); // Discard the '(' from the stack
            } else {
                // Handle error: Mismatched parentheses in reversed string
                printf("Error: Mismatched parentheses detected during postfix conversion.\n");
                postfix[0] = '\0'; 
                // Clear postfix string to indicate error
                return;
            }
        }
        // If operator
        else {
            // Pop operators with higher or equal precedence
            while (!isEmpty() && stack[top] != '(' && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c); // Push the current operator
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (!isEmpty()) {
        if (stack[top] == '(') {
             // Handle error: Mismatched parentheses (extra '(' left)
             printf("Error: Mismatched parentheses detected at end of postfix conversion.\n");
             postfix[0] = '\0'; // Clear postfix string to indicate error
             return;
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Add null terminator
}

/**
 * Step 3: Reverses the final postfix string to get the prefix.
 * C B A + * ->  * + A B C
 */
void reverseString(char* postfix_temp, char* reversed) {
    int len = strlen(postfix_temp);
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        reversed[j++] = postfix_temp[i];
    }
    reversed[j] = '\0';
}

// --- Main Function ---

int main() {
    char infix[MAX_SIZE];
    char reversed_infix[MAX_SIZE];
    char postfix_temp[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression (NO SPACES ALLOWED): ");
    scanf("%s", infix); // Using scanf as requested

    // --- Execute the 3-step algorithm ---

    // Step 1:
    reverseInfixAndSwapParens(infix, reversed_infix);
    // Optional: Print intermediate step
    // printf("\nReversed Infix (swapped): %s\n", reversed_infix);

    // Step 2:
    infixToPostfix(reversed_infix, postfix_temp);
    // Optional: Print intermediate step
    // printf("Intermediate Postfix: %s\n", postfix_temp);

    // Check if postfix conversion resulted in an error (e.g., mismatched parens)
    if (strlen(postfix_temp) == 0 && strlen(infix) > 0) {
         printf("\nConversion failed due to errors in the expression.\n");
         return 1; // Indicate error
    }


    // Step 3:
    reverseString(postfix_temp, prefix);

    printf("\nOriginal Infix: %s\n", infix);
    printf("Resulting Prefix: %s\n", prefix);

    return 0;
}