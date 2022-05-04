#include <iostream>

#include "view/View.h"
#include "model/Model.h"
#include "controller/Controller.h"
#include "controller/Observer.h"


int main() {

    Model *model = new Model;

//    model->addInput("15 / 3 + - 3");
//    std::cout << model->calculateResult() << std::endl;

    View *view = new View;
    Controller *controller = new Controller(view, model);
    Observer *observer = new Observer(controller);

    view->setObserver(observer);
    controller->onLoad();
    return 0;
}