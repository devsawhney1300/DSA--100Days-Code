#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];
    int votes[MAX] = {0};
    int unique = 0;

    for (int i = 0; i < n; i++) {
        char temp[LEN];
        scanf("%s", temp);

        int found = -1;

        // Check if name already exists
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            votes[found]++;
        } else {
            strcpy(names[unique], temp);
            votes[unique] = 1;
            unique++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[LEN];

    for (int i = 0; i < unique; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            strcpy(winner, names[i]);
        } 
        else if (votes[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}