/*
Name: Donal Mathew P T
Roll no: 220
--------------------------------------------------------

the grammar considered here: 
        E –> 2E2 
        E –> 3E3 
        E –> 4 
*/

//Including Libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Global Variables
int z = 0, i = 0, j = 0, c = 0;

// Modify array size to increase 
// length of string to be parsed
char a[16], ac[20], stk[15], act[10]; 

// This Function will check whether
// the stack contain a production rule 
// which is to be Reduce.
// Rules can be E->2E2 , E->3E3 , E->4
void check()
{
	// Copying string to be printed as action
	strcpy(ac,"REDUCE TO E -> "); 
	
	// c=length of input string
	for(z = 0; z < c; z++) 
	{
		//checking for producing rule E->4
		if(stk[z] == '4') 
		{
			printf("%s4", ac);
			stk[z] = 'E';
			stk[z + 1] = '\0';
			
			//printing action
			printf("\n$%s\t%s$\t", stk, a); 
		}
	}
		
	for(z = 0; z < c - 2; z++)
	{
		//checking for another production
		if(stk[z] == '2' && stk[z + 1] == 'E' && 
								stk[z + 2] == '2') 
		{
			printf("%s2E2", ac);
			stk[z] = 'E';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			printf("\n$%s\t%s$\t", stk, a);
			i = i - 2;
		}
		
	}
		
	for(z=0; z<c-2; z++)
	{
		//checking for E->3E3
		if(stk[z] == '3' && stk[z + 1] == 'E' && 
								stk[z + 2] == '3') 
		{
			printf("%s3E3", ac);
			stk[z]='E';
			stk[z + 1]='\0';
			stk[z + 1]='\0';
			printf("\n$%s\t%s$\t", stk, a);
			i = i - 2;
		}
	}
	return ; //return to main
}

//Driver Function
int main()
{
	printf("GRAMMAR is -\nE->2E2 \nE->3E3 \nE->4\n"); 
	
	// input string
	printf("\n input here:\n");
	char buffer[1024];
	scanf("%s",buffer);
	strcpy(a,buffer); 
	
	// strlen(a) will return the length of a to c
	c=strlen(a); 
	
	// "SHIFT" is copied to act to be printed
	strcpy(act,"SHIFT"); 
	
	// This will print Labels (column name)
	printf("\nstack \t input \t action"); 
	
	// This will print the initial 
	// values of stack and input
	printf("\n$\t%s$\t", a); 
	
	// This will Run upto length of input string
	for(i = 0; j < c; i++, j++) 
	{
		// Printing action
		printf("%s", act); 
		
		// Pushing into stack
		stk[i] = a[j];	 
		stk[i + 1] = '\0';
		
		// Moving the pointer
		a[j]=' ';
		
		// Printing action
		printf("\n$%s\t%s$\t", stk, a); 
		
		// Call check function ..which will 
		// check the stack whether its contain
		// any production or not
		check(); 
	}
	
	// Rechecking last time if contain
	// any valid production then it will
	// replace otherwise invalid
	check(); 
	
	// if top of the stack is E(starting symbol)
	// then it will accept the input
	if(stk[0] == 'E' && stk[1] == '\0') 
		printf("Accept\n");
	else //else reject
		printf("Reject\n");
}
// This code is contributed by Ritesh Aggarwal


/*-----------------------------------------------

INPUT-1:

GRAMMAR is -
E->2E2 
E->3E3 
E->4

 input here:
23432

OUTPUT-1:

stack 	 input 	 action
$	23432$	SHIFT
$2	 3432$	SHIFT
$23	  432$	SHIFT
$234	   32$	REDUCE TO E -> 4
$23E	   32$	SHIFT
$23E3	    2$	REDUCE TO E -> 3E3
$2E	    2$	SHIFT
$2E2	     $	REDUCE TO E -> 2E2
$E	     $	Accept

------------------------------------------------------
INPUT-2:

GRAMMAR is -
E->2E2 
E->3E3 
E->4

 input here:
2321

OUTPUT-2:

stack 	 input 	 action
$	2321$	SHIFT
$2	 321$	SHIFT
$23	  21$	SHIFT
$232	   1$	SHIFT
$2321	    $	Reject

---------------------------------------------------------
*/
