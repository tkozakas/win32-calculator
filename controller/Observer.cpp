#include "Observer.h"
Observer::Observer() = default;

Observer::Observer(Controller *c) {
    this->contr = c;
}

void Observer::removeQuery() {
    contr->modelHandler(REMOVE_INPUT);
}

void Observer::clearQuery() {
    contr->modelHandler(CLEAR_INPUT);
}

void Observer::resultQuery() {
    contr->modelHandler(RESULT);
}

void Observer::inputQuery(const std::string &input) {
    contr->addModelInput(input);
}

char *Observer::getInputQuery() {
    return contr->getModelInput();
}

void Observer::setController(class Controller *c) {
    this->contr = c;
}

