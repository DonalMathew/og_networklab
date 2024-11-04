%{
	#include<stdio.h>
	int lines = 0, words = 0, characters = 0, in_word=0;
%}

%%
[\n]		{lines++;characters++;in_word=0;}
[\t]		{characters += yyleng;in_word=0;}
[ ]		{characters++; in_word=0;}
[^\t\n]		{characters += yyleng;if(!in_word){words++;in_word=1;}}
.		{characters++;}

%%

int main(int argc,char *argv[])
{
	FILE *file = fopen(argv[1],"r");
	if(!file)
	{
		printf("File not Found!");
		return 1;
	}
	
	yyin = file;
	yylex();
	
	printf("\nLines: %d\n",lines);
	printf("\nWords: %d\n",words);
	printf("\nCharacters: %d\n",characters);
	
	fclose(file);
	return 0;
}

int yywrap()
{
	return 1;
}

/*
I/P:  Hello world
      this is an example
o/p:  Lines: 2
      Words: 6
      Characters: 30
