%{
	#include<stdio.h>
	FILE *fp;
%}

digit		[0-9]+
keyword		[\t]*"int"|[\t]*"char"|[\t]*"float"|[\t]*"for"|[\t]*"while"|[\t]*"else"|[\t]*"if"|[\t]*"break"|[\t]*"case"	
operator	"+"|"-"|"*"|"/"
symbol		";"|","|"\""
logicoptr	"&&"|"||"
relationoptr	[\t]*"<="|">="|"++"|"!="|"<"|">"|"="
identifier	[a-z]+[a-z0-9]*
main		"main()"

%%

{digit}		{printf("\n	numbers		::%s",yytext);}
{keyword}	{printf("\n	keyword		::%s",yytext);}
{operator}	{printf("\n	operator	::%s",yytext);}
{symbol}	{printf("\n	symbol		::%s",yytext);}
{logicoptr}	{printf("\n	logicoptr	::%s",yytext);}
{relationoptr}	{printf("\n	relationoptr	::%s",yytext);}
{identifier}	{printf("\n	identifier	::%s",yytext);}
{main}		{printf("\n	main		::%s",yytext);}
.		{}

%%

int main(int argc,char *argv[])
{
	fp=fopen(argv[1],"r");
	if(fp!=NULL)
	{
		yyin=fp;
		yylex();
	}
	return(0);
}
