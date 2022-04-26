#include "View.h"

#define BUTTON_WIDTH 50
#define BUTTON_HEIGHT 50
#define WINDOW_WIDTH 200
#define WINDOW_HEIGHT 330

#define Button(name, num, x, y) CreateWindow("BUTTON", (name), WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, \
                                                (x), (y), BUTTON_WIDTH, BUTTON_HEIGHT, hWnd, (HMENU) (num), NULL, NULL);

Observer *View::observer{};
HWND View::textField{};
HWND View::hWnd{};


View::View()
        : hInstance(GetModuleHandle(nullptr)) {
    std::cout << "Creating Window\n";

    this->wndClass.lpszClassName = "Window Class";
    this->wndClass.hInstance = hInstance;
    this->wndClass.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
    this->wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    this->wndClass.lpfnWndProc = windowProcess;

    if (!RegisterClass(&this->wndClass)) {
        std::cout << "'Class View' failed to create window" << std::endl;
        MessageBox(nullptr, TEXT("This program requires Windows NT!"),
                   "Window Class", MB_ICONERROR);
    }

    createWindow();
}

View::~View() {
    UnregisterClass("Window Class", this->hInstance);
}

void View::setObserver(Observer *obs) {
    observer = obs;
}

void View::Render() {
    while (true) {
        if (this->processMessage()) {
            break;
        }
    }
}

bool View::processMessage() {
    MSG msg = {};

    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (msg.message == WM_QUIT) {
            return false;
        }
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return true;
}

LRESULT CALLBACK View::windowProcess(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_COMMAND:
            buttonInput(wParam);
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void View::buttonInput(WPARAM wparam) {
    if(!observer->controllerHaveModel()) {
        return;
    }

    if (wparam >= 200 && wparam <= 209) {
        observer->inputQuery(std::to_string(wparam - 200));
    }

    switch (wparam) {
        case 11:
            observer->inputQuery(".");
            break;
        case 12:
            observer->inputQuery("(");
            break;
        case 13:
            observer->inputQuery(")");
            break;
        case 14:
            observer->inputQuery("/");
            break;
        case 15:
            observer->inputQuery("*");
            break;
        case 16:
            observer->inputQuery("-");
            break;
        case 17:
            observer->inputQuery("+");
            break;
        case 18:
            observer->resultQuery();
            break;
        case 19:
            observer->clearQuery();
            break;
        case 20:
            observer->removeQuery();
            break;
        default:
            break;
    }
    updateField(observer->getInputQuery());
}

void View::updateField(const char *fieldText) {
    SetWindowTextA(textField, fieldText);
}

void View::createWindow() {
    DWORD style = WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + WINDOW_WIDTH;
    rect.bottom = rect.top + WINDOW_HEIGHT;

    AdjustWindowRect(&rect, style, false);

    hWnd = CreateWindow (
            "Window Class",
            "win32-Calculator",
            style,
            rect.left,
            rect.top,
            rect.right - rect.left,
            rect.bottom - rect.top,
            nullptr,
            nullptr,
            hInstance,
            nullptr
    );

    // Text Field
    textField = CreateWindow(
            "EDIT",
            "",
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,
            0,
            0,
            WINDOW_WIDTH,
            60,
            hWnd,
            (HMENU) 1,
            hInstance,
            nullptr
    );

    // Creates the font
    hf = CreateFont(
            150,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            "Cambria Math"
    );

    // Buttons
    Button("0", 200, 50, 270);
    Button("1", 201, 0, 120);
    Button("2", 202, 50, 120);
    Button("3", 203, 100, 120);
    Button("4", 204, 0, 170);
    Button("5", 205, 50, 170);
    Button("6", 206, 100, 170);
    Button("7", 207, 0, 220);
    Button("8", 208, 50, 220);
    Button("9", 209, 100, 220);


    Button(".", 11, 0, 70);
    Button("(", 12, 50, 70);
    Button(")", 13, 100, 70);

    Button("/", 14, 150, 70);
    Button("*", 15, 150, 120);
    Button("-", 16, 150, 170);
    Button("+", 17, 150, 220);
    Button("=", 18, 150, 270);

    Button("C", 19, 0, 270);
    Button("X", 20, 100, 270);

    //Sets the font for all buttons. buttons id are in range of 200 to 209
    for (int i = 0; i < 10; i++) {
        SendDlgItemMessage(
                hWnd,
                200 + i,
                WM_SETFONT,
                (WPARAM) hf,
                TRUE
        );
    }

    ShowWindow(hWnd, SW_SHOW);
}

