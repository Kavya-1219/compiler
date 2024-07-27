%{
%}

%%

[a-zA-Z][a-zA-Z0-9]+ {printf("\n%s is IDENTIFIER",yytext);}

.+ {printf("\n%s is NOT A IDENTIFIER",yytext);}

%%
int yywrap() {}

int main()
{
	while(yylex());
}
