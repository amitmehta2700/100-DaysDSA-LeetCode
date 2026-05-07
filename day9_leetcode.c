#include <stdio.h>
#include <string.h>

void reverseString(char s[], int length) {
    int start = 0;
    int end = length - 1;
    
    while(start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        
        start++;
        end--;
    }
}

int main() {
    char s[100000];   // Max constraint
    
    scanf("%s", s);   // Input string
    int length = strlen(s);
    
    reverseString(s, length);
    
    printf("%s", s);
    
    return 0;
}
