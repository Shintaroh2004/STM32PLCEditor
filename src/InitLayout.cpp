#include <Controlers.hpp>
#include <tuple>

std::tuple<int, int, int, int> RECTPlace(
	RECT& rc,
	double x_ratio,
	double y_ratio,
	double width_ratio,
	double height_ratio
)
{
	int x = static_cast<int>(static_cast<double>(rc.right) * x_ratio);
	int y = static_cast<int>(static_cast<double>(rc.bottom) * y_ratio);
	int width = static_cast<int>(static_cast<double>(rc.right) * width_ratio);
	int height = static_cast<int>(static_cast<double>(rc.bottom) * height_ratio);

	return std::forward_as_tuple(x, y, width, height);
}

void Controlers::init_layout(HWND& m_hwnd,HINSTANCE& hInstance)
{
	RECT m_wnd_rc;
	GetClientRect(m_hwnd, &m_wnd_rc);
	int x, y, width, height;

	std::tie(x, y, width, height) = RECTPlace(m_wnd_rc, 0, 0.05, 0.2, 0.50);
	this->project_dir = CreateWindowEx(
		0,
		WC_TREEVIEW,
		"Exproler",
		WS_CHILD | WS_VISIBLE | WS_CAPTION,
		x, y, width, height,
		m_hwnd,
		(HMENU)IDList::PROJECT_DIR,
		hInstance,
		NULL
	);

	std::tie(x, y, width, height) = RECTPlace(m_wnd_rc, 0, 0.55, 0.2, 0.45);
	this->symbol_property = CreateWindowEx(
		0,
		WC_LISTVIEW,
		"Property",
		WS_CHILD | WS_VISIBLE | WS_CAPTION,
		x, y, width, height,
		m_hwnd,
		(HMENU)IDList::SYMBOL_PROPERTY,
		hInstance,
		NULL
	);

	std::tie(x, y, width, height) = RECTPlace(m_wnd_rc, 0.2, 0.05, 0.65, 0.65);
	this->ladder_field = CreateWindowEx(
		0,
		WC_LISTVIEW,
		"Ladder",
		WS_CHILD | WS_VISIBLE | WS_CAPTION | WS_SIZEBOX,
		x, y, width, height,
		m_hwnd,
		(HMENU)IDList::LADDER_FIELD,
		hInstance,
		NULL
	);

	std::tie(x, y, width, height) = RECTPlace(m_wnd_rc, 0.85, 0.05, 0.15, 0.65);
	this->ladder_field = CreateWindowEx(
		0,
		WC_LISTBOX,
		"Libraries",
		WS_CHILD | WS_VISIBLE | WS_CAPTION | LBS_NOINTEGRALHEIGHT,
		x, y, width, height,
		m_hwnd,
		(HMENU)IDList::LIBRARY_LIST,
		hInstance,
		NULL
	);
}