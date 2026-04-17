#include <stdio.h>

#define MAX 1000

// Simple hash map using arrays
int hash[2001];  // to handle negative sums
int indexMap[2001];

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Initialize hash
    for (int i = 0; i < 2001; i++)
        hash[i] = -2;  // -2 means not visited

    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int key = sum + 1000; // shift to handle negative

        if (hash[key] == -2) {
            hash[key] = i;  // store first occurrence
        } else {
            int len = i - hash[key];
            if (len > maxLen)
                maxLen = len;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}