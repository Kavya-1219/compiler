%{
int yylineno;
%}
%%
^(.*)\n printf("%4d\t%s", ++yylineno, yytext);
%%
int yywrap(void) {
return 1;
}
int main(){
extern FILE *yyin, *yyout; 
yyin=fopen("input21.txt", "r"); 

yylex();
fclose(yyin);
}
