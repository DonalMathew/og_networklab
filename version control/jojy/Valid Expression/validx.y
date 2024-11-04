%{
	#include<stdio.h>
	#include<stdlib.h>
	
	void yyerror(const char* s);
	int yylex(void);
%}

%token NUMBER

%%

expr:
	term 
	|expr '+' term 
	|expr '-' term 
	;
term:
	factor 
	|term '*' factor 
	|term '/' factor 
	;
	
factor:
	NUMBER
	|'(' expr ')'
	;
	
%%

void yyerror(const char *s)
{
	fprintf(stderr,"%s\n",s);
}

int main(void)
{
	printf("Enter the expression:");
	if(yyparse()==0)
		printf("Valid Expression.\n");
	else
		printf("Invalid Expression.\n");
	return 0;
}
