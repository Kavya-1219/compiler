%{
%}

%%

[0-9][0-9]\/[0-1][0-9]\/[1-2][0-9]{3} {printf("DOB is valid");}

.+ {printf("DOB is not valid");}

%%
int yywrap() {}

int main()
{
	yylex();
}
