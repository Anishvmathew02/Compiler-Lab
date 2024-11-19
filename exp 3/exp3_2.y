%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
%}

%token digit letter

%%
start : letter s
s:      letter s | digit s |
;
%%

int yyerror(){
   printf("\nInvalid identifier\n");
   exit(0);
}

int main(){
   printf("\nEnter the token : ");
   yyparse();

   printf("\nValid Identifier\n");

}
