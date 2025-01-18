#include <Controlers.hpp>

void Controlers::init_layout(HWND& m_hwnd,HINSTANCE& hInstance)
{
	RECT m_wnd_rc;
	GetClientRect(m_hwnd, &m_wnd_rc);
	HBITMAP hbmp;
	
	this->button = CreateWindowEx(
		0,
		WC_BUTTON,
		"カスタムボタン",
		WS_CHILD | WS_VISIBLE,
		0,0,200,72,
		m_hwnd,
		(HMENU)IDList::BUTTON,
		hInstance,
		NULL
	);
}