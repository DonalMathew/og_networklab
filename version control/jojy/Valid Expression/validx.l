%{
	#include <stdio.h>
	#include "y.tab.h"
%}

%%

[0-9]+		{return NUMBER;}
[-+*/()]	{return yytext[0];}
[^\t\n]		;
.		{printf("Unexpected character:%s\n",yytext);}

%%

int yywrap()
{
	return 1;
}


