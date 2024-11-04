/*
make sure that there is no space after the last charater, or else the last line will repeat once more in the output
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
FILE *fp,*fp1,*fp2;
fp=fopen("input.txt","r");
fp1=fopen("output.txt","w");
//fp2=fopen("output.txt","w");

int i;
char buffer[1024];

while(!feof(fp))
{
    i=0;
    fscanf(fp,"%s",buffer);
    
    if(buffer[i]=='/'){continue;} //to identify comments

    while(buffer[i]!='\0')
    {
        if(buffer[i]=='/'){break;} //to identify comments

        if(buffer[i]=='#'||buffer[i]=='<'||buffer[i]=='='||buffer[i]=='>'||buffer[i]=='('||buffer[i]==')'||buffer[i]=='{'||buffer[i]=='}'||buffer[i]=='"'||buffer[i]==';'||buffer[i]=='+')
        {
            fprintf(fp1," %c ",buffer[i]);
            
        }
        else
        {
            fprintf(fp1,"%c",buffer[i]); 
        }
        i++;
    }//inner while
    fprintf(fp1,"\n");
}//while

fclose(fp);
fclose(fp1);
}//main
