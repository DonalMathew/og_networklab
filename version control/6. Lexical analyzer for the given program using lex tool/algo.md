**IMPLEMENT LEXICAL ANALYSER**

  

AIM

Implement lexical analyser using lex tool.

  

ALGORITHM

  

1. Start
    
2. Open the file input.c in read mode
    
3. If the file is not found . Display an error message
    
4. Else scan and analyse each component ch until the end of file
    

If ch is a keyword display ‘kwd’

If ch is an identifier display ‘id’

If ch is any arithmetic operator display ‘op-plus/sub/div/mul..’

If ch is any other operators display the same

  

5. Close the file
    
6. Stop
    

  

OUTPUT

INPUT: input.c

int a,b,c;

c = a + b;

To execute the program: lex 11anaghasethu-p2.l

cc lex.yy.c

./a.out

  

  

OUTPUT: kwd id,id,id;

id op-equ id op-plus id;