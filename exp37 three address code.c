#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char tempVar = 't';
int tempCount = 0;

typedef struct {
    char result[10];
    char arg1[10];
    char op;
    char arg2[10];
} TAC;

TAC tacArray[MAX];
int tacIndex = 0;

void generateTAC(char* result, char* arg1, char op, char* arg2) {
    strcpy(tacArray[tacIndex].result, result);
    strcpy(tacArray[tacIndex].arg1, arg1);
    tacArray[tacIndex].op = op;
    strcpy(tacArray[tacIndex].arg2, arg2);
    tacIndex++;
}

void printTAC() {
    printf("Three Address Code:\n");
    for (int i = 0; i < tacIndex; i++) {
        printf("%s = %s %c %s\n", tacArray[i].result, tacArray[i].arg1, tacArray[i].op, tacArray[i].arg2);
    }
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

void infixToTAC(char* expr) {
    char opStack[MAX];
    char valStack[MAX][10];
    int opTop = -1, valTop = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (isspace(expr[i])) {
            continue;
        } else if (isdigit(expr[i]) || isalpha(expr[i])) {
            char val[10];
            int j = 0;
            while (isdigit(expr[i]) || isalpha(expr[i])) {
                val[j++] = expr[i++];
            }
            val[j] = '\0';
            strcpy(valStack[++valTop], val);
            i--;
        } else if (expr[i] == '(') {
            opStack[++opTop] = expr[i];
        } else if (expr[i] == ')') {
            while (opTop != -1 && opStack[opTop] != '(') {
                char op = opStack[opTop--];
                char arg2[10];
                char arg1[10];
                strcpy(arg2, valStack[valTop--]);
                strcpy(arg1, valStack[valTop--]);

                char result[10];
                sprintf(result, "%c%d", tempVar, tempCount++);
                generateTAC(result, arg1, op, arg2);
                strcpy(valStack[++valTop], result);
            }
            opTop--;
        } else {
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(expr[i])) {
                char op = opStack[opTop--];
                char arg2[10];
                char arg1[10];
                strcpy(arg2, valStack[valTop--]);
                strcpy(arg1, valStack[valTop--]);

                char result[10];
                sprintf(result, "%c%d", tempVar, tempCount++);
                generateTAC(result, arg1, op, arg2);
                strcpy(valStack[++valTop], result);
            }
            opStack[++opTop] = expr[i];
        }
    }

    while (opTop != -1) {
        char op = opStack[opTop--];
        char arg2[10];
        char arg1[10];
        strcpy(arg2, valStack[valTop--]);
        strcpy(arg1, valStack[valTop--]);

        char result[10];
        sprintf(result, "%c%d", tempVar, tempCount++);
        generateTAC(result, arg1, op, arg2);
        strcpy(valStack[++valTop], result);
    }
}

int main() {
    char expr[MAX];
    printf("Enter an expression: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = 0;

    infixToTAC(expr);
    printTAC();

    return 0;
}
