#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(){
FILE *fp,*fp1;
fp=fopen("input.txt","r");
fp1=fopen("output.txt","w");

int i=0;
char buffer[1024];
char b[20][100];
int flag[10];

while(!feof(fp))
{
	fscanf(fp,"%s",buffer);
	strcpy(b[i],buffer);

	if(isdigit(buffer[0]))
	{
		flag[i]=2;
		i++;
	}
	else if(buffer[0]=='+'||buffer[0]=='-'||buffer[0]=='*'||buffer[0]=='/')
	{
		flag[i]=1;
		i++;
	}
	else
	{
		flag[i]=0;
		i++;
	}
}
int len=i-1;
i=0;
fclose(fp);
printf("\ngrammer is:\n");
for(i=0;i<len;i++)
{
	printf("%s ",b[i]);
}
int capital=0;
int j=65;

printf("\n\nintermediate code: ");
for(i=len-1;i>=0;i--)
{
	if(flag[i]==2)
	{
		printf("\n%c = inttofloat(%s)",j,b[len]);
		j++;
	}
	else if(flag[i]==1 && flag[i+1]==2)
	{
		printf("\n%c = %s %s %c",j,b[i-1],b[i],j-1);
		j++;
		i--;
		capital=1;
	}
	else if(flag[i]==1 && flag[i+1]==0 && capital==1)
	{
		printf("\n%c = %s %s %c",j,b[i-1],b[i],j-1);
		j++;
		i--;
		capital=0;
	}
	else if(flag[i]==1 && flag[i+1]==0)
	{
		printf("\n%c = %s %s %s",j,b[i-1],b[i],b[i+1]);
		j++;
	}
	
}
printf("\n");

}

/*
input:

intput.txt
grammer: b + c * 60
-------------------------------------------------------------------
output:

grammer is:
b + c * 60 

intermediate code: 
A = inttofloat(60)
B = c * A
C = b + B

*/

