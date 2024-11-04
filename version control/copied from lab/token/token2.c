#include<stdio.h>
#include<stdlib.h>

int main(){
FILE *fp,*fp1,*fp2;
fp=fopen("input.txt","r");
fp1=fopen("intermediate.txt","w");
//fp2=fopen("output.txt","w");

int i;
int token=0;
char buffer[1024];

while(!feof(fp)){
 i=0;
 fscanf(fp,"%s",buffer);
 token++;

 while(buffer[i]!='\0'){

  if(buffer[i]=='#'||buffer[i]=='<'||buffer[i]=='='||buffer[i]=='>'||buffer[i]=='('||buffer[i]==')'||buffer[i]=='{'||buffer[i]=='}'||buffer[i]=='"'||buffer[i]==';'||buffer[i]=='+'){
   
   fprintf(fp1," %c ",buffer[i]);
   token++;
  }

  else
  fprintf(fp1,"%c",buffer[i]);

  i++;
 }//inner while
fprintf(fp1,"\n");
}//while

printf("\ntoken count=%d",token);

fclose(fp);
fclose(fp1);
}//main
