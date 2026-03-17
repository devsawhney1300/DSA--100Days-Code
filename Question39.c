#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// Swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && heap[parent] > heap[index]) {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert operation
void insert(int x) {
    if (size >= MAX)
        return;

    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Peek operation
void peek() {
    if (size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

// Extract Min
void extractMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

int main() {
    int N, x;
    char operation[20];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(operation, "extractMin") == 0) {
            extractMin();
        }
        else if (strcmp(operation, "peek") == 0) {
            peek();
        }
    }

    return 0;
}