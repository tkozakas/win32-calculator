//
// Created by tomas on 4/25/2022.
//

#ifndef CALCULATOR_SOLUTION_H
#define CALCULATOR_SOLUTION_H

#include <bits/stdc++.h>

using namespace std;
typedef long double ldouble;

class Solution {
public:
    Solution();

    explicit Solution(std::string v);

    ~Solution();

    void setExpression(const std::string &);

    std::string getSolution();

private:
    int getPrior(char);

    bool isOperator(const string &);

    bool isOperator(char);

    bool isOperand(const string &);

    bool validateExpression();

    std::vector<string> tokenizer(string);

    ldouble calculateWithSign(char, ldouble, ldouble);

    ldouble postfixCalculator(std::vector<string>);

    std::vector<string> convertToPostfix(std::vector<string>);

private:
    std::string expr;
    std::string result;

    vector<std::string> tokenizedExpr;
};


#endif //CALCULATOR_SOLUTION_H
