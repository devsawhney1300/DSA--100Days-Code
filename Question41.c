#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

int dequeue() {
    if (front == NULL)
        return -1;

    struct Node* temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        } else if (type == 2) {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}