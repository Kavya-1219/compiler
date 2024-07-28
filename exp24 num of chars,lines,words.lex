%{
int nlines,nwords,nchars;
%}

%%
\n {nchars++;nlines++;
       }

[^\n\t]+ {nwords++, nchars=nchars+yyleng;}
. {nchars++;}

%%

int yywrap(void){}
int main()
{
yylex();
printf("lines=%d\nChars=%d\nWords=%d",nlines,nchars,nwords);
return 0;
}
