#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if cows can be placed with minimum distance 'dist'
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int count = 1;              // first cow placed
    int last_pos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_pos >= dist) {
            count++;
            last_pos = stalls[i];
        }
        if (count >= k)
            return 1;  // possible
    }
    return 0;  // not possible
}

// Main function
int aggressiveCows(int stalls[], int n, int k) {
    // Step 1: sort stalls
    qsort(stalls, n, sizeof(int), compare);

    int left = 1;
    int right = stalls[n - 1] - stalls[0];
    int ans = 0;

    // Step 2: binary search
    while (left <= right) {
        int mid = (left + right) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            ans = mid;
            left = mid + 1;   // try larger distance
        } else {
            right = mid - 1;  // reduce distance
        }
    }

    return ans;
}

// Driver code
int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int stalls[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    int result = aggressiveCows(stalls, n, k);
    printf("%d\n", result);

    return 0;
}