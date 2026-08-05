#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s) {
    // 1. Find the longest non-increasing suffix from the right
    int i = n - 1;
    while (i > 0 && strcmp(s[i - 1], s[i]) >= 0) {
        i--;
    }
    
    // If the entire array is non-increasing, it is the last permutation
    if (i <= 0) {
        return 0;
    }
    
    // 2. Identify the pivot element (s[i - 1]) and find the rightmost element 
    // in the suffix that is lexicographically larger than the pivot
    int j = n - 1;
    while (strcmp(s[i - 1], s[j]) >= 0) {
        j--;
    }
    
    // Swap the pivot with this element
    char *tmp = s[i - 1];
    s[i - 1] = s[j];
    s[j] = tmp;
    
    // 3. Reverse the entire suffix to get the smallest lexicographical arrangement
    j = n - 1;
    while (i < j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
    
    return 1;
}


int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
