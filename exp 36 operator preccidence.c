#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


double performOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void applyOperation(double *values, int *valIndex, char *ops, int *opIndex) {
    double b = values[--(*valIndex)];
    double a = values[--(*valIndex)];
    char op = ops[--(*opIndex)];
    values[(*valIndex)++] = performOperation(a, b, op);
}

double evaluateExpression(const char *expr) {
    double values[100];
    char ops[100];
    int valIndex = 0, opIndex = 0;
    int i = 0;

    while (expr[i] != '\0') {
        if (isspace(expr[i])) {
            i++;
            continue;
        }

        if (isdigit(expr[i])) {
            double value = 0;
            while (isdigit(expr[i])) {
                value = (value * 10) + (expr[i++] - '0');
            }
            if (expr[i] == '.') {
                i++;
                double fraction = 1;
                while (isdigit(expr[i])) {
                    fraction /= 10;
                    value += (expr[i++] - '0') * fraction;
                }
            }
            values[valIndex++] = value;
        } else if (expr[i] == '(') {
            ops[opIndex++] = expr[i++];
        } else if (expr[i] == ')') {
            while (opIndex > 0 && ops[opIndex - 1] != '(') {
                applyOperation(values, &valIndex, ops, &opIndex);
            }
            opIndex--; 
            i++;
        } else {
            while (opIndex > 0 && precedence(ops[opIndex - 1]) >= precedence(expr[i])) {
                applyOperation(values, &valIndex, ops, &opIndex);
            }
            ops[opIndex++] = expr[i++];
        }
    }

    while (opIndex > 0) {
        applyOperation(values, &valIndex, ops, &opIndex);
    }

    return values[0];
}

int main() {
    char expr[100];

    printf("Enter an arithmetic expression: ");
    fgets(expr, sizeof(expr), stdin);

    size_t length = strlen(expr);
    if (length > 0 && expr[length - 1] == '\n') {
        expr[length - 1] = '\0';
    }

    double result = evaluateExpression(expr);
    printf("The result of the expression is: %.2f\n", result);

    return 0;
}
