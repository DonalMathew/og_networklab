/*
Nikhil Jojy
R7A_246
Intermediate code generator
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int tempVar = 0;  
char input[100];  

char* newTemp() {
    static char tempName[3];
    sprintf(tempName, "t%d", tempVar++);
    return tempName;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[100];
    int top = -1, k = 0;

    for (int i = 0; i < strlen(infix); i++) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';
}

void generateIntermediateCode(char* postfix) {
    char stack[100][100]; 
    int top = -1;

    for (int i = 0; i < strlen(postfix); i++) {
        if (isalnum(postfix[i])) {
            char operand[2] = {postfix[i], '\0'};
            strcpy(stack[++top], operand);
        } else if (isOperator(postfix[i])) {
            char op2[100], op1[100], result[100];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);

            char* temp = newTemp();
            printf("%s = %s %c %s\n", temp, op1, postfix[i], op2);
            strcpy(stack[++top], temp);
        }
    }

    printf("Final Result: %s\n", stack[0]);
}

int main() {
    char postfix[100];

    printf("Enter an arithmetic expression: ");
    scanf("%s", input);

    infixToPostfix(input, postfix);

    printf("\nIntermediate Code:\n");
    generateIntermediateCode(postfix);

    return 0;
}
