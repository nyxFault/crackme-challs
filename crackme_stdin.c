// gcc -o crackme_stdin crackme_stdin.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100

int main() {
    char input[BUFFER_SIZE];
    
    printf("Enter password: ");
    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
        printf("Failed to read input.\n");
        return 1;
    }
    
    // Remove newline if present
    input[strcspn(input, "\n")] = 0;
    int len = strlen(input);
    
    if (len != 12) {
        printf("Incorrect! Password must be 12 characters.\n");
        return 1;
    }
    
    // Check pattern: letters, then digits, then symbols
    int valid = 1;
    
    // First 6 should be lowercase letters
    for (int i = 0; i < 6; i++) {
        if (!islower(input[i])) {
            valid = 0;
            break;
        }
    }
    
    if (valid) {
        // Next 4 should be digits
        for (int i = 6; i < 10; i++) {
            if (!isdigit(input[i])) {
                valid = 0;
                break;
            }
        }
    }
    
    if (valid) {
        // Last 2 should be symbols
        for (int i = 10; i < 12; i++) {
            if (!ispunct(input[i])) {
                valid = 0;
                break;
            }
        }
    }
    
    // Secret password is "angrbin1234!!"
    if (valid && strcmp(input, "angrbin1234!!") == 0) {
        printf("Success! Welcome!\n");
        printf("Flag: FLAG{stdin_magic_%s}\n", input);
    } else {
        printf("Access Denied! Wrong password.\n");
    }
    
    return 0;
}