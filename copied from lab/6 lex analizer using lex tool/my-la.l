%{
    int isInsideComment=0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%

#.* {
    printf("\n%s is a preprocessor directive", yytext);
}

int|float|char|double|while|for|struct {
    printf("\n\t%s is a keyword",yytext);
}

"/*" {
    isInsideComment=1;
    printf("\n\t %s is a comment",yytext);
}

{identifier}\( {
    if(!isInsideComment)
        printf("\n Function \n\t %s",yytext);
}

