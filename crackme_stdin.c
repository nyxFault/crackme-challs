// gcc -o crackme_stdin crackme_stdin.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validate_password(const char *password) {
    int len = strlen(password);
    
    // Check total length (3 letters + 1 special + 3 digits = 7)
    if (len != 7) {
        return 0;
    }
    
    // Check first 3 characters are letters (A-Z or a-z)
    for (int i = 0; i < 3; i++) {
        if (!isalpha(password[i])) {
            return 0;
        }
    }
    
    // Check 4th character is a special character
    // We'll define special characters as anything that's not alphanumeric
    if (isalnum(password[3])) {
        return 0;
    }
    
    // Check last 3 characters are digits (0-9)
    for (int i = 4; i < 7; i++) {
        if (!isdigit(password[i])) {
            return 0;
        }
    }
    
    // Specific check for "NYX@123"
    if (strcmp(password, "NYX@123") == 0) {
        return 1;
    }
    
    return 0;
}

int main() {
    char password[100];
    
    printf("Enter password: ");
    
    // Read from stdin
    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    
    // Remove newline character if present
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }
    
    // Validate password
    if (validate_password(password)) {
        printf("Access granted! You entered the correct password.\n");
        printf("Flag: FLAG{stdin_magic_%s}\n", password);
    } else {
        printf("Access denied! Incorrect password.\n");
    }
    
    return 0;
}
