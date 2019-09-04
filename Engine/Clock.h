#pragma once

#include<chrono>

class Clock
{
public:
	Clock();
	void CalculateCurrentTime();
	void CalculateHourMinSecCurren();
	float TimePassed();
	int GetTimeCurrent() const;
	int GetHoursCurrent() const;
	int GetMinutesCurrent() const;
	int GetSecondsCurrent() const;
private:
	int timeCurrent;
	int hoursCurrent;
	int minutesCurrent;
	int secondsCurrent;
	std::chrono::steady_clock::time_point timeCountCurrent;
};