%{
#include <stdio.h>
%}

%option noyywrap

%%
abc             { printf("ABC"); }
.|\n            { printf("%c", yytext[0]); }

%%

int main(void) {
    yylex();
    return 0;
}
