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

std::vector<std::string> Solution::reduceSign(std::vector<std::string> expression) {

    for (long long e = 0; e < expression.size(); e++) {
        if (expression[e] == "-" && isOperand(expression[e + 1]) && e + 1 < expression.size()) {

            expression[e + 1] = to_string(stoi(expression[e + 1]) * -1);
            std::cout << expression[e - 1] << expression[e] << expression[e + 1] << std::endl;

            if (e > 0 && isOperand(expression[e - 1])) {
                expression[e] = "+";
            } else {
                expression.erase(expression.begin() + e);
            }
        }
    }

    return expression;
}

ldouble Solution::calculateWithSign(char c, ldouble a, ldouble b) {
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

int Solution::getPriority(char c) {
    if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}


ldouble Solution::postfixCalculator(std::vector<string> postfixes) {
    std::vector<ldouble> operands;
    ldouble a, b, c;
    std::string leftSide;


    for (auto &postfix: postfixes) {
        if (isOperand(postfix)) {
            operands.push_back(std::stoi(postfix));
        } else {
            if (operands.size() > 1) {
                b = operands.back();
                operands.pop_back();
                a = operands.back();
                operands.pop_back();
                std::cout << "sign:" << postfix[0] << " a:" << a << " b:" << b << std::endl;
                c = calculateWithSign(postfix[0], a, b);
            }
            operands.push_back(c);
        }

    }


    return operands[0];
}

std::vector<string> Solution::convertToPostfix(std::vector<string> infix) {
    std::vector<string> operators;
    std::vector<string> postfix;

    for (auto &inf: infix) {
        if (isOperand(inf)) {
            postfix.push_back(inf);
        } else if (inf == "(") {
            operators.push_back(inf);
        } else if (inf == ")") {
            while (!operators.empty() && operators.back()[0] != '(') {
                postfix.emplace_back(1, operators.back()[0]);
                operators.pop_back();
            }
            operators.pop_back();
        } else if (isOperator(inf)) {
            while (!operators.empty() && operators.back()[0] != '(' &&
                   getPriority(operators.back()[0]) >= getPriority(inf[0])) {

                postfix.emplace_back(1, operators.back()[0]);
                operators.pop_back();
            }
            operators.push_back(inf);
        }
    }

    while (!operators.empty()) {
        postfix.emplace_back(1, operators.back()[0]);
        operators.pop_back();
    }
    return postfix;
}

std::vector<string> Solution::tokenizer(string str) {
    std::vector<string> tokens;
    string temp;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            continue;
        }
        if (str[i] == '(' || str[i] == ')') {
            temp = str[i];
            tokens.push_back(temp);
            temp.clear();
            continue;
        }

        if (isOperator(str[i])) {
            temp.clear();
            temp += str[i];
            tokens.push_back(temp);
            temp.clear();
        } else {
            do {
                temp += str[i];
                i++;
                if (isOperator(str[i]) || str[i] == '(' || str[i] == ')') {
                    i--;
                    break;
                }
            } while (i < str.length());
            tokens.push_back(temp);
            temp.clear();
        }
    }
    return tokens;
}

std::string Solution::getSolution() {
    this->result = to_string(postfixCalculator(this->tokenizedExpr));
    return this->result;
}