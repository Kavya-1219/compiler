#include <stdio.h>
#include <string.h>

#define MAX_EXPR_LEN 100

int main() {
    char expressions[][MAX_EXPR_LEN] = {
        "x + y",
        "y * z",
        "x + y", 
        "x / z",
    };
    int num_expr = sizeof(expressions) / sizeof(expressions[0]);

    printf("Original Code:\n");
    for (int i = 0; i < num_expr; ++i) {
        printf("%s\n", expressions[i]);
    }

    
    for (int i = 0; i < num_expr; ++i) {
        for (int j = i + 1; j < num_expr; ++j) {
            if (strcmp(expressions[i], expressions[j]) == 0) {
                strcpy(expressions[j], "; Removed"); 
            }
        }
    }

    printf("\nOptimized Code:\n");
    for (int i = 0; i < num_expr; ++i) {
        if (strcmp(expressions[i], "; Removed") != 0) {
            printf("%s\n", expressions[i]);
        }
    }

    return 0;
}
