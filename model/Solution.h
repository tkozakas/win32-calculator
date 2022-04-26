//
// Created by tomas on 4/25/2022.
//

#ifndef CALCULATOR_SOLUTION_H
#define CALCULATOR_SOLUTION_H

#include <bits/stdc++.h>

using namespace std;
typedef long long int llInt;
class Solution {
public:
    Solution();

    explicit Solution(std::string);

    ~Solution();

    void setExpression(const std::string &);

    llInt calculate();

    std::string getSolution();

private:
    std::string expr;
};


#endif //CALCULATOR_SOLUTION_H
