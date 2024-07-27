#include <stdio.h>
#include <string.h>

#define SIZE 100

void eliminateLeftRecursion(char production[SIZE]) {
    char non_terminal = production[0];
    char alpha[SIZE], beta[SIZE];
    int index = 3, i = 0, j = 0;

    if (non_terminal == production[index]) {

        for (i = index + 1; production[i] != '|' && production[i] != '\0'; i++) {
            alpha[j++] = production[i];
        }
        alpha[j] = '\0';

        j = 0;
        if (production[i] == '|') {
            i++;
            for (; production[i] != '\0'; i++) {
                beta[j++] = production[i];
            }
        }
        beta[j] = '\0';

        printf("Grammar without left recursion:\n");
        printf("%c->%s%c'\n", non_terminal, beta, non_terminal);
        printf("%c'->%s%c'|E\n", non_terminal, alpha, non_terminal);
    } else {
        printf(" is not left recursive.\n");
    }
}

int main() {
    int num;
    char production[SIZE][SIZE];

    printf("Enter Number of Productions: ");
    scanf("%d", &num);

    printf("Enter the grammar as E->E-A :\n");
    for (int i = 0; i < num; i++) {
        scanf("%s", production[i]);
    }

    for (int i = 0; i < num; i++) {
        printf("\nGRAMMAR: %s", production[i]);
        eliminateLeftRecursion(production[i]);
    }

    return 0;
}
