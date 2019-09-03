/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed('H'))
	{
		if (!pressedKeyHours)
		{
			if (drawHours == true)
			{
				drawHours = false;
			}
			else
			{
				drawHours = true;
			}
		}
		pressedKeyHours = true;
	}
	else
	{
		pressedKeyHours = false;
	}
	clock.CalculateCurrentTime();
}

void Game::ComposeFrame()
{
	if (drawAll)
	{
		//hours
		if (drawHours)
		{
			for (int y = hourBarY; y < hourBarY + hourBarHeight; ++y)
			{
				for (int x = 10; x < gfx.ScreenWidth - 10; ++x)
					gfx.PutPixel(x, y, 255, 255, 255);
			}
			for (int hDraw = 0; hDraw < 25; hDraw++) //hour
			{
				for (int y = hourBarY - 8; y < hourBarY + hourBarHeight + 8; ++y)
				{
					for (int x = 10 + hDraw * hourStep - 4; x < 10 + hDraw * hourStep + 4; ++x)
						gfx.PutPixel(x, y, 255, 255, 255);
				}
			}
			for (int hDraw = 0; hDraw < 9; hDraw++) //3hour
			{
				for (int y = hourBarY - 16; y < hourBarY + hourBarHeight + 16; ++y)
				{
					for (int x = 10 + hDraw * hourStep * 3 - 6; x < 10 + hDraw * hourStep * 3 + 6; ++x)
						gfx.PutPixel(x, y, 255, 255, 255);
				}
			}
			for (int hDraw = 0; hDraw < 4; hDraw++) //6hour
			{
				for (int y = hourBarY - 32; y < hourBarY + hourBarHeight + 32; ++y)
				{
					for (int x = 10 + hDraw * hourStep * 6 - 8; x < 10 + hDraw * hourStep * 6 + 8; ++x)
						gfx.PutPixel(x, y, 255, 255, 255);
				}
			}
			for (int y = hourBarY - 64; y < hourBarY + hourBarHeight + 64; ++y) //12hour
			{
				for (int x = 10 + 12 * hourStep - 10; x < 10 + 12 * hourStep + 10; ++x)
					gfx.PutPixel(x, y, 255, 255, 255);
			}
		}
		//minutes
		if (drawMinutes)
		{
			for (int y = minuteBarY; y < minuteBarY + minuteBarHeight; ++y)
			{
				for (int x = 10; x < gfx.ScreenWidth - 10; ++x)
					gfx.PutPixel(x, y, 255, 255, 255);
			}
			for (int mDraw = 0; mDraw < 61; mDraw++) //1min
			{
				for (int y = minuteBarY - 8; y < minuteBarY + minuteBarHeight + 8; ++y)
				{
					for (int x = 10 + mDraw * minuteStep - 4; x < 10 + mDraw * minuteStep + 4; ++x)
						gfx.PutPixel(x, y, 255, 255, 255);
				}
			}
			for (int mDraw = 0; mDraw < 13; mDraw++) //5min
			{
				for (int y = minuteBarY - 16; y < minuteBarY + minuteBarHeight + 16; ++y)
				{
					for (int x = 10 + mDraw * minuteStep * 5 - 6; x < 10 + mDraw * minuteStep * 5 + 6; ++x)
						gfx.PutPixel(x, y, 255, 255, 255);
				}
			}
			for (int mDraw = 0; mDraw < 5; mDraw++) //15min
			{
				for (int y = minuteBarY - 32; y < minuteBarY + minuteBarHeight + 32; ++y)
				{
					for (int x = 10 + mDraw * minuteStep * 15 - 8; x < 10 + mDraw * minuteStep * 15 + 8; ++x)
						gfx.PutPixel(x, y, 255, 255, 255);
				}
			}
			for (int y = minuteBarY - 64; y < minuteBarY + minuteBarHeight + 64; ++y) //30min
			{
				for (int x = 10 + 30 * minuteStep - 10; x < 10 + 30 * minuteStep + 10; ++x)
					gfx.PutPixel(x, y, 255, 255, 255);
			}
		}
		//seconds
		if (drawSeconds)
		{
			for (int y = secondBarY; y < secondBarY + secondBarHeight; ++y)
			{
				for (int x = 10; x < gfx.ScreenWidth - 10; ++x)
					gfx.PutPixel(x, y, 255, 255, 255);
			}
			for (int sDraw = 0; sDraw < 61; sDraw++) //1sec
			{
				for (int y = secondBarY - 8; y < secondBarY + secondBarHeight + 8; ++y)
				{
					for (int x = 10 + sDraw * secondStep - 4; x < 10 + sDraw * secondStep + 4; ++x)
						gfx.PutPixel(x, y, 255, 255, 255);
				}
			}
			for (int sDraw = 0; sDraw < 13; sDraw++) //5sec
			{
				for (int y = secondBarY - 16; y < secondBarY + secondBarHeight + 16; ++y)
				{
					for (int x = 10 + sDraw * secondStep * 5 - 6; x < 10 + sDraw * secondStep * 5 + 6; ++x)
						gfx.PutPixel(x, y, 255, 255, 255);
				}
			}
			for (int sDraw = 0; sDraw < 5; sDraw++) //15sec
			{
				for (int y = secondBarY - 32; y < secondBarY + secondBarHeight + 32; ++y)
				{
					for (int x = 10 + sDraw * secondStep * 15 - 8; x < 10 + sDraw * secondStep * 15 + 8; ++x)
						gfx.PutPixel(x, y, 255, 255, 255);
				}
			}
			for (int y = secondBarY - 64; y < secondBarY + secondBarHeight + 64; ++y) //30sec
			{
				for (int x = 10 + 30 * secondStep - 10; x < 10 + 30 * secondStep + 10; ++x)
					gfx.PutPixel(x, y, 255, 255, 255);
			}
		}
	}
}
