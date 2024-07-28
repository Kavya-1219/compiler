%{
#include <stdio.h>
#include <string.h>

int word_count = 0;
char word_to_count[100];

void yyerror(const char *s);
int yylex(void);

%}

%option noyywrap

%%

[a-zA-Z0-9]+    { 
                    if (strcmp(yytext, word_to_count) == 0) {
                        word_count++;
                    } 
                }
.|\n            { /* Ignore other characters */ }

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Enter the word to count: ");
    scanf("%s", word_to_count);
    
   
    while ((getchar()) != '\n');
    
    printf("Enter the sentence: ");
    yylex();
    
    printf("The word '%s' occurred %d times.\n", word_to_count, word_count);
    return 0;
}
