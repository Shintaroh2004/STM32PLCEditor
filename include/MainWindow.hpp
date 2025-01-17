#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "./BaseWindow.hpp"
#include "./Controlers.hpp"
#include <memory>

class MainWindow : public BaseWindow<MainWindow>
{
public:

    std::shared_ptr<Controlers> controlers;

    LPCSTR  ClassName() const { return "Sample Window Class"; }
    LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
        case WM_CREATE:
            this->controlers = std::shared_ptr<Controlers>(
                new Controlers(
                    this->m_hwnd,
                    this->hInstance
                )
            );
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_COMMAND:
            break;

        case WM_NOTIFY:
            break;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(m_hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
            EndPaint(m_hwnd, &ps);
        }
        return 0;

        default:
            return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
        }
        return TRUE;
    }
};

#endif