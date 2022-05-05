//
// Created by tomas on 4/25/2022.
//

#ifndef CALCULATOR_SOLUTION_H
#define CALCULATOR_SOLUTION_H

#include <bits/stdc++.h>

typedef long double Type;

class Solution {
public:
    Solution();

    explicit Solution(std::string v);

    ~Solution();

    void setExpression(const std::string &);

    std::string getSolution();

private:
    int getPriority(char);

    bool isOperator(const std::string &);

    bool isOperand(const std::string &);

    std::vector<std::string> tokenizer(std::string);

    Type calculateWithSign(char, Type, Type);

    Type postfixCalculator(std::vector<std::string>);

    std::vector<std::string> convertToPostfix(std::vector<std::string>);

    std::vector<std::string> reduceSign(std::vector<std::string>);
private:
    std::string result;
    std::vector<std::string> tokenizedExpr;
};


#endif //CALCULATOR_SOLUTION_H
