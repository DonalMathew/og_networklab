#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    // 1.open files
    FILE *inputfp,*interfp,*outputfp;
    inputfp=fopen("input.txt","r");
    interfp=fopen("intermediate.txt","w");

    // 2.initialize buffer to store data
    int i;
    char buffer[1024];

    // 3.get strings from iput file one-by-one
    while(!feof(inputfp)){
        i=0;
        fscanf(inputfp,"%s",buffer);

        // 3.1 check for comments
        if(buffer[i]=='/'){continue;}
        
        // 3.3 jump to newline in output file
        fprintf(interfp,"\n");

        // 3.2 print each character from the buffer by considering special character and a normal character seperately
        while(buffer[i]!='\0'){

            if(buffer[i]=='/'){break;}

            if(buffer[i]=='#'||buffer[i]=='<'||buffer[i]=='>'||buffer[i]=='"'||buffer[i]==';'||buffer[i]=='('||buffer[i]==')'||buffer[i]=='='){
                fprintf(interfp," %c ",buffer[i]);
            }
            else{
                fprintf(interfp,"%c",buffer[i]);
            }
            i++;
        }
        
    }

    // 4 close the files 
    fclose(inputfp);
    fclose(interfp);

    
// 2nd part starts

    printf("token number    Token       Lexeme");
    interfp=fopen("intermediate.txt","r");
    outputfp=fopen("output.txt","w");

    int tokencounter=0;
    char keywords[30][30] = {"int", "void", "if", "else", "do", "while"};
    char operators[30][30] = {"+","-","*","/",">","<","=","%","&","|"};
    char splsymbol[30][30] = {";","{","}","(",")","?","!","@","#","."};

    int flag=0;
    while(!feof(interfp)){
        fscanf(interfp,"%s",buffer);
        //printf("%s",buffer);

        tokencounter++;

        for(i=0;i<30;i++){
            
            if(strcmp(buffer,keywords[i])==0){
                printf("\n%d          Keyword          %s",tokencounter,buffer); flag=1;
            }
            else if(strcmp(buffer,operators[i])==0){
                printf("\n%d          operator          %s",tokencounter,buffer); flag=1;
            }
            else if(strcmp(buffer,splsymbol[i])==0){
                printf("\n%d          spl symbol          %s",tokencounter,buffer); flag=1;
            }
            else if(isdigit(buffer[0])){
                printf("\n%d          number          %s",tokencounter,buffer); flag=1; break;
            }
        }
        if(flag==0){
            printf("\n%d          identifier          %s",tokencounter,buffer);
        }
        else{
            flag=0;
        }
    }

    printf("\ntotal number of tokens is: %d",tokencounter-1);

}