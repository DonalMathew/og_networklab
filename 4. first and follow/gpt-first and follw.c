#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Global variables
int productionCount, firstFollowIndex = 0, i = 0, j = 0;
char productions[10][10], firstFollowResult[10];

// Function prototypes
void findFollow(char symbol);
void findFirst(char symbol);

int main()
{
    int shouldContinue;
    char symbol, dummyChar;

    // Input: Number of productions
    printf("Enter the number of productions:\n");
    scanf("%d", &productionCount);
    
    // Input: Productions
    printf("Enter the productions:\n");
    for (i = 0; i < productionCount; i++)
        scanf("%s%c", productions[i], &dummyChar);

    do
    {
        firstFollowIndex = 0;
        printf("Enter the element whose FIRST & FOLLOW is to be found: ");
        scanf("%c", &symbol);

        // Find and print the FIRST set
        findFirst(symbol);
        printf("First(%c) = {", symbol);
        for (i = 0; i < firstFollowIndex; i++)
            printf("%c", firstFollowResult[i]);
        printf("}\n");

        // Reset result array for FOLLOW set
        strcpy(firstFollowResult, " ");
        firstFollowIndex = 0;

        // Find and print the FOLLOW set
        findFollow(symbol);
        printf("Follow(%c) = {", symbol);
        for (i = 0; i < firstFollowIndex; i++)
            printf("%c", firstFollowResult[i]);
        printf("}\n");

        // Continue or exit
        printf("Continue (0/1)? ");
        scanf("%d%c", &shouldContinue, &dummyChar);

    } while (shouldContinue == 1);

    return 0;
}

// Function to find the FIRST set of a given symbol
void findFirst(char symbol)
{
    int k;

    // If the symbol is a terminal, add it to the FIRST set
    if (!isupper(symbol)) 
    {
        firstFollowResult[firstFollowIndex++] = symbol;
        return;
    }

    // Loop through all productions
    for (k = 0; k < productionCount; k++)
    {
        // Check if the production rule starts with the symbol
        if (productions[k][0] == symbol)
        {
            // If the production has epsilon, add FOLLOW of the non-terminal
            if (productions[k][2] == '$')
                findFollow(productions[k][0]);
            // If the next symbol is a terminal, add it to the FIRST set
            else if (islower(productions[k][2]))
                firstFollowResult[firstFollowIndex++] = productions[k][2];
            // If the next symbol is a non-terminal, recursively find its FIRST set
            else 
                findFirst(productions[k][2]);
        }
    }
}

// Function to find the FOLLOW set of a given symbol
void findFollow(char symbol)
{
    // If the symbol is the start symbol, add '$' to its FOLLOW set
    if (productions[0][0] == symbol)
        firstFollowResult[firstFollowIndex++] = '$';

    // Loop through all productions
    for (i = 0; i < productionCount; i++)
    {
        for (j = 2; j < strlen(productions[i]); j++)
        {
            // If the symbol is found in the production rule
            if (productions[i][j] == symbol)
            {
                // If the next symbol exists, find its FIRST set
                if (productions[i][j + 1] != '\0')
                    findFirst(productions[i][j + 1]);
                
                // If the symbol is at the end of the production rule, find the FOLLOW of the non-terminal on the left-hand side
                if (productions[i][j + 1] == '\0' && symbol != productions[i][0])
                    findFollow(productions[i][0]);
            }
        }
    }
}

/*----------------------------------------
OUTPUT:

Enter the no of prooductions:
5

Enter the productions:
S=AbCd
A=Cf
A=a
C=gE
E=h

Enter the elemets whose fisrt & follow is to be found:S
First(S)={ga}
Follow(S)={$}
Continue(0/1)?1

Enter the elemets whose fisrt & follow is to be found:A
First(A)={ga}
Follow(A)={b}
Continue(0/1)?0

------------------------------------------------------
*/