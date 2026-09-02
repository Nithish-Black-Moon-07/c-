#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// A prime number larger than 2 * max_elements to minimize collisions
#define HASH_SIZE 300007

typedef struct {
    int key;
    bool occupied;
} HashEntry;

// Simple hash function handling negative numbers
int get_hash(int key) {
    long long k = key;
    int h = k % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return h;
}

// Insert into the hash table
void insert(HashEntry* table, int key) {
    int h = get_hash(key);
    while (table[h].occupied) {
        if (table[h].key == key) return; // Duplicate found, skip
        h = (h + 1) % HASH_SIZE;
    }
    table[h].key = key;
    table[h].occupied = true;
}

// Check if a key exists in the hash table
bool contains(HashEntry* table, int key) {
    int h = get_hash(key);
    while (table[h].occupied) {
        if (table[h].key == key) return true;
        h = (h + 1) % HASH_SIZE;
    }
    return false;
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    // Allocate hash table dynamically to reset state per test case
    HashEntry* table = (HashEntry*)calloc(HASH_SIZE, sizeof(HashEntry));
    
    // Step 1: Populate the hash table
    for (int i = 0; i < numsSize; i++) {
        insert(table, nums[i]);
    }

    int longest_streak = 0;

    // Step 2: Find the longest consecutive sequence
    for (int i = 0; i < numsSize; i++) {
        int current_num = nums[i];

        // Only start a sequence check if current_num is the absolute start of a sequence
        if (!contains(table, current_num - 1)) {
            int current_streak = 1;

            // Count the length of the consecutive chain going upwards
            while (contains(table, current_num + 1)) {
                current_num += 1;
                current_streak += 1;
            }

            if (current_streak > longest_streak) {
                longest_streak = current_streak;
            }
        }
    }

    free(table);
    return longest_streak;
}
