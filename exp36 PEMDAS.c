#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

char opStack[MAX];
int opTop = -1;
double valStack[MAX];
int valTop = -1;

void pushOp(char op) {
    opStack[++opTop] = op;
}

char popOp() {
    if (opTop == -1) return '\0';
    return opStack[opTop--];
}

char peekOp() {
    if (opTop == -1) return '\0';
    return opStack[opTop];
}

void pushVal(double val) {
    valStack[++valTop] = val;
}

double popVal() {
    if (valTop == -1) return 0;
    return valStack[valTop--];
}

int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        case '(': return 0;
    }
    return -1;
}

double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}

void processOp(char op) {
    double b = popVal();
    double a = popVal();
    double result = applyOp(a, b, op);
    printf("Step: Apply %c to %.2f and %.2f\n", op, a, b);
    printf("%.2f %c %.2f = %.2f\n", a, op, b, result);
    pushVal(result);
}

void evaluateExpression(char* expr) {
    int i;
    for (i = 0; expr[i] != '\0'; i++) {
        if (isspace(expr[i])) continue;
        if (isdigit(expr[i]) || expr[i] == '.') {
            double num = 0;
            int decimal_places = 0;
            while (isdigit(expr[i]) || expr[i] == '.') {
                if (expr[i] == '.') {
                    decimal_places = 1;
                } else {
                    if (decimal_places) {
                        num = num + (expr[i] - '0') * pow(10, -decimal_places);
                        decimal_places++;
                    } else {
                        num = num * 10 + (expr[i] - '0');
                    }
                }
                i++;
            }
            i--;
            pushVal(num);
        } else if (expr[i] == '(') {
            pushOp(expr[i]);
        } else if (expr[i] == ')') {
            while (peekOp() != '(') {
                processOp(popOp());
            }
            popOp();
        } else {
            while (opTop != -1 && precedence(peekOp()) >= precedence(expr[i])) {
                processOp(popOp());
            }
            pushOp(expr[i]);
        }
    }

    while (opTop != -1) {
        processOp(popOp());
    }
}

int main() {
    printf("PEMDAS: Parentheses, Exponentiation, Multiplication, Division, Addition, Subtraction\n");
    
    char expr[MAX];
    printf("Enter an expression: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = 0;

    evaluateExpression(expr);
    printf("Final Result: %.2f\n", popVal());

    return 0;
}
