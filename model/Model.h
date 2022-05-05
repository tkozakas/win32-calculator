#ifndef CALCULATOR_MODEL_H
#define CALCULATOR_MODEL_H

#include <windows.h>
#include "Solution.h"

#define DIV_ZERO_ERROR "Math error: Attempted to divide by Zero\n"
#define INVALID_ARG "Error: Invalid argument\n"

class Model {
public:
    Model();

    Model(std::string);

    ~Model();

    char *getInput();

    void clearInput();

    void removeInput();

    void addInput(const std::string &);

    std::string calculateResult();

    Model &operator=(const std::string &);

private:
    std::string input;
    std::string result;
};


#endif
