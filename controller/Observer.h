#ifndef CALCULATOR_OBSERVER_H
#define CALCULATOR_OBSERVER_H

#include "Controller.h"
#include "iostream"

class Observer {
public:
    Observer(class Controller *c);

    char *getInputQuery();

    void inputQuery(const std::string& input);

    void removeQuery();

    void clearQuery();

    void resultQuery();

    bool isModelSet();

private:
    Controller *contr;
};


#endif
