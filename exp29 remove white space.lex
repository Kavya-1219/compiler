%{
#include <stdio.h>
int whitespace_count = 0;
int newline_count = 0;
%}

WS      [ \t]
NEWLINE \n

%%

{WS}    { whitespace_count++; }
{NEWLINE} { newline_count++; }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    printf("Number of whitespace characters: %d\n", whitespace_count);
    printf("Number of newline characters: %d\n", newline_count);
    return 0;
}
