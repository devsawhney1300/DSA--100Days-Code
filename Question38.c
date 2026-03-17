#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

// Check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Check if deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Insert at front
void push_front(int value) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }

    if (front == -1) {   // first element
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = value;
}

// Insert at rear
void push_back(int value) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }

    if (front == -1) {  // first element
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

// Delete from front
void pop_front() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Delete from rear
void pop_back() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// Get front element
void getFront() {
    if (isEmpty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

// Get rear element
void getRear() {
    if (isEmpty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

// Display deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    printf("Deque elements: ");

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(1);

    display();

    pop_front();
    pop_back();

    display();

    getFront();
    getRear();

    return 0;
}