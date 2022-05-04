
#include "Model.h"

#include <algorithm>
#include <sstream>

Model::Model() = default;

Model::Model(std::string in) : input(in) {}

Model::~Model() = default;

// Function converts to pointer char (win32 functions are supporting only char*)
char *Model::convertToPtrChar(const std::string &s) {
    char *res = new char[s.size() + 1];
    memcpy(res, s.c_str(), s.size() + 1);
    return res;
}

char *Model::getInput() {
    return convertToPtrChar(this->input);
}

void Model::addInput(const std::string &in) {
    if (this->input == DIV_ZERO_ERROR || this->input == INVALID_ARG) {
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
//      Remove two times if input.back() is not digit or length of the input is greater than 0
        if(!isdigit(this->input[this->input.length() - 1]) && this->input.length() > 0) {
            this->input.pop_back();
        }
    }
}

std::string Model::calculateResult() {
    Solution sol(this->input);

    if (this->input.empty()) {
        this->result.clear();
    } else {
        try{
            this->result = sol.getSolution();
        } catch (std::runtime_error e) {
            std::cout << e.what() << std::endl;
            this->result = e.what();
        } catch (std::invalid_argument e) {
            std::cout << e.what() << std::endl;
            this->result = e.what();
        }
    }

    this->input = this->result;

    return this->result;
}

Model &Model::operator=(const std::string &str) {
    this->input = str;
    return *this;
}
