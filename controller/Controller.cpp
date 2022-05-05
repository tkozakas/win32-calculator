#include "Controller.h"

Controller::Controller(View *pView, Model *pModel) {
    this->model = pModel;
    this->view = pView;
}

void Controller::setModel(Model *pModel) {
    this->model = pModel;
}

void Controller::setView(View *pView) {
    this->view = pView;
}

void Controller::onLoad() {
    this->view->Render();
}

char *Controller::getModelInput() {
    return this->model->getInput();
}

void Controller::addModelInput(const std::string &input) {
    this->model->addInput(input);
}

void Controller::modelHandler(int key) {
    switch (key) {
        case REMOVE:
            this->model->removeInput();
            break;
        case RESULT:
            this->model->calculateResult();
            break;
        case CLEAR_INPUT:
            this->model->clearInput();
            break;
        case REMOVE_INPUT:
            this->model->removeInput();
            break;
        default:
            break;
    }
}

Model *Controller::getModel() {
    return model;
}
