%{
#include "y.tab.h"
extern int yylval;
%}

%%
[0-9]+    { yylval = atoi(yytext); return NUMBER; }
[a-zA-Z]+ { return ID; }
[\n]        { return NL; }
[ \t]+    { }
.         { return yytext[0]; }
%%
