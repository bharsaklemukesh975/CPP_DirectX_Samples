#include "bitmat_class.h"

Bitmap::Bitmap()
{}

bool Bitmap::Load_Bitmap(LPCSTR szFileName, HDC hWinDC)
{
	// Load the bitmap image file
	
	hBitmap = (HBITMAP)::LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE);
	// Verify that the image was loaded
	if (hBitmap == NULL) {
		::MessageBox(NULL,("LoadImage Failed"), ("Error"), MB_OK);
		return false;
	}
	// Create a device context that is compatible with the window
	hLocalDC = ::CreateCompatibleDC(hWinDC);
	// Verify that the device context was created
	if (hLocalDC == NULL) {
		::MessageBox(NULL,("CreateCompatibleDC Failed"),("Error"), MB_OK);
		return false;
	}

	// Get the bitmap's parameters and verify the get
	int iReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP),
		reinterpret_cast<LPVOID>(&qBitmap));
	if (!iReturn) {
		::MessageBox(NULL,("GetObject Failed"),("Error"), MB_OK);
		return false;
	}

	// Select the loaded bitmap into the device context
	hOldBmp = (HBITMAP)::SelectObject(hLocalDC, hBitmap);
	if (hOldBmp == NULL) {
		::MessageBox(NULL,("SelectObject Failed"),("Error"), MB_OK);
		return false;
	}

	// Blit the dc which holds the bitmap onto the window's dc
	qRetBlit = ::BitBlt(hWinDC, 0, 0, qBitmap.bmWidth, qBitmap.bmHeight,
		hLocalDC, 0, 0, SRCCOPY);
	if (!qRetBlit) {
		::MessageBox(NULL,("Blit Failed"),("Error"), MB_OK);
		return false;
	}

	return true;
}

Bitmap::~Bitmap()
{
	//deallocate resources
	::SelectObject(hLocalDC, hOldBmp);
	::DeleteDC(hLocalDC);
	::DeleteObject(hBitmap);
}