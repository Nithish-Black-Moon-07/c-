#include <stdio.h>

int main() {
    // 1. Declare 4 variables: two of type int and two of type float.
    int int1, int2;
    float float1, float2;
    
    // 2. Read 2 lines of input from stdin and initialize your variables.
    scanf("%d %d", &int1, &int2);
    scanf("%f %f", &float1, &float2);
    
    // 3. Print the sum and difference of the two int variables.
    printf("%d %d\n", int1 + int2, int1 - int2);
    
    // 4. Print the sum and difference of the two float variables rounded to one decimal place.
    printf("%.1f %.1f\n", float1 + float2, float1 - float2);
    
    return 0;
}
