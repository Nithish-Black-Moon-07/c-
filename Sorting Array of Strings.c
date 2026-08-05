#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Sort lexicographically in increasing order
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// 2. Sort lexicographically in decreasing order
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// Helper to count distinct characters in a string
int count_distinct(const char* str) {
    int count = 0;
    int hash[26] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        if (hash[str[i] - 'a'] == 0) {
            hash[str[i] - 'a'] = 1;
            count++;
        }
    }
    return count;
}

// 3. Sort by number of distinct characters
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int distinct_a = count_distinct(a);
    int distinct_b = count_distinct(b);
    if (distinct_a == distinct_b) {
        return strcmp(a, b);
    }
    return distinct_a - distinct_b;
}

// 4. Sort by string length
int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    if (len_a == len_b) {
        return strcmp(a, b);
    }
    return len_a - len_b;
}

// Custom sorting function using Bubble Sort
void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
