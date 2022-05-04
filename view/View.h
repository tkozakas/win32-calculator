
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

    void createButtons();

    void createWindow();

    void createTextField();
private:
    static LRESULT CALLBACK windowProcess(HWND, UINT, WPARAM, LPARAM);

    static void colorButton(WPARAM, LPARAM);

    static void colorBackground(WPARAM);

    static void buttonInput(WPARAM);

    static void keyboardInput(WPARAM);

    static void updateField(const char *);

private:
    static class Observer *observer;

    static HWND hWnd;
    static HWND textField;
    static HINSTANCE hInstance;
    static HFONT hf;

    WNDCLASS wndClass{};
};


#endif