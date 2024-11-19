%{
#include <stdio.h>
int lines = 0, spaces = 0, words = 0, characters = 0;
%}

%%
[a-zA-Z0-9]+ { characters += yyleng; words++; }  
[ \t]        { spaces++; characters++; }            
\n           { lines++; characters++; }             
.            { characters++; }                                   
%%

int main() {
    if (!(yyin = fopen("input.txt", "r"))) { 
       perror("Error opening file"); 
       return 1; 
    }
    yylex(); 
    fclose(yyin); 
    printf("Characters: %d\nWords: %d\nLines: %d\nSpaces: %d\n", characters, words, lines, spaces);
    return 0;
}

int yywrap() { 
    return 1; 
}

