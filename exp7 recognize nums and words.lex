%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void add_number(const char *text);
void add_word(const char *text);

%}

%option noyywrap

%%
[0-9]+          { add_number(yytext); }
[a-zA-Z]+       { add_word(yytext); }
[ \t\n]+        ;
.               ;

%%

int main(void) {
    yylex();
    return 0;
}

void add_number(const char *text) {
    printf("Number: %s\n", text);
}

void add_word(const char *text) {
    printf("Word: %s\n", text);
}
