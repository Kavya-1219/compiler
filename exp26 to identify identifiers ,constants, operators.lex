%{
#include <stdio.h>
#include <string.h>

void print_token(const char *token_type, const char *lexeme);
%}

identifier [a-zA-Z_][a-zA-Z0-9_]{0,31}
constant [0-9]+
operator [+\-*/=<>!]+

%%

"/*"([^*]|\*+[^*/])*\*+\/     { /* Ignore multi-line comments */ }
"//".*                        { /* Ignore single-line comments */ }
[ \t\n]+                      { /* Ignore whitespace */ }
{identifier}                  { print_token("Identifier", yytext); }
{constant}                    { print_token("Constant", yytext); }
{operator}                    { print_token("Operator", yytext); }
.                             { print_token("Unknown", yytext); }

%%

void print_token(const char *token_type, const char *lexeme) {
    printf("%s: %s\n", token_type, lexeme);
}

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }

    yylex();

    if (yyin != stdin) {
        fclose(yyin);
    }

    return 0;
}
