#pragma once

#include<chrono>

class Clock
{
public:
	void CalculateCurrentTime();
	void CalculateHourMinSecCurren();
	int GetTimeCurrent() const;
	int GetHoursCurrent() const;
private:
	int timeCurrent;
	int hoursCurrent;
	int minutesCurrent;
	int secondsCurrent;
};