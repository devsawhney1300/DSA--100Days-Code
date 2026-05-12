#include <stdio.h>
#include <stdlib.h>

// Structure for interval
typedef struct {
    int start, end;
} Interval;

// Compare function for sorting by start time
int compare(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Function to merge intervals
void mergeIntervals(Interval arr[], int n) {
    if (n == 0) return;

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    // Result array (in-place)
    int index = 0;

    for (int i = 1; i < n; i++) {
        // If overlapping → merge
        if (arr[index].end >= arr[i].start) {
            if (arr[i].end > arr[index].end)
                arr[index].end = arr[i].end;
        } else {
            // No overlap → move forward
            index++;
            arr[index] = arr[i];
        }
    }

    // Print merged intervals
    printf("Merged intervals:\n");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", arr[i].start, arr[i].end);
    }
    printf("\n");
}

// Main
int main() {
    Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeIntervals(arr, n);

    return 0;
}