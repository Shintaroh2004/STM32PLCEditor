#ifndef CONTROLERS_HPP
#define CONTROLERS_HPP

#include <Windows.h>
#include <CommCtrl.h>

enum class IDList
{
	MAIN_MANU,
	SUB_MANU_1
};

class Controlers
{
public:

	HMENU hmenu;
	HMENU hsubmenu1;

	Controlers(HWND& m_hwnd,HINSTANCE& hInstance)
	{
		this->init_menu(m_hwnd, hInstance);
		this->init_layout(m_hwnd,hInstance);
	}
	void init_layout(HWND& m_hwnd, HINSTANCE& hInstance);
	void init_menu(HWND& m_hwnd, HINSTANCE& hInstance);
    void command_handle(WPARAM& wParam, LPARAM& lParam, HWND& m_hwnd);
	void notify_handle(WPARAM& wParam, LPARAM& lParam, HWND& m_hwnd);
};

#endif