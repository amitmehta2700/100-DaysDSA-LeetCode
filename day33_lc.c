#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int evalRPN(char **tokens, int tokensSize) {
    int stack[10000];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        
        // Check if operator
        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {

            int b = stack[top--];
            int a = stack[top--];

            int result;

            if (strcmp(tokens[i], "+") == 0)
                result = a + b;
            else if (strcmp(tokens[i], "-") == 0)
                result = a - b;
            else if (strcmp(tokens[i], "*") == 0)
                result = a * b;
            else
                result = a / b; // truncates toward zero

            stack[++top] = result;
        }
        else {
            // Convert string to integer
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}