/*
Nikhil Jojy
R7A_246
Recursive Descent Parser
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char input[50];
int i,error;
void E();
void T();
void Eprime();
void Tprime();
void F();
void main()
{
	i=0;
	error=0;
	printf("Enter an arithmetic expression: ");
	scanf("%s",input);
	E();
	if(strlen(input)==i && error==0)
		printf("\nAccepted..!!\n");
	else
		printf("\nRejected..!!\n");
}
void Eprime()
{
	if(input[i]=='+')
	{
		i++;
		T();
		Eprime();
	}
}
void E()
{
	T();
	Eprime();
}
void T()
{
	F();
	Tprime();
}
void Tprime()
{
	if(input[i]=='*')
	{
		i++;
		F();
		Tprime();
	}
}
void F()
{
	if(isalnum(input[i]=='('))
	{	
		i++;
		E();
		if(input[i]==')')
			i++;
		else
			error=1;
	}
	else if(input[i]=='i' && input[i+1]=='d')
	i+=2;
	else
		error=1;
}
		
