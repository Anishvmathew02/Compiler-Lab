%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
[0-9]+           { return DIGIT; }
[a-zA-Z][a-zA-Z0-9_]* { return ID; }
\n               { return NL; }
[ \t]            { /* Ignore whitespace */ }
[+\-*\/()]         { return yytext[0]; } 
.                { printf("Unrecognized character: %s\n", yytext); }
%%
