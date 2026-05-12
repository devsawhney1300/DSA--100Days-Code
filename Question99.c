#include <stdio.h>
#include <stdlib.h>

// Structure to store car data
typedef struct {
    int position;
    int speed;
} Car;

// Compare function (sort by position descending)
int compare(const void* a, const void* b) {
    return ((Car*)b)->position - ((Car*)a)->position;
}

// Function to count car fleets
int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    // Step 1: Store data
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Step 2: Sort by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    float lastTime = 0.0;

    // Step 3: Traverse
    for (int i = 0; i < n; i++) {
        float time = (float)(target - cars[i].position) / cars[i].speed;

        // New fleet condition
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}

// Main
int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);

    printf("Number of car fleets: %d\n", carFleet(target, position, speed, n));

    return 0;
}