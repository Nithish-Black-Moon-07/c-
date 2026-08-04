#include <stdio.h>

// Helper function to return the greater of two values
int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

// Function to find the greatest of four integers
int max_of_four(int a, int b, int c, int d) {
    // Compare the first two, then compare the last two, and find the max of the results
    int left_max = max(a, b);
    int right_max = max(c, d);
    return max(left_max, right_max);
}

int main() {
    int a, b, c, d;
    // Read four integers from standard input
    if (scanf("%d\n%d\n%d\n%d", &a, &b, &c, &d) == 4) {
        int ans = max_of_four(a, b, c, d);
        printf("%d\n", ans);
    }
    return 0;
}
