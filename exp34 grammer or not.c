#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {
    NUM,
    PLUS,
    MUL,
    LPAREN,
    RPAREN,
    EOF_TOKEN
};
int check_grammar(char*);
int main() {
    char input[100];
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; 
    if (check_grammar(input)) {
        printf("Input string satisfies the grammar\n");
    } else {
        printf("Input string does not satisfy the grammar\n");
    }
    return 0;
}

int check_grammar(char* input) {

    int len = strlen(input);
    int i;
    for (i = 0; i < len; i++) {
        if (input[i] >= '0' && input[i] <= '9') {

        } else if (input[i] == '+') {

        } else if (input[i] == '*') {

        } else if (input[i] == '(') {

        } else if (input[i] == ')') {

        } else {
            return 0; 
        }
    }

    int paren_count = 0;
    for (i = 0; i < len; i++) {
        if (input[i] == '(') paren_count++;
        else if (input[i] == ')') paren_count--;
        if (paren_count < 0) return 0; 
    }
    if (paren_count != 0) return 0; 
    return 1; 
}
