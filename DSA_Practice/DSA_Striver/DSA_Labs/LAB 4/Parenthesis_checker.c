#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char val) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = val;
    }
}
char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0'; 
}

// Checks if the stack is empty
int isEmpty() {
    return top == -1;
}

// Checks if two characters are a matching pair of brackets
int areMatching(char open_br, char close_br) {
    if (open_br == '(' && close_br == ')') return 1;
    if (open_br == '{' && close_br == '}') return 1;
    if (open_br == '[' && close_br == ']') return 1;
    return 0;
}

// Parenthesis Checker function
int areParenthesesBalanced(char* exp) {
    top = -1; 
    // Ensure the stack is empty for each new check
    int i;
    int len = strlen(exp);

    for (i = 0; i < len; i++) {
        // If it's an opening bracket, push it onto the stack
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(exp[i]);
        }
        // If it's a closing bracket
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            // Case 1: Closing bracket with no matching opener
            if (isEmpty()) {
                return 0; // Not balanced
            }
            // Case 2: Mismatched brackets (e.g., '{' and ')')
            if (!areMatching(pop(), exp[i])) {
                return 0; // Not balanced
            }
        }
    }

    // Case 3: Unmatched opening brackets left on the stack
    return isEmpty();
}

int main() {
    char exp[MAX_SIZE];

    printf("Enter an expression (NO SPACES ALLOWED !!): ");
    scanf("%s", exp); 

    if (areParenthesesBalanced(exp)) {
        printf("\nResult: The expression is Balanced.\n");
    } else {
        printf("\nResult: The expression is NOT Balanced.\n");
    }

    return 0;
}