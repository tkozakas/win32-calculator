#include "Solution.h"

#include <utility>


Solution::Solution() = default;

Solution::Solution(std::string e) : expr(std::move(e)) {}

Solution::~Solution() = default;

void Solution::setExpression(const std::string &e) {
    this->expr = e;
}

llInt Solution::calculate() {
    llInt l1 = 0, l2 = 1;
    llInt o1 = 1, o2 = 1;

    std::stack<llInt> st;

    for (long long i = 0; i < expr.size(); i++) {
        char x = expr[i];
        if (std::isdigit(x)) {
            llInt num = x - '0';
            while (i + 1 < expr.size() && isdigit(expr[i + 1])) {
                i++;
                num = (num * 10) + (expr[i] - '0');
            }
            l2 = (o2 == 1) ? l2 * num : l2 / num;
        } else if (x == '(') {
            st.push(l1);
            st.push(o1);
            st.push(l2);
            st.push(o2);
            l1 = 0;
            o2 = 1;
            o1 = 1;
            l2 = 1;
        } else if (x == ')') {
            llInt temp = l1 + o1 * l2;
            o2 = st.top();
            st.pop();
            l2 = st.top();
            st.pop();
            o1 = st.top();
            st.pop();
            l1 = st.top();
            st.pop();
            l2 = (o2 == 1) ? l2 * temp : l2 / temp;
        } else if (x == '*' || x == '/') {
            o2 = (x == '*') ? 1 : -1;
        } else if (x == '+' || x == '-') {
            if (x == '-' && (i == 0 || (i - 1 >= 0 && expr[i - 1] == '('))) {
                o1 = -1;
                continue;
            }
            l1 += o1 * l2;
            o1 = (x == '+') ? 1 : -1;
            l2 = 1;
            o2 = 1;
        }
    }
    return (l1 + o1 * l2);
}

std::string Solution::getSolution() {
    return to_string(this->calculate());
}
