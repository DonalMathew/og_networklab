### Concise Algorithm for the Lexical Analyzer:

1. **Initialize Variables**: Set up line counter `l = 1`, token counter `t = 0`, and other helper variables.

2. **Open Input File**: Open `input.txt` for reading and print the header for the output table.

3. **Process File**: Loop through the file character by character:
   - **Skip Comments**: If `//` or `/*` is detected, skip characters until the end of the comment.
   - **Detect Operators**: If an operator (`+`, `-`, `*`, etc.) is found, print it as an operator token.
   - **Detect Special Symbols**: If a special symbol (`;`, `{`, `}`, etc.) is found, print it as a special symbol token.
   - **Detect Numbers**: If a digit is found, read consecutive digits to form a number and print it as a number token.
   - **Detect Keywords/Identifiers**: If a letter is found, read consecutive alphanumeric characters to form a string. Check if the string is a keyword or identifier and print it accordingly.
   - **Handle Newlines**: Increment line counter if a newline character is encountered.

4. **Close File**: After processing, close the input file and print the total number of tokens.

5. **End Program**: Exit the program.