### General Algorithm for Shift-Reduce Parser:

1. **Initialize Variables**:
   - Set up an input string, a stack (`stk`) to simulate parsing, and necessary counters (`i`, `j`, `z`).
   - Prepare action labels (e.g., `SHIFT`) and rules to be applied during the parsing process.

2. **Begin Parsing**:
   - **Display Initial Setup**:
     - Print the grammar rules being used.
     - Display the initial stack (which is empty) and the input string.
   - **Shift and Reduce**:
     - **SHIFT**: 
       - Take the first character of the input string and push it onto the stack.
       - Remove the shifted character from the input string.
       - Print the current state of the stack, the remaining input string, and the action taken ("SHIFT").
     - **REDUCE**:
       - Check the stack to see if the top of the stack matches any right-hand side of the production rules.
       - If a match is found:
         - Replace the matched sequence in the stack with the corresponding left-hand side of the rule.
         - Print the action taken (e.g., "REDUCE TO X -> ...").
         - Adjust the input pointer as needed.
       - If no match is found, continue shifting.

3. **Define a `check()` Function**:
   - For each rule in the grammar:
     - Compare the current contents of the stack against the right-hand side of the production.
     - If the stack contains a sequence that can be reduced, replace that sequence with the non-terminal symbol from the left-hand side of the rule.
     - Print the action taken and the new state of the stack.
   - Repeat this check until no further reductions are possible.

4. **Repeat the Parsing Process**:
   - Continue alternating between shift and reduce actions until all input symbols are either shifted or reduced.
   - After every shift, call the `check()` function to apply any possible reductions.

5. **Final Check and Acceptance**:
   - Once all input has been processed, perform a final check:
     - If the stack contains only the start symbol and no other characters, the input is accepted.
     - Otherwise, the input is rejected.

6. **Handle Errors**:
   - At any point, if the stack cannot be reduced to the start symbol or if the input is exhausted without achieving the start symbol in the stack, reject the input.

### Example Application:
- **Given Grammar**:
  - `S -> aSb | ε`
- **Shift-Reduce Steps**:
  - Shift symbols from input to stack.
  - After each shift, check if the stack can be reduced.
  - Continue until the stack contains only `S` and the input is fully consumed.

This algorithm can be adapted to any context-free grammar by adjusting the `check()` function to account for different production rules and applying the shift-reduce logic accordingly.