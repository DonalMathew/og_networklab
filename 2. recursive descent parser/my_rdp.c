/*
This  algorithm using Recursive procedures to implement the following Grammar.

E → TE′
E′ → +TE′
T → FT′
T′ →∗ FT′|ε
F → (E)|id

*/
#include<stdio.h>
#include<string.h>

int i=0;
char input[200];
int error=0;


void E();
void T();
void Eprime();
void Tprime();
void F();



    void E(){
        T();
        Eprime();
    }
    void Eprime(){
        if(input[i]=='+'){
            i++;
            T();
            Eprime();
        }
    }
    void T(){
        F();
        Tprime();
    }
    void Tprime(){
        if(input[i]=='*'){
            i++;
            F();
            Tprime();
        }
    }
    void F(){
        if(input[i]=='a'){
            i++;
        }
        else if(input[i]=='('){
            i++;
            E();
            
            if(input[i]==')'){
                i++;
            }
            else{
                error=1;
            }
        }
        else{
            error=1;
        }
    }



int main(){
    
    
    printf("input the expression in the form a+a*a");
    scanf("%s",input);

    E();

    if((strlen(input)==i) && (error==0)){
        printf("accepted");
    }
    else{
        printf("rejected");
    }
}
