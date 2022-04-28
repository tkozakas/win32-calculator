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

    int getPrior(char c);

    bool isOperator( const string& c);

    bool isOperator(char c);

    bool isOperand(const string& c);

    std::vector<string> convertToPostfix(std::vector<string> infix);

    std::vector<string> tokenizer(string str);

    ldouble calculateWithSign(char c, ldouble a, ldouble b);

    ldouble postfixCalculator(std::vector<string> postfixes);

    std::string getSolution();

private:
    std::string expr;
    std::string result;

    vector<std::string> tokenizedExpr;
};


#endif //CALCULATOR_SOLUTION_H
