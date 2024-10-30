%{
	#include<stdio.h>
	#include<string.h>
%}

%%
abc 	{printf("ABC");}
\n	
.	{putchar(yytext[0]);}

%%
int main()
{
	printf("Enter the input string: ");
	yylex();
	return 0;
}

int yywrap()
{
	return 1;
}

