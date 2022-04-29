#include "Controller.h"

Controller::Controller(Model *pModel) {
    this->model = pModel;
    this->view = nullptr;
}

Controller::Controller(View *pView) {
    this->view = pView;
    this->model = nullptr;
}

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
    if (view != nullptr) {
        this->view->Render();
    }
}

char *Controller::getModelInput() {
    if (this->model != nullptr) {
        return this->model->getInput();
    } else {
        std::cout << "Model not passed to controller construction" << std::endl;
    }
}

void Controller::addModelInput(const std::string &input) {
    if (this->model != nullptr) {
        this->model->addInput(input);
    } else {
        std::cout << "Model not passed to controller construction" << std::endl;
    }
}

void Controller::modelHandler(int key) {
    if (this->model != nullptr) {
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
    } else {
        std::cout << "Model not passed to controller construction" << std::endl;
    }
}

Model *Controller::getModel() {
    return model;
}

View *Controller::getView() {
    return view;
}
