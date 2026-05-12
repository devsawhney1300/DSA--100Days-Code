#include <stdio.h>
#include <stdlib.h>

// Structure for intervals
typedef struct {
    int start, end;
} Interval;

// Compare function for qsort (sort by start time)
int compare(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Min Heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[(index - 1)/2] > heap[index]) {
        swap(&heap[(index - 1)/2], &heap[index]);
        index = (index - 1)/2;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Insert into heap
void push(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

// Remove min element
int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

// Get min element
int top(int heap[]) {
    return heap[0];
}

// Function to find minimum rooms
int minMeetingRooms(Interval intervals[], int n) {
    if (n == 0) return 0;

    // Step 1: Sort by start time
    qsort(intervals, n, sizeof(Interval), compare);

    int *heap = (int*)malloc(n * sizeof(int));
    int size = 0;

    // Add first meeting end time
    push(heap, &size, intervals[0].end);

    // Process remaining meetings
    for (int i = 1; i < n; i++) {
        // If room is free
        if (intervals[i].start >= top(heap)) {
            pop(heap, &size);
        }
        // Allocate room (push end time)
        push(heap, &size, intervals[i].end);
    }

    int result = size;
    free(heap);
    return result;
}

// Main
int main() {
    Interval intervals[] = {{0,30}, {5,10}, {15,20}};
    int n = sizeof(intervals)/sizeof(intervals[0]);

    printf("Minimum rooms required: %d\n", minMeetingRooms(intervals, n));

    return 0;
}