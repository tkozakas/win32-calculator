#include "Solution.h"

#include <utility>

using namespace std;

Solution::Solution() {
    this->tokenizedExpr = tokenizer(this->expr);
}

Solution::Solution(std::string v) : expr(std::move(v)) {
    this->tokenizedExpr = tokenizer(this->expr);
}

Solution::~Solution() = default;

void Solution::setExpression(const std::string &e) {
    this->expr = e;
    this->tokenizedExpr = tokenizer(e);
}

bool Solution::isOperator(const string &c) {
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

bool Solution::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool Solution::isOperand(const string &c) {
    if (!(isOperator(c)))
        return (c != ")") && (c != "(");
    return false;
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

int Solution::getPrior(char c) {
    if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}


ldouble Solution::postfixCalculator(std::vector<string> postfixes) {
    std::vector<ldouble> operands;
    ldouble a, b, c;

    for (auto &postfix: postfixes) {
        if (isOperand(postfix))
            operands.push_back(std::stoi(postfix));
        else if (operands.size() > 1) {
            b = operands.back();
            operands.pop_back();
            a = operands.back();
            operands.pop_back();
            c = calculateWithSign(postfix[0], a, b);
            operands.push_back(c);
        }
    }
    return operands[0];
}

std::vector<string> Solution::convertToPostfix(std::vector<string> infix) {
    std::vector<string> operators;
    std::vector<string> postfix;

    for (auto &i: infix) {
        if (isOperand(i)) {
            postfix.push_back(i);
        } else if (i == "(") {
            operators.push_back(i);
        } else if (i == ")") {
            while (!operators.empty() && operators.back()[0] != '(') {
                postfix.emplace_back(1, operators.back()[0]);
                operators.pop_back();
            }
            operators.pop_back();
        } else if (isOperator(i)) {
            while (!operators.empty() && operators.back()[0] != '(' &&
                   getPrior(operators.back()[0]) >= getPrior(i[0])) {
                postfix.emplace_back(1, operators.back()[0]);
                operators.pop_back();
            }
            operators.push_back(i);
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
        if (str[i] == '(' || str[i] == ')') {
            temp = str[i];
            tokens.push_back(temp);
            temp = "";
            continue;
        }

        if (isOperator(str[i])) {
            temp = "";
            temp += str[i];
            tokens.push_back(temp);
            temp = "";
        } else {
            while (i < str.length()) {
                temp += str[i];
                i++;
                if (isOperator(str[i]) || str[i] == '(' || str[i] == ')') {
                    i--;
                    break;
                }
            }
            tokens.push_back(temp);
            temp = "";
        }
    }
    return tokens;
}

std::string Solution::getSolution() {
    this->result = to_string(postfixCalculator(convertToPostfix(this->tokenizedExpr)));
    return this->result;
}