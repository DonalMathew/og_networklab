/*
the grammar considered here: 
        E –> 2E2 
        E –> 3E3 
        E –> 4 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
int inputIndex = 0, stackIndex = 0, length = 0;
char inputString[16], stack[15], action[10];

// This function checks if the current stack contents match any production rule
void checkReduction()
{
    // Copying string to be printed as action
    char reductionAction[30] = "REDUCE TO E -> "; 
    
    // Check for production rule E -> 4
    for (int z = 0; z < length; z++) 
    {
        if (stack[z] == '4') 
        {
            printf("%s4\n", reductionAction);
            stack[z] = 'E';
            stack[z + 1] = '\0'; // Terminate the string
            printf("\n$%s\t%s$\t", stack, inputString); 
        }
    }

    // Check for production rule E -> 2E2
    for (int z = 0; z < length - 2; z++)
    {
        if (stack[z] == '2' && stack[z + 1] == 'E' && stack[z + 2] == '2') 
        {
            printf("%s2E2\n", reductionAction);
            stack[z] = 'E';
            stack[z + 1] = '\0'; // Terminate the string
            stack[z + 2] = '\0'; // Terminate the string
            printf("\n$%s\t%s$\t", stack, inputString);
            inputIndex -= 2; // Adjust input index
        }
    }
    
    // Check for production rule E -> 3E3
    for (int z = 0; z < length - 2; z++)
    {
        if (stack[z] == '3' && stack[z + 1] == 'E' && stack[z + 2] == '3') 
        {
            printf("%s3E3\n", reductionAction);
            stack[z] = 'E';
            stack[z + 1] = '\0'; // Terminate the string
            stack[z + 2] = '\0'; // Terminate the string
            printf("\n$%s\t%s$\t", stack, inputString);
            inputIndex -= 2; // Adjust input index
        }
    }
}

// Main Function
int main()
{
    printf("GRAMMAR is -\nE -> 2E2 \nE -> 3E3 \nE -> 4\n"); 
    
    // Input string from the user
    printf("\nEnter input string:\n");
    char buffer[1024];
    scanf("%s", buffer);
    strcpy(inputString, buffer); 
    
    length = strlen(inputString); 
    
    // Set action label to "SHIFT"
    strcpy(action, "SHIFT"); 
    
    // Print headers for stack, input, and action
    printf("\nStack\tInput\tAction"); 
    
    // Print initial stack and input
    printf("\n$\t%s$\t", inputString); 
    
    // Parsing loop
    for (inputIndex = 0; stackIndex < length; inputIndex++, stackIndex++) 
    {
        // Print the action
        printf("%s", action); 
        
        // Push the next input symbol onto the stack
        stack[inputIndex] = inputString[stackIndex];	 
        stack[inputIndex + 1] = '\0'; // Terminate the string
        
        // Replace the current input symbol with a space
        inputString[stackIndex] = ' ';
        
        // Print current state
        printf("\n$%s\t%s$\t", stack, inputString); 
        
        // Call checkReduction to apply any possible reductions
        checkReduction(); 
    }
    
    // Final check for reductions after the last shift
    checkReduction(); 
    
    // Final acceptance check
    if (stack[0] == 'E' && stack[1] == '\0') 
        printf("Accept\n");
    else 
        printf("Reject\n");
    
    return 0;
}

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
