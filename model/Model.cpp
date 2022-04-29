
#include "Model.h"

#include <algorithm>
#include <sstream>

Model::Model() {}

Model::~Model() = default;

char *Model::convertToPtrChar(const std::string &s) {
    char *res = new char[s.size() + 1];
    memcpy(res, s.c_str(), s.size() + 1);
    return res;
}

char *Model::getInput() {
    return convertToPtrChar(this->input);
}

void Model::addInput(const std::string &in) {
    if (this->input == "error") {
        this->input.clear();
    }
    this->input += in;
}

void Model::clearInput() {
    this->input.clear();
    this->result.clear();
}

void Model::removeInput() {
    if (!this->input.empty()) {
        this->input.pop_back();
    }
}

void Model::calculateResult() {
    Solution sol(this->input);

    if (this->input.empty()) {
        this->result.clear();
    } else {
        this->result = sol.getSolution();
    }

    this->input = this->result;
}