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

char input[10];    // Array to store the input string
int i = 0;         // Index to traverse the input string
int error = 0;     // Error flag to indicate parsing errors

// Function prototypes for each non-terminal in the grammar
void E();
void T();
void Eprime();
void Tprime();
void F();

int main() 
{
    // Prompt user to enter an arithmetic expression
    printf("Recursive Descent Parser for arithmetic expressions containing + and * (e.g., a+a*a)\n");
    printf("Enter an arithmetic expression: ");
    scanf("%s", input);  // Read the input string

    E();  // Start parsing with the start symbol E

    // Check if the entire input string was parsed and no errors occurred
    if (strlen(input) == i && error == 0)
        printf("\nAccepted..!!!\n");  // If successful, print "Accepted"
    else
        printf("\nRejected..!!!\n");  // If not, print "Rejected"

    return 0;
}

// Function to parse the non-terminal E -> TE'
void E() 
{
    T();       // Parse the production T
    Eprime();  // Parse the production E'
}

// Function to parse the non-terminal E' -> +TE' | ε
void Eprime() 
{
    if (input[i] == '+')  // Check if the current character is '+'
    {
        i++;        // Consume '+'
        T();        // Parse the production T
        Eprime();   // Recursively parse the production E'
    }
    // Else, E' -> ε, do nothing (implicit)
}

// Function to parse the non-terminal T -> FT'
void T() 
{
    F();       // Parse the production F
    Tprime();  // Parse the production T'
}

// Function to parse the non-terminal T' -> *FT' | ε
void Tprime() 
{
    if (input[i] == '*')  // Check if the current character is '*'
    {
        i++;        // Consume '*'
        F();        // Parse the production F
        Tprime();   // Recursively parse the production T'
    }
    // Else, T' -> ε, do nothing (implicit)
}

// Function to parse the non-terminal F -> (E) | id
void F() 
{
    if (input[i] == 'a')  // Check if the current character is 'a' (representing id)
    {
        i++;  // Consume 'a'
    }
    else if (input[i] == '(')  // Check if the current character is '('
    {
        i++;  // Consume '('
        E();  // Parse the expression inside the parentheses
        if (input[i] == ')')  // Check if the closing ')' is present
        {
            i++;  // Consume ')'
        }
        else
        {
            error = 1;  // If ')' is missing, set error flag
        }
    }
    else
    {
        error = 1;  // If the input doesn't match 'a' or '(', set error flag
    }
}

/*

Recursive Descent Parser for arithmetic expressions containing + and * (e.g., a+a*a)
Enter an arithmetic expression: a+a*a

Accepted..!!!

------------------------------------------------------------------------------------

Recursive Descent Parser for arithmetic expressions containing + and * (e.g., a+a*a)
Enter an arithmetic expression: a-

Rejected..!!!

*/