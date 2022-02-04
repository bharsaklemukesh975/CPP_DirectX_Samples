#include "simple_window.h"
#include "bitmat_class.h"

//this is entry point of every window program
int WINAPI WinMain
	(HINSTANCE hInst, HINSTANCE hPrevInst, char * cmdParam, int cmdShow)
{
	char class_Name [] = "Simple_Window";

	//define a window class and register it under the name "Simple_Window"
	Simple_Window Window_Instance (wnd_proc, class_Name, hInst);
	Window_Instance.Register_Wnd ();

	//create and show window
	Wnd_Maker win ("Simple Window",class_Name, hInst);
	win.show_wnd(cmdShow);

	MSG msg;
	int status;
	// Keep pumping messages--they end up in our Window Procedure
	while ((status = ::GetMessageA (&msg, 0, 0, 0)) != 0 )
	{
		if (status == -1)
			return -1;
		::DispatchMessage(&msg);
	}
}

Simple_Window :: Simple_Window (WNDPROC Wnd_Proc, char const * class_Name, HINSTANCE hInst)
{
	HBRUSH h_brush = CreateSolidBrush (RGB (150, 0, 200));
	wnd_class.style = 0;
	wnd_class.lpfnWndProc = Wnd_Proc;    // Window Procedure: mandatory
	wnd_class.cbClsExtra = 0;
	wnd_class.cbWndExtra = 0;
	wnd_class.hInstance = hInst;          //owner of class: mandatory
	wnd_class.hIcon = 0;
	wnd_class.hCursor = ::LoadCursor (0, IDC_ARROW);//optional
	wnd_class.hbrBackground = (HBRUSH) h_brush;              //optional
	wnd_class.lpszMenuName = 0;
	wnd_class.lpszClassName = class_Name;//mandatory
}

Wnd_Maker :: Wnd_Maker (char const * caption, char const * class_Name, HINSTANCE hInst)
{
	_hwnd = ::CreateWindow (
		class_Name,             //name of a registered window class
		caption,                //window caption
		WS_OVERLAPPEDWINDOW,    // window style
		CW_USEDEFAULT,          //X position
		CW_USEDEFAULT,          //Y position
		CW_USEDEFAULT,          //width
		CW_USEDEFAULT,          //height
		0,                      //handle to parevt window
		0,                      //handle to menu
		hInst,                  //application instance
		0);                     //window creation data
}

LRESULT CALLBACK wnd_proc 
	(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	PAINTSTRUCT ps;
    HDC hdc;
	Bitmap *_Bitmap = new Bitmap();
	switch (message)
	{
		//in this simple program, this id the only message going to process
	case WM_DESTROY:
		::PostQuitMessage (0);
		return 0; //return 0 when processed

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		// TODO: Add any drawing code here...
		_Bitmap->Load_Bitmap(("image.bmp"), hdc);
        break;
	
	}
	delete _Bitmap;
	// All the unprocessed messages go there, to be dealt in some default way
	return ::DefWindowProcA (hwnd, message, wparam, lparam);
}