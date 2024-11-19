%{
#include <stdio.h>
#include <string.h>
char str[100] = ""; 
%}

%%
abc    { strcat(str, "ABC"); }
[^\n]  { strcat(str, yytext); } 
\n     { printf("%s\n", str); return 0; }
%%

int main() {
    printf("Enter the input text:\n"); 
    yylex(); 
    return 0; 
}

int yywrap() { 
   return 1; 
}
