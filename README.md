*This project has been created as a technical prototype for Minishell*

# Math shell
A Recursive Descent Parser & AST Implementation

## Description
This project is a simplified mathematical interpreter designed to master the core concepts of parsing before tackling Minishell. It implements a full compilation pipeline: Lexical Analysis (Lexer), Syntactic Analysis (Parser via Recursive Descent), and an Abstract Syntax Tree (AST) to handle operator precedence and parentheses.

### Prerequisites
#### Technical Requirements
- **The Lexer**: Tokenize raw strings into distinct units (INT, PLUS, MINUS, MULT, DIV, PARENTHESES).
- **The Parser**: Build a hierarchical tree (AST) based on mathematical grammar.
- **Precedence**: Correctly handle PEMDAS (Multiplication/Division before Addition/Subtraction).
- **Parentheses**: Support nested priority levels using recursive calls.
- **Error Handling**: 
  - `Syntax Error`: For invalid sequences like `5 ++ 2` or `(3 + 1`.
  - `Division by Zero`: Handle runtime arithmetic errors.

#### Features
- **Expressions**: Handle complex strings like `(3 + 5) * 2 / (10 - 5)`.
- **AST Execution**: Recursively evaluate the tree to produce a single integer result.
- **Memory Management**: Ensure every node in the tree is properly freed after evaluation.

#### Grammar Hierarchy (RDP)
The parser follows these priority levels:
1. `parse_expression`: Handles `+` and `-`.
2. `parse_term`: Handles `*` and `/`.
3. `parse_factor`: Handles raw numbers and `(expressions)`.

#### Allowed external functions:
> `printf`, `malloc`, `realloc`, `free`, `write`, `exit`, `strtol`, `isdigit`.

### Implementation
- **Data Structure**: Binary Tree where leaf nodes are values and internal nodes are operators.
- **Algorithm**: Recursive Descent Parsing (Top-Down).

### Technical demonstration
```bash
INPUT: 
	> 3 + 5 * 2 + (3 - 1)

TOKENIZED: 
	> [DIGIT] [PLUS] [DIGIT] [MULTIPLY] [DIGIT] [L_PARENTHESIS] [DIGIT] [MINUS] [DIGIT] [R_PARENTHESIS]
AST:
	> building...
PARSED:
	> to-do

OUTPUT:
	> Result: 15
```

## Instructions
### Compiling
```bash
make
```
### Executing
```bash
./math_shell "3 + 5 * 2"
# Output: Result: 13
```