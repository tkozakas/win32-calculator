#ifndef CALCULATOR_OBSERVER_H
#define CALCULATOR_OBSERVER_H

#include "Controller.h"
#include "iostream"

class Observer {
public:
    Observer();

    Observer(class Controller *);

    void setController(class Controller*);

    char *getInputQuery();

    void inputQuery(const std::string& input);

    void removeQuery();

    void clearQuery();

    void resultQuery();

private:
    Controller *contr;
};


#endif
