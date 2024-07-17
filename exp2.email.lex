%{
%}

%%

[a-z.0-9_]+@[a-z]+".com"|".in" {printf("\nit is Valid\n");}

.+ {printf("\nit is not valid\n");}

%%
int yywrap() {}

int main()
{
	printf("\nEnter Email : ");
	yylex();
}
