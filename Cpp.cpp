#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

// Symbol Table
std::unordered_map<std::string, int> symbolTable;

void insertVariable(const std::string& name, int value) {
    symbolTable[name] = value;
}

int searchVariable(const std::string& name) {
    return symbolTable[name];
}

// Custom Stack Implementation using Array
class Stack {
private:
    int arr[100];
    int top;
public:
    Stack() : top(-1) {}

    void push(int value) {
        if (top >= 100 - 1) {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow" << std::endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }
};

// Postfix Arithmetic Evaluation
int evaluatePostfix(const std::string& expression) {
    Stack stack;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (isdigit(token[0])) { // If token is a number
            stack.push(std::stoi(token));
        } else { // If token is an operator
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            if (token == "+") {
                stack.push(operand1 + operand2);
            } else if (token == "-") {
                stack.push(operand1 - operand2);
            } else if (token == "*") {
                stack.push(operand1 * operand2);
            } else if (token == "/") {
                stack.push(operand1 / operand2);
            }
        }
    }

    return stack.pop();
}

// Postfix with Variables
int evaluatePostfixWithVariables(const std::string& expression) {
    Stack stack;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (isdigit(token[0])) { // If token is a number
            stack.push(std::stoi(token));
        } else if (token == "=") { // If token is an assignment operator
            int value = stack.pop();
            std::string variable;
            ss >> variable; // Read the next token which should be the variable name
            insertVariable(variable, value);
            return 0; // Return after assignment
        } else { // If token is a variable or operator
            if (symbolTable.find(token) != symbolTable.end()) {
                stack.push(searchVariable(token)); // It's a variable
            } else { // It's an operator
                int operand2 = stack.pop();
                int operand1 = stack.pop();
                if (token == "+") {
                    stack.push(operand1 + operand2);
                } else if (token == "-") {
                    stack.push(operand1 - operand2);
                } else if (token == "*") {
                    stack.push(operand1 * operand2);
                } else if (token == "/") {
                    stack.push(operand1 / operand2);
                }
            }
        }
    }

    return stack.pop();
}

int main() {
//    // Symbol Table examples
    insertVariable("A", 3);
    insertVariable("B", 2);

    // Postfix Arithmetic Evaluation example
    std::string expression1 = "3 4 +";
    int result1 = evaluatePostfix(expression1);
    std::cout << "Result of postfix arithmetic evaluation: " << result1 << std::endl; // Output: 7

    // Postfix with Variables examples
    std::string expression2 = "3 A =";
    

    evaluatePostfixWithVariables(expression2); // Assign 2 to variable B    
 //std::cout << "Result of postfix with variables evaluation: " << expression2 << std::endl;        

    std::string expression3 = "A B *";
    int result3 = evaluatePostfixWithVariables(expression3);
    std::cout << "Result of postfix with variables evaluation: " << result3 << std::endl; // Output: 6 (A * B)
    
     // Search operation
    int valueA = searchVariable("A");
    if (valueA != -1) {
        std::cout << "Value of variable A: " << valueA << std::endl; // Output: 3
    }

    int valueB = searchVariable("B");
    if (valueB != -1) {
        std::cout << "Value of variable B: " << valueB << std::endl; // Output: 2
    }

    return 0;
}
