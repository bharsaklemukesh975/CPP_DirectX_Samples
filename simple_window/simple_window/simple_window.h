#if !define SIMPLE_WINDOW_H
#define SIMPLE_WINDOW_H

#include <Windows.h>

//forword declaration of our window procedure
LRESULT CALLBACK wnd_proc 
	(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

// window of this class will be creating in this program.
class Simple_Window
{
public:
	Simple_Window (WNDPROC Wnd_Proc, char const * class_Name, HINSTANCE hInst);
	void Register_Wnd ()
	{
		::RegisterClass (&wnd_class);
	}
private:
	WNDCLASS wnd_class;
};

// Creates a window of a given Class
class Wnd_Maker
{
public:
	Wnd_Maker () : _hwnd(0) {}
	Wnd_Maker (char const * caption, char const * class_Name, HINSTANCE hInts);
	void show_wnd(int cmdShow)
	{
		::ShowWindow (_hwnd, cmdShow);
		::UpdateWindow (_hwnd);
	}
protected:
	HWND _hwnd;
};
#endif