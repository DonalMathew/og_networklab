%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex();
	void yyerror(const char *s);
%}

%token NUMBER EOL

%left '+' '-'
%left '*' '/'
%right UMINUS

%%


line:
	| line expr EOL 		{printf("Result: %d\n",$2);}
	;

expr:
	NUMBER 		{$$ = $1;}
	| expr '+' expr	{$$ = $1+$3;}
	| expr '-' expr	{$$ = $1-$3;}
	| expr '*' expr {$$ = $1*$3;}
	| expr '/' expr	{
				if($3 == 0){
					yyerror("Division by 0!");
					exit(1);
					}
				$$ = $1 / $3;	
			}
	| '-' expr %prec UMINUS {$$=-$2;}
	| '(' expr ')'		{$$=$2;}		
	;
	
%%	

void yyerror(const char *s)
{
	fprintf(stderr, "Error: %s\n",s);
}

int main(void)
{
	printf("Enter the expression:\n");
	fflush(stdout);
	yyparse();
	return 0;
}
	


