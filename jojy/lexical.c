/*
Nikhil Jojy
R7A_246
Lexical Analyzer
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	FILE *f1;
	f1=fopen("inputlex.txt","r");
	int i,nc=0,j=0;
	char ch,str[100];
	do
	{
		i=0;
		ch=fgetc(f1);
		if(ch=='+'||ch=='-'||ch=='/'||ch=='*'||ch=='^')
		{
			printf("\nToken [%c] is an operator.",ch);
			nc++;
		}
		else if(ch=='{'||ch=='}'||ch=='('||ch==')'||ch=='['||ch==']'||ch=='#'||ch=='<'||ch=='>'||ch=='.'||ch=='\\'||ch=='%'||ch=='='||ch=='"'||ch=='\''||ch==';')
		{
			if(ch=='\\'||ch=='%')
			{
				str[i]=ch;
				i++;
				ch=fgetc(f1);
				str[i]=ch;
				i++;
				str[i]='\0';
				printf("\nToken [%s] is a spcial character.",str);
				nc++;
			}
			else
			{
				printf("\nToken [%c] is a spcial character.",ch);
				nc++;\
			}
		}
		else if(isdigit(ch))
		{
			str[i]=ch;
			i++;
			ch=fgetc(f1);
			while(isalnum(ch)&&ch!=' ')
			{
				str[i]=ch;
				i++;
				ch=fgetc(f1);
			}
			str[i]='\0';
			fseek(f1,-1,SEEK_CUR);
			printf("\nToken [%s] is a number.",str);
			nc++;
		}
		else if(isalpha(ch))
		{
			str[i]=ch;
			i++;
			ch=fgetc(f1);
			while((isalnum(ch)||ch=='_')&&ch!=' ')
			{
				str[i]=ch;
				i++;
				ch=fgetc(f1);
			}
			str[i]='\0';
			fseek(f1,-1,SEEK_CUR);
			nc++;
			if(strcmp(str,"if")==0||strcmp(str,"else")==0||strcmp(str,"do")==0||strcmp(str,"while")==0||strcmp(str,"for")==0||strcmp(str,"include")==0||strcmp(str,"then")==0||strcmp(str,"break")==0||strcmp(str,"continue")==0||strcmp(str,"switch")==0||strcmp(str,"case")==0||strcmp(str,"int")==0||strcmp(str,"float")==0||strcmp(str,"char")==0||strcmp(str,"main")==0||strcmp(str,"return")==0||strcmp(str,"printf")==0||strcmp(str,"scanf")==0||strcmp(str,"stdio")==0||strcmp(str,"stdlib")==0||strcmp(str,"string")==0||strcmp(str,"ctype")==0)
			{
				if(strcmp(str,"stdio")==0||strcmp(str,"stdlib")==0||strcmp(str,"string")==0||strcmp(str,"ctype")==0)
				{
					//i--;
					ch=fgetc(f1);
					str[i]=ch;
					i++;
					ch=fgetc(f1);
					str[i]=ch;
					i++;
					str[i]='\0';
				}
				printf("\nToken [%s] is a keyword.",str);
			}
			else
				printf("\nToken [%s] is an identifier.",str);
		}
		else
			j++;
	}while(ch!=EOF);
	printf("\nTotal number of tokens is: %d\n",nc);
	fclose(f1);
}
