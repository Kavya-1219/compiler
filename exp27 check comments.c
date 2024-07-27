#include <stdio.h>
#include <string.h>

int main() {
    
    printf("Enter a line of text: ");
    fgets(charline, sizeof(line), stdin);
    if (strstr(line, "//") != NULL) {
        printf("Single-line comment found.\n");
    }
    
    else if (strstr(line, "/*") != NULL) {
        printf("Start of multi-line comment found.\n");
    }
    
    else if (strstr(line, "*/") != NULL) {
        printf("End of multi-line comment found.\n");
    } else {
        printf("No comment found.\n");
    }
    
    return 0;
}
