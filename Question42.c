#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    for (int i = front; i <= rear; i++) {
        push(queue[i]);
    }

    for (int i = front; i <= rear; i++) {
        queue[i] = pop();
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}