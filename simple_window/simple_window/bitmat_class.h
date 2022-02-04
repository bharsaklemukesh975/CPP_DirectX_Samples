#if !define BITMAP_CLASS_H
#define BITMAP_CLASS_H

#include <Windows.h>

class Bitmap
{
public:
	Bitmap();
	~Bitmap();
	bool Load_Bitmap(LPCSTR szFileName, HDC hWinDC);
private:
	HBITMAP hBitmap;
	HBITMAP hOldBmp;
	HDC hLocalDC;
	BITMAP qBitmap;
	BOOL qRetBlit;
};

#endif