%{
#include <stdio.h>
#include <stdlib.h>

void print_word(const char *text);
void print_operator(const char *text);

%}

%option noyywrap

%%
[a-zA-Z]+       { print_word(yytext); }
"=="            { print_operator(yytext); }
"!="            { print_operator(yytext); }
"<="            { print_operator(yytext); }
">="            { print_operator(yytext); }
"<"             { print_operator(yytext); }
">"             { print_operator(yytext); }
[ \t\n]+        ;
.               ;

%%

int main(void) {
    yylex();
    return 0;
}

void print_word(const char *text) {
    printf("Word: %s\n", text);
}

void print_operator(const char *text) {
    printf("Relational Operator: %s\n", text);
}
