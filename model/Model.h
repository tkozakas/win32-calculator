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

    ~Model();

    void setObserver(class Observer*);

    char *getInput();

    void clearInput();

    void removeInput();

    void addInput(const std::string &);

    void calculateResult();

private:
    std::string input;
    std::string result;

    class Observer *observer;
};


#endif
