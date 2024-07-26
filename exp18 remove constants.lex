%{
#include <stdio.h>

int cons = 0;
%}

digit [0-9]+(\.[0-9]+)?

%%

{digit} { cons++; printf("%s is a constant\n", yytext); }
.|\n { /* Ignore other characters */ }

%%

int yywrap(void) {
    return 1;
}

int main(void)
{
    extern FILE *yyin, *yyout; 
    yyin = fopen("input18.txt", "r");
    if (!yyin) {
        perror("constant.txt");
        return 1;
    }
    yylex();
    printf("Number of Constants: %d\n", cons);
    fclose(yyin);  
    return 0;
}
