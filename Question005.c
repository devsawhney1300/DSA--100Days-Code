#include <stdio.h>

int main() {
    int p, q;
    int merged[200];
    // Read size of first log
    scanf("%d", &p);
    int log1[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    
    // Read size of second log
    scanf("%d", &q);
    int log2[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    
    int i = 0, j = 0,k=0;
    
    // Merge and print in chronological order
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            merged[k++]=log1[i++];
        } else 
        {
            merged[k++]=log2[j++];
        }
    }
    
    // Print remaining elements (if any)
    while (i < p) {
        merged[k++]=log1[i++];
    }
    
    while (j < q) {
        merged[k++]=log2[j++];
    }
    for (int i = 0; i < k; i++) {
        printf("%d\t", merged[i]);
    }
    
    return 0;
}