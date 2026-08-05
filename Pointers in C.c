void update(int *a, int *b) {
    int sum = *a + *b;
    int diff = (*a > *b) ? (*a - *b) : (*b - *a);
    
    *a = sum;
    *b = diff;
}
