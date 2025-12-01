// gcc -o crackme_argv crackme_argv.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        printf("Wrong! Please provide exactly one argument.\n");
        return 1;
    }
    
    char *input = argv[1];
    int len = strlen(input);
    
    if (len != 8) {
        printf("Error! Password must be 8 characters.\n");
        return 1;
    }
    
    // Simple check: first 4 chars must be uppercase, last 4 must be digits
    int valid = 1;
    for (int i = 0; i < 4; i++) {
        if (!isupper(input[i])) {
            valid = 0;
            break;
        }
    }
    
    if (valid) {
        for (int i = 4; i < 8; i++) {
            if (!isdigit(input[i])) {
                valid = 0;
                break;
            }
        }
    }
    
    // Secret password is "NYXF1234"
    if (valid && strcmp(input, "NYXF1234") == 0) {
        printf("Congratulations! Cracked! Flag is: FLAG{argv_rocks_%s}\n", input);
    } else {
        printf("Try Again! Invalid password.\n");
    }
    
    return 0;
}
