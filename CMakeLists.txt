cmake_minimum_required(VERSION 3.21)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(calculator main.cpp model/Model.cpp model/Model.h
        view/View.cpp view/View.h controller/Controller.cpp controller/Controller.h
        model/Solution.cpp model/Solution.h controller/Observer.cpp controller/Observer.h)
