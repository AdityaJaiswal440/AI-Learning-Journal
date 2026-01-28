#include <stdio.h>
#include <string.h>
#include <ctype.h> // For isdigit()
#include <stdlib.h> // For atoi() - converts string to integer
#include <math.h>   // For pow() if you want to support exponentiation

#define MAX_SIZE 100

// Stack for evaluation (holds numbers)
int eval_stack[MAX_SIZE];
int eval_top = -1;

// --- Integer Stack Functions ---

void push_int(int val) {
    if (eval_top < MAX_SIZE - 1) {
        eval_stack[++eval_top] = val;
    } else {
        printf("Evaluation Stack Overflow!\n");
    }
}

int pop_int() {
    if (eval_top != -1) {
        return eval_stack[eval_top--];
    }
    printf("Evaluation Stack Underflow!\n");
    return 0; // Return 0 or handle error appropriately
}

int isEmpty_int() {
    return eval_top == -1;
}

// --- Core Evaluation Logic ---

/**
 * Evaluates a given prefix expression.
 * Assumes single-digit numbers for simplicity in this basic version.
 * Scans from right to left.
 */
int evaluatePrefix(char* prefix_exp) {
    int len = strlen(prefix_exp);

    // Scan the prefix expression from right to left
    // right to left associativity.
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix_exp[i];

        // If the character is a digit (operand)
        if (isdigit(c)) {
            // Convert character digit to integer and push
            push_int(c - '0');
             // casting character to integer.
        }
        // If the character is an operator
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Pop two operands from the stack
            // Note: Order matters for prefix evaluation from right to left
            int operand1 = pop_int();
            int operand2 = pop_int();

            // Perform the operation based on the operator
            switch (c) {
                case '+':
                    push_int(operand1 + operand2);
                    break;
                case '-':
                    push_int(operand1 - operand2); // Correct order for right-to-left
                    break;
                case '*':
                    push_int(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero!\n");
                        return 0; // Indicate error
                    }
                    push_int(operand1 / operand2); // Correct order for right-to-left
                    break;
                // Add case for '^' if needed, using pow() from math.h
                case '^':
                    push_int(pow(operand1, operand2));
                    break;
            }
        }
        // Ignore other characters (like spaces, if any)
    }

    // After the loop, the final result is the only element left on the stack
    if (!isEmpty_int()) {
        return pop_int();
    } else {
        printf("Error: Invalid prefix expression.\n");
        return 0; // Indicate error
    }
}

// --- Main Function ---

int main() {
    char prefix_exp[MAX_SIZE];

    printf("Enter a prefix expression (single digits, NO SPACES): ");
    scanf("%s", prefix_exp); // Using scanf as requested

    int result = evaluatePrefix(prefix_exp);

    printf("\nOriginal Prefix: %s\n", prefix_exp);
    // returns 0 if evaluation produced an error.
    printf("Evaluation Result: %d\n", result);

    return 0;
}