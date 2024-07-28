%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);

%}

%option noyywrap

%%

[0-9]+(\.[0-9]+)?   { printf("NUMBER(%s)\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("IDENTIFIER(%s)\n", yytext); }
"="                 { printf("ASSIGN\n"); }
"+"                 { printf("PLUS\n"); }
"-"                 { printf("MINUS\n"); }
"*"                 { printf("MULTIPLY\n"); }
"/"                 { printf("DIVIDE\n"); }
"("                 { printf("LPAREN\n"); }
")"                 { printf("RPAREN\n"); }
\n                  { printf("NEWLINE\n"); }
[ \t]+              { /* Ignore whitespace */ }
.                   { printf(" CHARACTER: %s\n", yytext); }

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Enter an expression: ");
    yylex();
    return 0;
}
