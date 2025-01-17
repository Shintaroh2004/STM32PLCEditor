#ifndef CONTROLERS_HPP
#define CONTROLERS_HPP

#include <Windows.h>
#include <CommCtrl.h>

enum class IDList
{

};

class Controlers
{
public:


	Controlers(HWND& m_hwnd,HINSTANCE& hInstance)
	{
		this->init_layout(m_hwnd, hInstance);
	}
	void init_layout(HWND& m_hwnd, HINSTANCE& hInstance);
    void command_handle(WPARAM& wParam, LPARAM& lParam, HWND& m_hwnd);
	void notify_handle(WPARAM& wParam, LPARAM& lParam, HWND& m_hwnd);
};

#endif