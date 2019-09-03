#pragma once

#include<chrono>

class Clock
{
public:
	void CalculateCurrentTime();
	double GetCurrentTime() const;
private:
	int currentTime;
};