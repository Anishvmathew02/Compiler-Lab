%{
#include <stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
%}

%token NUMBER ID NL
%left '-' '+'
%left '*' '/'

%%
E: T NL { printf("Result = %d\n", $$); exit(0); }
    ;
T: T '+' T { $$ = $1 + $3; }
  | T '-' T { $$ = $1 - $3; }
  | T '*' T { $$ = $1 * $3; }
  | T '/' T { $$ = $1 / $3; }
  | '-' NUMBER { $$ = -$2; }
  | NUMBER { $$ = $1; }
  | ID { $$ = $1; };
%% 

int main() {
    printf("Enter the expression\n");
    yyparse();
}

int yyerror() {
    printf("\nExpression is invalid\n");
}





