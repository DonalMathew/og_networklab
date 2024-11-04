- first run .y file(look for tutorial inside that file).

input formats:

y = x + 2 * (3 - 1);

x = 5;


chat-gpt output:
To use your `exp.y` and `exp.l` files for parsing expressions, you'll need to provide valid input that adheres to the grammar specified in your Yacc file (`exp.y`). Below, I'll explain the expected input format and give some examples.

### Input Format

Based on your grammar, the valid expressions should follow these rules:

1. **Assignment**: An identifier (`id`) is assigned an expression, ending with a semicolon.
2. **Expressions**: The right-hand side of the assignment can be:
   - An identifier followed by additional expressions.
   - A number.
   - A negated number.
   - A parenthetical expression.

3. **Operators**: The operators allowed are `+`, `-`, `*`, and `/`.

### Example Inputs

Here are some example inputs you can use:

1. **Simple Assignment**:
   ```
   x = 5;
   ```

2. **Using Operators**:
   ```
   y = x + 2 * (3 - 1);
   ```

3. **Multiple Assignments**:
   ```
   a = 3;
   b = a + 4;
   c = (b - 1) / 2;
   ```

4. **Negative Numbers**:
   ```
   d = -5 + 3;
   ```

5. **Invalid Expressions** (for testing error handling):
   ```
   x = + 3;  // Invalid: operator without a left operand
   y = (2 + 3;  // Invalid: missing closing parenthesis
   ```

### Running the Program

1. **Create the Lex file** (`exp.l`) and Yacc file (`exp.y`) with the provided content.

2. **Compile the files** using the following commands:
   ```bash
   yacc -d exp.y
   lex exp.l
   gcc lex.yy.c y.tab.c -w
   ```

3. **Run the compiled program**:
   ```bash
   ./a.out
   ```

4. **Input the expression** when prompted.

### Sample Interaction

When you run the program and provide the input:

```
Enter the expression:
x = 5;
```

You should see the output:

```
Valid expression!
```

For an invalid input like:

```
Enter the expression:
x = + 3;
```

You should see:

```
Invalid expression!
```

This setup should help you test various valid and invalid expressions, allowing you to explore how the parser behaves based on the grammar you've defined. Let me know if you have further questions or need additional examples!
