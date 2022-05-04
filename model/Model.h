#ifndef CALCULATOR_MODEL_H
#define CALCULATOR_MODEL_H

#include <windows.h>

#include "../controller/Observer.h"
#include "Solution.h"

class Model {
private:
    char *convertToPtrChar(const std::string &);

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
