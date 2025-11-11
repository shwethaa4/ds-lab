#include <stdio.h>
#include <string.h>

#define MAX 100
int isPalindrome(char* str) {
    char stack[MAX];
    int top = -1; 

   
    for (int i = 0; str[i]; i++) {
        stack[++top] = str[i]; 
    }

    
    for (int i = 0; str[i]; i++) {
        if (str[i] != stack[top--]) {
            return 0;
        }
    }
    return 1; 
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s",str);
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}