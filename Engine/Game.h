/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Clock.h"
#include "Sound.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */

	Sound soundAlarm0;
	bool soundAlarm0Playing = false;
	static constexpr float soundAlarm0PlayTime = 60.0f;
	float soundAlarm0ElapsedTime = 0.0f;
	Clock clock;
	bool drawAll = true;
	bool pressedKeyAll = false;
	bool drawHours = true;
	bool pressedKeyHours = false;
	bool drawMinutes = true;
	bool pressedKeyMinutes = false;
	bool drawSeconds = true;
	bool pressedKeySeconds = false;
	static constexpr int hourBarY = 100;
	static constexpr int hourBarHeight = 4;
	static constexpr int hourStep = 60;
	static constexpr int minuteBarY = 300;
	static constexpr int minuteBarHeight = 4;
	static constexpr int minuteStep = 24;
	static constexpr int secondBarY = 500;
	static constexpr int secondBarHeight = 4;
	static constexpr int secondStep = 24;
	static constexpr int alarm0Start = 15300;
	static constexpr int alarm0End = alarm0Start + 3600;
	/********************************/
};