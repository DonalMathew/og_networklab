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
for(i=0;i<len;i++)
{
	printf("%s\n",b[i]);
}


}
		

