#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Main function
int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("input.txt", "r");  // Open input file
    outputFile = fopen("output.txt", "w");  // Open output file

    int currentIndex = 0;
    char buffer[1024];  // Buffer to hold each token from the input
    char tokens[20][100];  // Array to store tokens (operands and operators)
    int tokenType[10];  // Array to store type of each token: 0 for operand, 1 for operator, 2 for number

    // Reading the input file and categorizing each token
    while (!feof(inputFile)) {
        fscanf(inputFile, "%s", buffer);  // Read each token
        strcpy(tokens[currentIndex], buffer);  // Store token

        // Determine the type of token
        if (isdigit(buffer[0])) {  // Check if token is a number
            tokenType[currentIndex] = 2;
        } else if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/') {  // Check if token is an operator
            tokenType[currentIndex] = 1;
        } else {  // Otherwise, it's an operand
            tokenType[currentIndex] = 0;
        }
        currentIndex++;
    }
    int totalTokens = currentIndex - 1;  // Get total number of tokens
    fclose(inputFile);  // Close the input file

    // Output the original grammar (input expression)
    printf("\nGrammar is:\n");
    for (currentIndex = 0; currentIndex < totalTokens; currentIndex++) {
        printf("%s ", tokens[currentIndex]);
    }

    int useCapital = 0;  // Flag to indicate if a temporary variable is used
    int tempVariable = 65;  // ASCII value for 'A', used for naming temporary variables

    printf("\n\nIntermediate Code:\n");

    // Generate intermediate code in reverse order
    for (currentIndex = totalTokens; currentIndex >= 0; currentIndex--) {
        if (tokenType[currentIndex] == 0 && currentIndex == totalTokens) {  // Operand at the end of the expression
            printf("\n%c = %s", tempVariable, tokens[currentIndex]);
            tempVariable++;
            useCapital = 1;
        } else if (tokenType[currentIndex] == 1 && tokenType[currentIndex + 1] == 2) {  // Operator followed by a number
            printf("\n%c = %s %s %c", tempVariable, tokens[currentIndex - 1], tokens[currentIndex], tempVariable - 1);
            tempVariable++;
            currentIndex--;
            useCapital = 1;
        } else if (tokenType[currentIndex] == 1 && tokenType[currentIndex + 1] == 0 && useCapital == 1 && isdigit(tokens[currentIndex - 1][0]) == 0) {
            printf("\n%c = %s %s %c", tempVariable, tokens[currentIndex - 1], tokens[currentIndex], tempVariable - 1);
            tempVariable++;
            currentIndex--;
            useCapital = 0;
        } else if (tokenType[currentIndex] == 1 && tokenType[currentIndex + 1] == 0 && useCapital == 1) {
            printf("\n%c = %s %s %c", tempVariable, tokens[currentIndex - 1], tokens[currentIndex], tempVariable - 1);
            tempVariable++;
            currentIndex--;
            useCapital = 0;
        } else if (tokenType[currentIndex] == 1 && tokenType[currentIndex + 1] == 0) {  // Operator followed by an operand
            printf("\n%c = %s %s %s", tempVariable, tokens[currentIndex - 1], tokens[currentIndex], tokens[currentIndex + 1]);
            tempVariable++;
        } else if (tokenType[currentIndex] == 2 && useCapital == 0) {  // Number without a previous temporary variable
            printf("\n%c = %s", tempVariable, tokens[totalTokens]);
            tempVariable++;
        } else if (tokenType[currentIndex] == 2 && useCapital == 1) {  // Number with a previous temporary variable
            printf("\n%c = %s %s %c", tempVariable, tokens[currentIndex - 1], tokens[currentIndex], tempVariable - 1);
            tempVariable++;
            currentIndex--;
            useCapital = 0;
        }
    }

    printf("\n");
    return 0;
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