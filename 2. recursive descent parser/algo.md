# general algo (scroll to the end, to find algo particular to a grammer)
### General Algorithm for Recursive Descent Parser:

1. **Initialize Input and Pointers**:
   - Store the input string and set up a pointer (e.g., `i = 0`) to track the current position in the string.
   - Initialize an `error` flag (e.g., `error = 0`) to detect any parsing issues.

2. **Start Parsing**:
   - Begin the parsing process by calling the function corresponding to the start symbol of the grammar (e.g., `StartSymbol()`).
   - After the parsing is complete, check if:
     - The entire input has been consumed (i.e., `strlen(input) == i`).
     - No errors were flagged (i.e., `error == 0`).
   - Based on these checks, accept or reject the input.

3. **Implement Functions for Each Non-Terminal**:
   - For each non-terminal symbol in the grammar, create a corresponding function (e.g., `NonTerminal()`).
   - The function should follow the specific production rules of the grammar for that non-terminal:
     - **Match Terminals**: If a terminal symbol is expected (e.g., `+`, `*`, `id`), check if it matches the current input symbol:
       - If it matches, consume the symbol (e.g., `i++`).
       - If it doesn’t match, set the `error` flag.
     - **Handle Multiple Productions**: If a non-terminal has multiple productions (e.g., `A -> B | C`):
       - Use lookahead or the current input symbol to decide which production to apply.
       - Recursively call the corresponding functions for each part of the chosen production.
     - **Handle Empty Productions (ε)**: If a production can be empty (e.g., `A -> ε`), implement it by simply returning from the function without consuming any input.

4. **Error Handling**:
   - At any point, if an expected terminal does not match the current input symbol or if a non-terminal is not properly derived, set the `error` flag to indicate a problem.
   - Functions should return early if an error is detected to prevent further processing.

5. **Finish Parsing**:
   - After all the non-terminals have been processed, ensure that the input has been completely consumed and no errors have occurred.
   - If the input is accepted, print an "Accepted" message; otherwise, print "Rejected".

### Example Application:
- **Given Grammar**:
  - `S -> A B`
  - `A -> a | ε`
  - `B -> b | ε`
- **Generated Functions**:
  - `void S() { A(); B(); }`
  - `void A() { if (input[i] == 'a') i++; }`
  - `void B() { if (input[i] == 'b') i++; }`

This general algorithm can be adapted to any context-free grammar by creating appropriate recursive functions for each non-terminal and handling the parsing flow according to the grammar’s production rules.


# algo particular to a grammer
### Concise Algorithm for Recursive Descent Parser:

1. **Initialize Input and Pointers**:
   - Set the input string and initialize the index `i = 0` to traverse the string.
   - Initialize an `error` flag to 0, indicating no errors at the start.

2. **Parse the Input**:
   - Begin parsing by calling the start symbol's function (`E()` in this case).
   - After parsing, check if the input has been fully consumed (`strlen(input) == i`) and if no errors occurred (`error == 0`).
     - If both conditions are true, the input is accepted.
     - Otherwise, the input is rejected.

3. **Implement Recursive Functions for Each Non-Terminal**:
   - **`E()`**:
     - Call `T()` to handle the production `T`.
     - Call `Eprime()` to handle the rest of the production `E′`.
   - **`Eprime()`**:
     - If the current symbol is `+`, consume it (`i++`), then recursively call `T()` and `Eprime()` to handle the production `+TE′`.
   - **`T()`**:
     - Call `F()` to handle the production `F`.
     - Call `Tprime()` to handle the rest of the production `T′`.
   - **`Tprime()`**:
     - If the current symbol is `*`, consume it (`i++`), then recursively call `F()` and `Tprime()` to handle the production `∗FT′`.
   - **`F()`**:
     - If the current symbol is an identifier (`id`), consume it (`i++`).
     - If the current symbol is `(`, consume it (`i++`), call `E()`, and then check if the closing `)` is present. If not, set `error = 1`.
     - If neither condition is met, set `error = 1`.

4. **Handle Errors**:
   - Throughout the parsing process, set the `error` flag if an unexpected symbol or unmatched parenthesis is encountered.

5. **End Program**:
   - If the input string is accepted, print "Accepted".
   - If the input string is rejected, print "Rejected".

This algorithm is structured to handle any grammar by defining appropriate recursive functions for each non-terminal and managing the parsing flow based on the specific productions of the grammar.