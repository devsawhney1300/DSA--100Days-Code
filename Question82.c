#include <stdio.h>

// Function to find Lower Bound (first index where arr[i] >= x)
int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n; // default if not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            right = mid - 1; // move left
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

// Function to find Upper Bound (first index where arr[i] > x)
int upperBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n; // default if not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > x) {
            ans = mid;
            right = mid - 1; // move left
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}