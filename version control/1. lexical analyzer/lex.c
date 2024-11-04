/*----------------------------------------------
Name: Donal Mathew P T
Roll no: 220
*/

#include<stdio.h> 
#include<ctype.h> 
#include<string.h> 

int main() 
{ 
	FILE *input;
	int l=1;
	int t=0;
	int j=0;
	int i,flag,k;
	char ch,ch1,str[20],dig[20]; 
	
	input = fopen("input.txt","r"); 
	char keyword[30][30] = {"int","void","if","else","do","while"}; 
	printf("Line no. \t Token no.\t\t Token \t\t Lexeme\n"); 

	while(!feof(input))
	{ 
		i=0,k=0;
		flag=0;
		ch=fgetc(input); 
		
		if(ch=='/')
		{
			ch=fgetc(input);
			if(ch=='/')
			{
				while((ch=fgetc(input))!='\n');
				if(ch=='\n')
				l++;
			}
			else if(ch=='*')
			{
				ch=fgetc(input);
				ch1=fgetc(input);
				while(ch!='*'&&ch1!='/')
				{
					ch=ch1;
					ch1=fgetc(input);
					if(ch=='\n')
					l++;
				}
			}
			else
			{
				ungetc(ch,input);
			}
			ch=fgetc(input); 
		} 
		if( ch=='+' || ch== '-' || ch=='*' || ch=='/' ||ch=='>'||ch=='<'||ch=='='||ch=='%'||ch=='&'||ch=='|') 
		{
 			printf("%7d\t\t %7d\t\t Operator\t %7c\n",l,t,ch); 
			t++;
 		}
 		else if( ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='?' ||ch=='@' || ch=='!' ||ch=='#'||ch==','||ch=='.'||ch=='"') 
		{ 
			printf("%7d\t\t %7d\t\t Special symbol\t %7c\n",l,t,ch);
			t++; 
		}
		else if(isdigit(ch)) 
		{
			dig[k]=ch;
			k++; 
			ch=fgetc(input);
 			while(isdigit(ch)) 
			{ 
				dig[k]=ch;
 				k++;
 				ch=fgetc(input);
 			} 
			ungetc(ch,input);
			dig[k]='\0';
			printf("%7d\t\t %7d\t\t Number\t\t %7s\n",l,t,dig); 
			t++; 
		}
		else if(isalpha(ch)) 
		{
			str[i]=ch;
			i++; 
			ch=fgetc(input);
			while(isalnum(ch) && ch!=' ') 
			{
				str[i]=ch; i++; 
				ch=fgetc(input);
			}
			ungetc(ch,input);
			str[i]='\0';
			for(j=0;j<=30;j++) 
			{
				if(strcmp(str,keyword[j])==0) 
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				printf("%7d\t\t %7d\t\t Keyword\t %7s\n",l,t,str); 
				t++; 
			}
			else
			{
				printf("%7d\t\t %7d\t\t Identifier\t %7s\n",l,t,str); 
				t++; 
			}
		}
		else if(ch=='\n') 
		{
			l++;
		}
	}
	printf("total no of tokens:%7d",t-1);
	fclose(input);
	return 0; 
}

/*------------------------------------------------------
INPUT:
#include<stdio.h>
void main()
{
	printf("Hello World");
}

OUTPUT:
Line no. 	 Token no.		 Token 		 Lexeme
      1		       0		 Special symbol	       #
      1		       1		 Identifier	 include
      1		       2		 Operator	       <
      1		       3		 Identifier	   stdio
      1		       4		 Special symbol	       .
      1		       5		 Identifier	       h
      1		       6		 Operator	       >
      2		       7		 Keyword	    void
      2		       8		 Identifier	    main
      2		       9		 Special symbol	       (
      2		      10		 Special symbol	       )
      3		      11		 Special symbol	       {
      4		      12		 Identifier	  printf
      4		      13		 Special symbol	       (
      4		      14		 Special symbol	       "
      4		      15		 Identifier	   Hello
      4		      16		 Identifier	   World
      4		      17		 Special symbol	       "
      4		      18		 Special symbol	       )
      4		      19		 Special symbol	       ;
      5		      20		 Special symbol	       }
total no of tokens:      6

--------------------------------------------------------
*/
