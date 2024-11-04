%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%token DIGIT LETTER UND NL

%%

stmnt:variable NL{printf("valid idenifier\n");}
;

variable: LETTER alphanumeric|LETTER

;
alphanumeric:LETTER alphanumeric
	|DIGIT alphanumeric
	|UND alphanumeric
	|LETTER
	|DIGIT
	|UND
	
;
%%

void yyerror()
{
	printf("Invalid identifier!\n");
}

int main()
{
	printf("Enter the variable name:");
	yyparse();
	return 0;
}
