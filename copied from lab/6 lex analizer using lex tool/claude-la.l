/* ====== Definitions Section ====== */
%{
/* Variable to check if we're inside a comment */
int isInsideComment = 0;
%}

/* Define pattern for identifiers */
identifier [a-zA-Z][a-zA-Z0-9]*

/* ====== Rules Section ====== */
%%

/* 1. Preprocessor Directives */
#.*     {
    printf("\n%s is a preprocessor directive", yytext);
}

/* 2. C Keywords */
int|float|char|double|while|for|struct|typedef|do|if|break|continue|void|switch|return|else|goto    {
    printf("\n\t%s is a keyword", yytext);
}

/* 3. Comments */
"/*"    {
    isInsideComment = 1;
    printf("\n\t %s is a COMMENT", yytext);
}

/* 4. Function Declarations */
{identifier}\(    {
    if(!isInsideComment) 
        printf("\nFUNCTION \n\t%s", yytext);
}

/* 5. Code Block Markers */
\{      {
    if(!isInsideComment) 
        printf("\n BLOCK BEGINS");
}
\}      {
    if(!isInsideComment) 
        printf("BLOCK ENDS ");
}

/* 6. Variables and Arrays */
{identifier}(\[[0-9]*\])?    {
    if(!isInsideComment) 
        printf("\n %s IDENTIFIER", yytext);
}

/* 7. String Literals */
\".*\"  {
    if(!isInsideComment) 
        printf("\n\t %s is a STRING", yytext);
}

/* 8. Numbers */
[0-9]+  {
    if(!isInsideComment) 
        printf("\n %s is a NUMBER ", yytext);
}

/* 9. Parentheses */
\)(\:)? {
    if(!isInsideComment) {
        printf("\n\t");
        ECHO;
        printf("\n");
    }
}
\(      ECHO;

/* 10. Assignment Operator */
=       {
    if(!isInsideComment) 
        printf("\n\t %s is an ASSIGNMENT OPERATOR", yytext);
}

/* 11. Relational Operators */
\<=|\>=|\<|==|\>    {
    if(!isInsideComment) 
        printf("\n\t%s is a RELATIONAL OPERATOR", yytext);
}

/* ====== C Code Section ====== */
%%

/* Main function to process the input file */
int main(int argc, char **argv)
{
    /* Try to open the input file */
    FILE *inputFile;
    inputFile = fopen("var.c", "r");
    
    /* Check if file opened successfully */
    if(!inputFile) {
        printf("could not open the file");
        exit(0);
    }
    
    /* Process the file */
    yyin = inputFile;
    yylex();
    printf("\n");
    return(0);
}

/* Required function for Lex */
int yywrap()
{
    return(1);
}