%{
#include <stdio.h>
#include <stdlib.h>

void print_vowel_string(const char *text);

%}

%option noyywrap

%%
[AEIOUaeiou][a-zA-Z]* { print_vowel_string(yytext); }
.                     ;
\n                    ;

%%

int main(void) {
    yylex();
    return 0;
}

void print_vowel_string(const char *text) {
    printf("String starting with a vowel: %s\n", text);
}
