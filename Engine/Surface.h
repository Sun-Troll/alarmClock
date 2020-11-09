#pragma once

#include "Colors.h"
#include "Rect.h"
#include <string>

class Surface
{
public:
	Surface() = default;
	Surface(const std::string& filename);
	Surface(int width, int height);
	Surface(const Surface& rhs);
	~Surface();
	Surface& operator= (const Surface& rhs);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
	RectI GetRect() const;
private:
	Color* pPixels = nullptr;
	int width;
	int height;
};