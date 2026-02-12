# Postfix Expression Evaluator (C++) — Custom Stack + Symbol Table

This university project demonstrates core **data structures** and **expression evaluation** in C++ by implementing:

- A **symbol table** using `std::unordered_map` (store variables like `A`, `B`)
- A **custom stack** built on a fixed-size array (no STL stack used)
- A **postfix (Reverse Polish Notation) evaluator**
- Postfix evaluation **with variables** and a simple **assignment** operation

> Postfix examples:  
> `3 4 +` → `7`  
> `3 A =` → assigns `A = 3`  
> `A B +` → evaluates using variables

---

## Features

- ✅ Evaluate postfix arithmetic expressions using `+ - * /`
- ✅ Assign variables using postfix-style assignment
- ✅ Lookup stored variables in the symbol table
- ✅ Uses a custom stack implementation to reinforce DS concepts

---

## Files

- `Cpp.cpp` — main program containing:
  - symbol table functions (`insertVariable`, `searchVariable`)
  - custom `Stack` class
  - postfix evaluation functions
  - example calls in `main()`

---

## Build & Run

### Compile (g++)
```bash
g++ -std=c++17 -O2 -Wall Cpp.cpp -o postfix_eval
```

### Run
```bash
./postfix_eval
```

On Windows (PowerShell):
```powershell
g++ -std=c++17 -O2 -Wall Cpp.cpp -o postfix_eval.exe
./postfix_eval.exe
```

---

## Example Output (from `main()`)

The current `main()` contains example expressions and prints results such as:

- Result of postfix arithmetic evaluation: `7`
- Value of variable `A`: `3`
- Value of variable `B`: `2`

(Exact output depends on the expressions configured in `main()`.)

---

## How it works (High level)

1. **Tokenize** the postfix expression using `std::stringstream`
2. For each token:
   - If it’s a number → push to stack
   - If it’s a variable name → push the variable value from the symbol table
   - If it’s an operator → pop two operands, apply operator, push result
   - If it’s `=` → pop a value and store it in the symbol table under a variable name
3. Final stack value is the result

---

## Limitations / Notes

- The stack is fixed-size (`arr[100]`). Very long expressions may overflow.
- The evaluator assumes valid postfix input (limited validation).
- Division by zero is not explicitly handled.
- `searchVariable()` currently uses `symbolTable[name]` which can create a default entry if the variable doesn’t exist.  
  (A safer approach is to use `find()` and handle missing variables explicitly.)
