
#ifndef CALCULATOR_CONTROLLER_H
#define CALCULATOR_CONTROLLER_H

#include <windows.h>
#include "../model/Model.h"
#include "../view/View.h"
#include "iostream"

#define REMOVE 1
#define RESULT 2
#define REMOVE_INPUT 3
#define CLEAR_INPUT 4

class Controller {
public:
    Controller(class View *v, class Model *m);

    Controller(class Model *m);

    Controller(class View *v);

    void setModel(Model *m);

    void setView(View *v);

    Model *getModel();

    View *getView();

    char *getModelInput();

    void addModelInput(const std::string &input);

    void modelHandler(int key);

    void onLoad();

private:
    class Model *model;

    class View *view;
};


#endif