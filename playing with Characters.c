#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch;
    char s[100];
    char sen[100];
    
    // 1. Read the character
    scanf("%c", &ch);
    
    // 2. Read the single-word string
    scanf("%s", s);
    
    // 3. Clear the newline character from the buffer
    scanf("\n");
    
    // 4. Read the entire sentence until a newline is hit
    scanf("%[^\n]%*c", sen);
    
    // 5. Print the outputs
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);
    
    return 0;
}
