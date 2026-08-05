#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1001];
    int frequencies[10] = {0}; // Array to store counts for digits 0-9

    // Read the input string
    if (scanf("%1000s", s) == 1) {
        int length = strlen(s);

        // Iterate through each character of the string
        for (int i = 0; i < length; i++) {
            // Check if the character is a digit
            if (isdigit(s[i])) {
                int digit = s[i] - '0'; // Convert char to integer index
                frequencies[digit]++;
            }
        }

        // Print the frequencies separated by space
        for (int i = 0; i < 10; i++) {
            printf("%d", frequencies[i]);
            if (i < 9) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
