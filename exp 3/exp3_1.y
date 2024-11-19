%{
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double

int yylex();
void yyerror();
%}

%token DIGIT ID NL
%left '-' '+'
%left '*' '/'

%%
stmt: exp NL { printf("Valid expression.\n"); exit(0); }
    ;

exp: exp '+' exp | exp '-' exp
   | exp '*' exp | exp '/' exp
   | '(' exp ')' | ID | DIGIT
   ;

%%
void yyerror() {
    printf("Invalid expression.\n");
}

int main() {
    printf("Enter the expression:\n");
    yyparse();
    return 0;
}
