#include <MainWindow.hpp>
#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
    MainWindow win;

    if (!win.Create("STM32PLCEditor", WS_OVERLAPPEDWINDOW, hInstance))
    {
        return 0;
    }

    ShowWindow(win.Window(), SW_MAXIMIZE);

    win.init_UI();

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}