#include "Clock.h"

void Clock::CalculateCurrentTime()
{
	auto now = std::chrono::system_clock::now();
	auto what = now.time_since_epoch();
	//auto timeSinceY2019M09D03 = what.count() / 10000000 - 1567461601;
	auto daysSinceStart = what.count() / 864000000000;
	currentTime = what.count() / 10000000 - daysSinceStart * 86400 + 7200;
}

double Clock::GetCurrentTime() const
{
	return currentTime;
}
