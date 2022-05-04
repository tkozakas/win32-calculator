#include "Solution.h"

using namespace std;

Solution::Solution() = default;

Solution::Solution(std::string e) {
    this->setExpression(e);
}

Solution::~Solution() = default;

void Solution::setExpression(const std::string &expression) {
    this->tokenizedExpr = tokenizer(expression);
    this->tokenizedExpr = this->reduceSign(this->tokenizedExpr);
    this->tokenizedExpr = convertToPostfix(this->tokenizedExpr);
}

bool Solution::isOperator(const string &c) {
    return isOperator(c[0]);
}

bool Solution::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool Solution::isOperand(const string &c) {
    return !isOperator(c) && (c != ")" && c != "(") || c.size() > 1;
}

// Function simplifies initial expression, by reducing signs ("-" && "-" = "+"; "-" && "val" = "-val")
std::vector<std::string> Solution::reduceSign(std::vector<std::string> expression) {

    for (long long e = 0; e < expression.size(); e++) {
        if (expression[e] == "-" && isOperand(expression[e + 1]) && e + 1 < expression.size()) {

            expression[e + 1] = to_string(stoi(expression[e + 1]) * -1);

            if (e > 0 && isOperand(expression[e - 1])) {
                expression[e] = "+";
            } else {
                expression.erase(expression.begin() + e);
            }
        }
    }

    return expression;
}

// Function takes operator and two operands, returns their result
Type Solution::calculateWithSign(char c, Type a, Type b) {
    switch (c) {
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case '*':
            return (a * b);
        case '/':
            return (a / b);
    }
    return 0;
}

// Function return priority of specific operator
int Solution::getPriority(char c) {
    return (c == '*' || c == '/') ? 2 : (c == '+' || c == '-') ? 1 : 0;
}

// Function calculates result using postfix expression, return value
Type Solution::postfixCalculator(std::vector<string> postfixes) {
    std::vector<Type> operands;
    Type a, b, c;
    std::string leftSide;

    for (auto &postfix: postfixes) {
        if (isOperand(postfix)) {
//          if postfix string is operand, then convert it to number (double / int)
            operands.push_back(std::stod(postfix));
//          operands.push_back(std::stoi(postfix));
        } else {
//          if operands are a pair of two or more
            if (operands.size() > 1) {
                b = operands.back();
                operands.pop_back();
                a = operands.back();
                operands.pop_back();
//              calculate result
                c = calculateWithSign(postfix[0], a, b);
            }
//          push back result in operands vector
            operands.push_back(c);
        }

    }
//  return last operand (result)
    return operands[0];
}

// Function converts infix expression to postfix, return vector of postfix expression
// Logic of thinking is taken from: https://www.tutorialspoint.com/Convert-Infix-to-Postfix-Expression
std::vector<string> Solution::convertToPostfix(std::vector<string> infix) {
    std::vector<string> operators;
    std::vector<string> postfix;

    // for each character string from infix expression
    for (auto &inf: infix) {
        if (isOperand(inf)) {
            postfix.push_back(inf);
        } else if (inf == "(") {
            operators.push_back(inf);
        } else if (inf == ")") {
//          if string is closing parenthesis ),
//          while vector is not empty and vecotr back != (,
//          do pop and add item from operator vector to postfix expression
            while (!operators.empty() && operators.back()[0] != '(') {
                postfix.emplace_back(1, operators.back()[0]);
                operators.pop_back();
            }
//          pop ( also from the operators
            operators.pop_back();
        } else if (isOperator(inf)) {
//          while operator vector is not empty and priority of string is less than priority of operator vector last element,
//          do pop and add into postfix expression
            while (!operators.empty() && operators.back()[0] != '(' &&
                   getPriority(operators.back()[0]) >= getPriority(inf[0])) {

                postfix.emplace_back(1, operators.back()[0]);
                operators.pop_back();
            }
            operators.push_back(inf);
        }
    }

//  while there is still operators remaining, do pop and add to the postfix expression
    while (!operators.empty()) {
        postfix.emplace_back(1, operators.back()[0]);
        operators.pop_back();
    }
    return postfix;
}

// Function uses strtok() way of tokenizing a string in vector
std::vector<string> Solution::tokenizer(string str) {
    std::vector<string> tokens;

    char input[str.length()];
    strcpy(input, str.c_str());

    const char *delimiters = " ";
    char *token = std::strtok(input, delimiters);

    while (token) {
        tokens.push_back(token);
        token = std::strtok(nullptr, delimiters);
    }

    return tokens;
}

std::string Solution::getSolution() {
    this->result = to_string(postfixCalculator(this->tokenizedExpr));
    return this->result;
}