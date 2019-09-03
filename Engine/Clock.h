#pragma once

#include<chrono>

class Clock
{
public:
	void CalculateCurrentTime();
	int GetTimeCurrent() const;
private:
	int timeCurrent;
};