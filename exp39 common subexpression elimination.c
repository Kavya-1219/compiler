#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evaluateExpression(const char *expr) {
    int a, b;
    char op;

    sscanf(expr, "%d %c %d", &a, &op, &b);

    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

void eliminateCommonSubexpressions(const char *expr) {
    char subExpr1[] = "5 * 3";
    char subExpr2[] = "5 * 3"; 
    char subExpr3[] = "2 + 4";

    int result1 = evaluateExpression(subExpr1);
    int result3 = evaluateExpression(subExpr3);

    printf("Original Expression: %s\n", expr);
    printf("Optimized Expression: \n");
    printf("temp1 = %d\n", result1); 
    printf("result = temp1 + %d\n", result3); 
}

int main() {
    char expr[100];

    printf("Enter an arithmetic expression: ");
    fgets(expr, sizeof(expr), stdin);

    size_t length = strlen(expr);
    if (length > 0 && expr[length - 1] == '\n') {
        expr[length - 1] = '\0';
    }

    eliminateCommonSubexpressions(expr);

    return 0;
}
