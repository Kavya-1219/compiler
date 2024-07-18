%{
#include<stdio.h>
%}

%%

if|else|while|int|switch|for|char {printf("its a keywword");}
[a-zA-Z0-9]+ {printf("\n%s is IDENTIFIER",yytext);}

%%
int yywrap() {}

int main()
{
	while(yylex());
}
