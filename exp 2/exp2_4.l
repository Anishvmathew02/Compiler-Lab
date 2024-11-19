%{
#include <stdio.h>
int v = 0, cons = 0;
%}

%%
[aeiouAEIOU]		{ v++; }
[a-zA-Z]		{ cons++; }
\n			{ printf("%d vowels and %d consonants\n", v, cons); return 0; }
%% 

int main() {
    printf("Enter the input text:\n");
    yylex();
    return 0;
}

int yywrap() { 
   return 1; 
}
