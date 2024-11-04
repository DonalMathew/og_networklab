#include<stdio.h>
#include<stdlib.h>

int main(){
FILE *fp,*fp1,*fp2;
fp=fopen("input.txt","r");
fp1=fopen("intermediate.txt","w");
fp2=fopen("output.txt","w");

int i;
int token=0;
char buffer[1024];
while(!feof(fp)){
i=0;
fscanf(fp,"%s",buffer);
token++;

while(buffer[i]!='\0'){

if(buffer[i]=='#'||buffer[i]=='<'||buffer[i]=='.'||buffer[i]=='>'||buffer[i]=='('||buffer[i]==')'||buffer[i]=='{'||buffer[i]=='}'||buffer[i]=='"'||buffer[i]==';'){
fprintf(fp1," %c ",buffer[i]);
token++;
}

else
fprintf(fp1,"%c",buffer[i]);

i++;
}
fprintf(fp1,"\n");
}
printf("\ntoken count=%d",token);

fclose(fp);
fclose(fp1);
fp=fopen("input.txt","r");
fp1=fopen("intermediate.txt","w");
/*
while(!feof(fp1)){
i=0;
fscanf(fp1,"%s",buffer);
printf("%s",buffer);
/*
if(buffer[i]=='#'||buffer[i]=='.'||buffer[i]=='"'||buffer[i]==';'){
//fprintf(fp2,"%s  is a special character",buffer);
printf("%s  is logical operator",buffer);}
else if(buffer[i]=='<'||buffer[i]=='>'){
//fprintf(fp2,"%s  is logical operator",buffer);
printf("%s  is logical operator",buffer);}
else if(buffer[i]=='+'){
//fprintf(fp2,"%s",buffer);
printf("%s  is logical operator",buffer);}
else{
//fprintf(fp2,"%s  is a variable",buffer);
printf("%s  is logical operator",buffer);}
 } */

fclose(fp);
fclose(fp1);
fclose(fp2);
}
