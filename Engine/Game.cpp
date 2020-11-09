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
#include <sstream>
#include <iomanip>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	soundAlarm0(L"Sounds\\alarm0.wav"),
	clock(),
	font("Sprites\\asciitext.bmp")
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
	const float frameTime = clock.TimePassed();
	clock.CalculateCurrentTime();
	if (!setting)
	{
		clock.CalculateHourMinSecCurren();
		clock.CalculateHourMinSecRemain();
		std::ostringstream curTimeTemp;
		curTimeTemp << std::setw(2) << std::setfill('0') << clock.GetHoursCurrent() <<
			':' << std::setw(2) << std::setfill('0') << clock.GetMinutesCurrent() <<
			':' << std::setw(2) << std::setfill('0') << clock.GetSecondsCurrent();
		curTime = curTimeTemp.str();
		std::ostringstream remTimeTemp;
		remTimeTemp << std::setw(2) << std::setfill('0') << clock.GetHoursRemain() <<
			':' << std::setw(2) << std::setfill('0') << clock.GetMinutesRemain() <<
			':' << std::setw(2) << std::setfill('0') << clock.GetSecondsRemain();
		remTime = remTimeTemp.str();
		if (!soundAlarm0Played && clock.AlarmPlay())
		{
			soundAlarm0.Play();
			soundAlarm0Played = true;
		}
	}
	else
	{
		while (!wnd.kbd.KeyIsEmpty())
		{
			const Keyboard::Event e = wnd.kbd.ReadKey();
			if (e.IsRelease())
			{
				switch (e.GetCode())
				{
				case VK_BACK:
					if (!enterTime.empty())
					{
						enterTime.pop_back();
					}
					break;
				case VK_RETURN:
					if (!enterTime.empty())
					{
						clock.SetAlarm(std::stoi(enterTime));
						std::ostringstream alarmTimeTemp;
						alarmTimeTemp << std::setw(2) << std::setfill('0') << clock.GetHoursAlarm() <<
							':' << std::setw(2) << std::setfill('0') << clock.GetMinutesAlarm() <<
							':' << std::setw(2) << std::setfill('0') << clock.GetSecondsAlarm();
						alarmTime = alarmTimeTemp.str();
						setting = false;
					}
					break;
				case VK_NUMPAD0:
					enterTime.push_back('0');
					break;
				case VK_NUMPAD1:
					enterTime.push_back('1');
					break;
				case VK_NUMPAD2:
					enterTime.push_back('2');
					break;
				case VK_NUMPAD3:
					enterTime.push_back('3');
					break;
				case VK_NUMPAD4:
					enterTime.push_back('4');
					break;
				case VK_NUMPAD5:
					enterTime.push_back('5');
					break;
				case VK_NUMPAD6:
					enterTime.push_back('6');
					break;
				case VK_NUMPAD7:
					enterTime.push_back('7');
					break;
				case VK_NUMPAD8:
					enterTime.push_back('8');
					break;
				case VK_NUMPAD9:
					enterTime.push_back('9');
					break;
				default:
					break;
				}
			}
		}
	}
}

void Game::ComposeFrame()
{
	if (!setting)
	{
		font.DrawText(curTime, Colors::White, { 0, 0 }, gfx.GetGameRect(), gfx);
		font.DrawText(alarmTime, Colors::White, { 0, 35 }, gfx.GetGameRect(), gfx);
		font.DrawText(remTime, Colors::White, { 0, 70 }, gfx.GetGameRect(), gfx);
	}
	else
	{
		font.DrawText("Minutes:", Colors::White, { 0, 0 }, gfx.GetGameRect(), gfx);
		font.DrawText(enterTime, Colors::White, { 0, 35 }, gfx.GetGameRect(), gfx);
	}
}
