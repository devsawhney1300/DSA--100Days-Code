#include <stdio.h>

// Function to check if allocation is possible
int canAllocate(int pages[], int n, int m, int maxPages) {
    int student_count = 1;
    int current_pages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book exceeds maxPages → not possible
        if (pages[i] > maxPages)
            return 0;

        // If adding this book exceeds limit → assign new student
        if (current_pages + pages[i] > maxPages) {
            student_count++;
            current_pages = pages[i];

            if (student_count > m)
                return 0;
        } else {
            current_pages += pages[i];
        }
    }

    return 1; // allocation possible
}

// Main function
int allocateBooks(int pages[], int n, int m) {
    int left = 0, right = 0;

    // Find max and sum
    for (int i = 0; i < n; i++) {
        if (pages[i] > left)
            left = pages[i];   // max element
        right += pages[i];     // total sum
    }

    int ans = right;

    // Binary Search
    while (left <= right) {
        int mid = (left + right) / 2;

        if (canAllocate(pages, n, m, mid)) {
            ans = mid;
            right = mid - 1;  // try smaller max
        } else {
            left = mid + 1;   // increase limit
        }
    }

    return ans;
}

// Driver code
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    int result = allocateBooks(pages, n, m);
    printf("%d\n", result);

    return 0;
}