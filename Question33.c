#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;
void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
char peek() {
    return stack[top];
}
int precedence(char op) {
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}
int main() {
    char infix[100], postfix[100];
    int k = 0;
    scanf("%s", infix);
    for(int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if(isalnum(c)) { 
            postfix[k++] = c;
        }
        else { 
            while(top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while(top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf("%s", postfix);
    return 0;
}