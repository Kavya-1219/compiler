#include <stdio.h>

int main() {
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0;

    printf("Enter text (EOF to stop):\n");

    while ((ch = getchar()) != EOF) {
        charCount++;

        if (ch == '\n') {
            lineCount++;
        }

        if (ch == ' ' || ch == '\t' || ch == '\n') {
            inWord = 0;
        } else if (!inWord) {
            wordCount++;
            inWord = 1;
        }
    }

    printf("Characters: %d\n", charCount);
    printf("Words: %d\n", wordCount);
    printf("Lines: %d\n", lineCount);
    return 0;
}
