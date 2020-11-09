#pragma once
#include "Graphics.h"

class Font
{
public:
	Font(const std::string& filename, Color chroma = Colors::White);
	void DrawText(const std::string& text, Color col, const VecI& pos, const RectI& drawRegion, Graphics& gfx) const;
private:
	RectI MapGlyphRect(char c) const;
private:
	Surface fontSheet;
	int glyphWidth;
	int glyphHeight;
	static constexpr int nColumns = 19;
	static constexpr int nRows = 5;
	Color chroma;
	static constexpr char firstChar = ' ';
	static constexpr char lastChar = '~';
};