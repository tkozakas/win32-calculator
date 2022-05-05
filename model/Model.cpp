
#include "Model.h"

#include <algorithm>
#include <sstream>

Model::Model() = default;

Model::Model(std::string in) : input(in) {}

Model::~Model() = default;

// Function converts, then returns pointer char (win32 functions are supporting only char*)
char *Model::getInput() {
    char *res = new char[this->input.size() + 1];
    memcpy(res, this->input.c_str(), this->input.size() + 1);
    return res;
}

void Model::addInput(const std::string &in) {
    if (this->input == DIV_ZERO_ERROR || this->input == INVALID_ARG) {
        this->input.clear();
    }
    std::cout << in << " ";
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
//          To remove trailing zeros, if the type of Solution class is double
            this->result.erase ( this->result.find_last_not_of('0'), std::string::npos);
            if(this->result.back() == '.') {
                this->result.pop_back();
            }
        } catch (std::runtime_error e) {
            this->result = e.what();
        } catch (std::invalid_argument e) {
            this->result = e.what();
        }
    }
    std::cout << " = " << this->result << std::endl;

    this->input = this->result;

    return this->result;
}

Model &Model::operator=(const std::string &str) {
    this->input = str;
    return *this;
}
