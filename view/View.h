
#ifndef CALCULATOR_VIEW_H
#define CALCULATOR_VIEW_H

#include <windows.h>
#include "../controller/Observer.h"

class View {
public:

    View();

    ~View();

    void setObserver(class Observer *);

    void Render();

    bool processMessage();

    void createWindow();

    static void buttonInput(WPARAM);

    static void updateField(const char *);
private:
    static class Observer *observer;

    static HWND hWnd;
    static HWND textField;

    WNDCLASS wndClass{};
    HINSTANCE hInstance{};
    HFONT hf{};

    static LRESULT CALLBACK windowProcess(HWND, UINT, WPARAM, LPARAM);
};


#endif