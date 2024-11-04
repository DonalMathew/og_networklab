### Algorithm for Finding FIRST and FOLLOW Sets

1. **Input the Number of Productions**:
   - Read the number of productions `n` from the user.
   - Store the productions in a 2D array `a` where each row represents a production.

2. **Repeat for Each Non-Terminal**:
   - For each non-terminal symbol entered by the user, repeat the following steps to calculate its FIRST and FOLLOW sets.

3. **Calculate FIRST Set**:
   - Initialize the FIRST set for the current non-terminal.
   - For each production:
     - If the production’s left-hand side matches the current non-terminal:
       - If the first symbol on the right-hand side is a terminal, add it to the FIRST set.
       - If the first symbol is a non-terminal, recursively calculate the FIRST set for that non-terminal and add the result to the current FIRST set.
       - If the right-hand side is epsilon (`ε` or `$` in the code), add the FOLLOW set of the left-hand side to the current FIRST set.

4. **Calculate FOLLOW Set**:
   - Initialize the FOLLOW set for the current non-terminal.
   - Add the end-of-input marker (`$`) to the FOLLOW set of the start symbol (usually the first non-terminal).
   - For each production:
     - Traverse the right-hand side to find occurrences of the current non-terminal:
       - If the non-terminal is followed by a terminal, add that terminal to the FOLLOW set.
       - If the non-terminal is followed by another non-terminal, add the FIRST set of that non-terminal to the FOLLOW set.
       - If the non-terminal is at the end of the production, recursively calculate the FOLLOW set for the production’s left-hand side and add it to the current FOLLOW set.

5. **Display Results**:
   - Output the calculated FIRST and FOLLOW sets for the current non-terminal.

6. **Continue for Other Non-Terminals**:
   - Prompt the user to continue for other non-terminals until they choose to stop.

7. **End Program**:
   - Exit the program after processing all requested non-terminals.