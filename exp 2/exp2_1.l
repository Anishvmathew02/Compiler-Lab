%{
#include <stdio.h>
int k=0, i=0, o=0, num=0;
%}

%%
if|else|while|int|switch|for|char      { printf("%s is a keyword\n", yytext); k++; }
[_a-zA-Z][_a-zA-Z0-9]*                 { printf("%s is an identifier\n", yytext); i++; }
[=+\-*/<>]                             { printf("%s is an operator\n", yytext); o++; }
[0-9]+                                 { printf("%s is a number\n", yytext); num++; }
[ \t\n]+                               { /* ignore whitespace */ }
.                                      { /* ignore other characters */ }

%%

int main() {
    if (!(yyin = fopen("exp2_1Text.txt", "r"))) { 
       perror("Error opening file"); 
       return 1; 
    }
    yylex(); 
    fclose(yyin); 
    return 0;
}

int yywrap() { return 1; }
