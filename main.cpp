#include <iostream>

#include "view/View.h"
#include "model/Model.h"
#include "controller/Controller.h"
#include "controller/Observer.h"


int main() {

    Model *model = new Model;
    View *view = new View;

    Controller *controller = new Controller(view, model);
    //Controller *controller = new Controller(view);
    //Controller *controller = new Controller(model);
    Observer *observ = new Observer(controller);

    view->setObserver(observ);
    model->setObserver(observ);

    controller->onLoad();
    return 0;
}