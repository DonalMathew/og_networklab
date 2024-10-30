%{
	#include<stdio.h>
	#include "y.tab.h"
%}

%%
[0-9]+		{yylval = atoi(yytext); return NUMBER;}
[-+*/()]	{return yytext[0];}
\n		{return EOL;}
[ \t]		;
.		{printf("Unexpected Character!\n");}
<<EOF>>		{return EOF;}
%%

int yywrap(void)
{	
	return 1;
}

