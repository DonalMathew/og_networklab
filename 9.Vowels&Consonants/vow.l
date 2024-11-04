%{
	#include<stdio.h>
	int cons=0;
	int vowel=0;
%}

%%
[aeiouAEIOU]	{vowel++;}
\n
.		{cons++;}

%%
int main()
{
	printf("Enter the input string: ");
	yylex();
	printf("No.of vowels :%d\n",vowel);
	printf("No.of consonants :%d\n",cons);
	return 0;
}

int yywrap()
{
	return 1;
}
