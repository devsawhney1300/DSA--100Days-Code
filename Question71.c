#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define SIZE 100

int table[SIZE];
int m; // size of hash table

// Hash function
int hash(int key) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

// Search using quadratic probing
void search(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        }
        else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}