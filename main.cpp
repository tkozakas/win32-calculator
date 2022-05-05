#include <iostream>

#include "view/View.h"
#include "model/Model.h"
#include "controller/Controller.h"
#include "controller/Observer.h"


int main() {

    Model *model = new Model;

    Observer *observer = new Observer;
    View *view = new View;
    Controller *controller = new Controller(view, model);

    observer->setController(controller);
    view->setObserver(observer);

    controller->onLoad();

    return 0;
}