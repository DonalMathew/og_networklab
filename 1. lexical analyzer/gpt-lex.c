#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main() 
{
    FILE *inputFile;              // File pointer to read the input file
    int lineNumber = 1;           // Tracks the current line number in the file
    int tokenNumber = 0;          // Tracks the number of tokens identified
    int keywordIndex = 0;         // Index for looping through keywords
    int strIndex, numIndex, isKeyword;
    char currentChar, nextChar;   // Variables to store current and next characters
    char identifier[20], number[20]; // Arrays to store identified strings and numbers

    // Open the input file for reading
    inputFile = fopen("input.txt", "r");

    // Array of keywords to identify in the input
    char keywords[30][30] = {"int", "void", "if", "else", "do", "while"};

    // Print the header for the output table
    printf("Line no.\tToken no.\t\tToken\t\tLexeme\n");

    // Process the file until the end is reached
    while (!feof(inputFile)) 
    {
        strIndex = 0;
        numIndex = 0;
        isKeyword = 0; // Flag to check if an identifier is a keyword
        currentChar = fgetc(inputFile); // Read the next character

        // Check for comments
        if (currentChar == '/') 
        {
            nextChar = fgetc(inputFile); // Read the character following '/'
            if (nextChar == '/') 
            {
                // Single-line comment: skip until newline
                while ((currentChar = fgetc(inputFile)) != '\n');
                lineNumber++; // Increment line number after skipping comment
            } 
            else if (nextChar == '*') 
            {
                // Multi-line comment: skip until '*/'
                do 
                {
                    currentChar = fgetc(inputFile);
                    nextChar = fgetc(inputFile);
                    if (currentChar == '\n')
                        lineNumber++; // Increment line number within multi-line comment
                } while (currentChar != '*' || nextChar != '/');
            } 
            else 
            {
                ungetc(nextChar, inputFile); // Not a comment, revert character read
            }
            currentChar = fgetc(inputFile); // Read the next character after handling comments
        }

        // Check for operators
        if (strchr("+-*/><=%&|", currentChar)) 
        {
            printf("%7d\t\t%7d\t\tOperator\t%7c\n", lineNumber, tokenNumber, currentChar);
            tokenNumber++;
        }
        // Check for special symbols
        else if (strchr(";{}()?!@#,.\",", currentChar)) 
        {
            printf("%7d\t\t%7d\t\tSpecial Symbol\t%7c\n", lineNumber, tokenNumber, currentChar);
            tokenNumber++;
        }
        // Check for numbers
        else if (isdigit(currentChar)) 
        {
            number[numIndex++] = currentChar;
            currentChar = fgetc(inputFile);
            while (isdigit(currentChar)) 
            {
                number[numIndex++] = currentChar;
                currentChar = fgetc(inputFile);
            }
            ungetc(currentChar, inputFile); // Revert the non-digit character read
            number[numIndex] = '\0';
            printf("%7d\t\t%7d\t\tNumber\t\t%7s\n", lineNumber, tokenNumber, number);
            tokenNumber++;
        }
        // Check for keywords or identifiers
        else if (isalpha(currentChar)) 
        {
            identifier[strIndex++] = currentChar;
            currentChar = fgetc(inputFile);
            while (isalnum(currentChar)) 
            {
                identifier[strIndex++] = currentChar;
                currentChar = fgetc(inputFile);
            }
            ungetc(currentChar, inputFile); // Revert the non-alphanumeric character read
            identifier[strIndex] = '\0';

            // Check if the string matches any keyword
            for (keywordIndex = 0; keywordIndex < 30; keywordIndex++) 
            {
                if (strcmp(identifier, keywords[keywordIndex]) == 0) 
                {
                    isKeyword = 1;
                    break;
                }
            }
            // Print as keyword or identifier based on the flag
            if (isKeyword) 
            {
                printf("%7d\t\t%7d\t\tKeyword\t\t%7s\n", lineNumber, tokenNumber, identifier);
            } 
            else 
            {
                printf("%7d\t\t%7d\t\tIdentifier\t%7s\n", lineNumber, tokenNumber, identifier);
            }
            tokenNumber++;
        }
        // Increment line number if a newline character is encountered
        else if (currentChar == '\n') 
        {
            lineNumber++;
        }
    }

    // Print the total number of tokens identified
    printf("Total number of tokens: %7d\n", tokenNumber - 1);

    // Close the input file
    fclose(inputFile);

    return 0;
}

/*
input.txt:
#include<stdio.h>
void main()
{
	printf("Hello World");
}

output:
Line no.        Token no.               Token           Lexeme
      1               0         Special Symbol        #
      1               1         Identifier      include
      1               2         Operator              <
      1               3         Identifier        stdio
      1               4         Special Symbol        .
      1               5         Identifier            h
      1               6         Operator              >
      2               7         Keyword            void
      2               8         Identifier         main
      2               9         Special Symbol        (
      2              10         Special Symbol        )
      3              11         Special Symbol        {
      4              12         Identifier       printf
      4              13         Special Symbol        (
      4              14         Special Symbol        "
      4              15         Identifier        Hello
      4              16         Identifier        World
      4              17         Special Symbol        "
      4              18         Special Symbol        )
      4              19         Special Symbol        ;
      5              20         Special Symbol        }
Total number of tokens:      20

*/