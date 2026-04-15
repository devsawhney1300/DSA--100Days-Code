#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};  // for 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        freq[index]++;

        if (freq[index] == 2) {   // second occurrence found
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // no repeated character
    printf("-1\n");

    return 0;
}