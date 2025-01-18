#include <Controlers.hpp>

void Controlers::init_menu(HWND& m_hwnd, HINSTANCE& hInstance)
{
	MENUITEMINFO mii;
	hmenu = CreateMenu();

	//ファイル↓
	mii.cbSize = sizeof(MENUITEMINFO);
	mii.fMask = MIIM_FTYPE | MIIM_STRING | MIIM_SUBMENU;
	mii.fType = MFT_STRING;
	mii.dwTypeData = "ファイル(&F)";
	hsubmenu1 = mii.hSubMenu = CreatePopupMenu();
	InsertMenuItem(hmenu, (UINT)IDList::MAIN_MANU, TRUE, &mii);

	//セパレーター
	mii.fMask = MIIM_FTYPE;
	mii.fType = MFT_SEPARATOR;
	InsertMenuItem(hsubmenu1, (UINT)IDList::SUB_MANU_1, TRUE, &mii);

	SetMenu(m_hwnd, hmenu);
}