#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
long long calculate_square_area(triangle tr) {
    long long a = tr.a;
    long long b = tr.b;
    long long c = tr.c;
    // Scaled version of Heron's formula: 16 * S^2 = (a+b+c)*(b+c-a)*(a+c-b)*(a+b-c)
    return (a + b + c) * (b + c - a) * (a + c - b) * (a + b - c);
}

// Function to sort the triangles by their area using Bubble Sort
void sort_by_area(triangle* tr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (calculate_square_area(tr[j]) > calculate_square_area(tr[j + 1])) {
                // Swap the triangles
                triangle temp = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
