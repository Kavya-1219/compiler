%{
#include <stdio.h>
%}

OPERATOR  "+"|"-"|"*"|"/"

%%

{OPERATOR}  {
                printf("Valid operator: %s\n", yytext);
            }

.           {
                printf("Invalid character: %s\n", yytext);
            }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
