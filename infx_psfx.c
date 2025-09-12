#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') {
        return 3;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if ((c >= 'A' && c <= 'Z') || 
            (c >= 'a' && c <= 'z') || 
            (c >= '0' && c <= '9')) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1 && stack[top] == '(') {
                pop(); // Remove '('
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (top != -1 && 
                   ((precedence(stack[top]) > precedence(c)) || 
                    (precedence(stack[top]) == precedence(c) && c != '^'))) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("The Postfix Expression is: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%99s", infix);
    infixToPostfix(infix);
    return 0;
}

