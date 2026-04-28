#include <stdio.h>

int integerSqrt(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (mid * mid == n) {
            return mid;  // perfect square
        }
        else if (mid * mid < n) {
            ans = mid;   // store possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans; // floor value of sqrt
}

int main() {
    int n;

    // Input
    scanf("%d", &n);

    // Output
    printf("%d", integerSqrt(n));

    return 0;
}