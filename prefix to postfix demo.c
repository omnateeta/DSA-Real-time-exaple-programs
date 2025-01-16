#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct Stack {
    int top;
    char* items[MAX];
} Stack;

// Initialize stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push an item to the stack
void push(Stack* s, char* item) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = strdup(item);
}

// Pop an item from the stack
char* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return NULL;
    }
    return s->items[s->top--];
}

// Function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to convert prefix to postfix
void prefixToPostfix(char* prefix) {
	int i;
    Stack stack;
    initStack(&stack);
    
    int length = strlen(prefix);

    // Traverse the prefix expression in reverse order
    for (i = length - 1; i >= 0; i--) {
        // If the character is an operator
        if (isOperator(prefix[i])) {
            // Pop two operands from the stack
            char* operand1 = pop(&stack);
            char* operand2 = pop(&stack);

            // Create a new string in the format operand1 operand2 operator
            char* temp = (char*)malloc(strlen(operand1) + strlen(operand2) + 2);
            sprintf(temp, "%s%s%c", operand1, operand2, prefix[i]);

            // Push the resulting string back to the stack
            push(&stack, temp);

            // Free the temporary strings
            free(operand1);
            free(operand2);
        } else {
            // If the character is an operand, push it to the stack
            char operand[2] = {prefix[i], '\0'};
            push(&stack, operand);
        }
    }

    // The final result will be at the top of the stack
    char* result = pop(&stack);
    printf("Postfix expression: %s\n", result);
    free(result);
}

int main() {
    char prefix[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix);

    return 0;
}

