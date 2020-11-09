#include "Font.h"
#include <cassert>

Font::Font(const std::string& filename, Color chroma)
	:
	fontSheet(filename),
	glyphWidth(fontSheet.GetWidth() / nColumns),
	glyphHeight(fontSheet.GetHeight() / nRows),
	chroma(chroma)
{
	assert(glyphWidth * nColumns == fontSheet.GetWidth());
	assert(glyphHeight * nRows == fontSheet.GetHeight());
}

void Font::DrawText(const std::string& text, Color col, const VecI& pos, const RectI& drawRegion, Graphics& gfx) const
{
	auto curPos = pos;
	for (auto& c : text)
	{
		if (c >= firstChar + 1 && c <= lastChar)
		{
			gfx.DrawSpriteText(curPos.x, curPos.y, col, fontSheet, MapGlyphRect(c), drawRegion, chroma);
		}
		curPos.x += glyphWidth;
	}
}

RectI Font::MapGlyphRect(char c) const
{
	assert(c >= firstChar && c <= lastChar);
	const int glyphIndex = c - ' ';
	const int yGlyph = glyphIndex / nColumns;
	const int xGlyph = glyphIndex % nColumns;
	return RectI({ xGlyph * glyphWidth, yGlyph * glyphHeight },
		glyphWidth, glyphHeight);
}
