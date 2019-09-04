#include "Clock.h"

Clock::Clock()
	:
	timeCountCurrent(std::chrono::steady_clock::now())
{
}

void Clock::CalculateCurrentTime()
{
	auto now = std::chrono::system_clock::now();
	auto what = now.time_since_epoch();
	//auto timeSinceY2019M09D03 = what.count() / 10000000 - 1567461601;
	auto daysSinceStart = (what.count() + 72000000000)/ 864000000000;
	timeCurrent = int(what.count() / 10000000 - daysSinceStart * 86400 + 7200);
}

void Clock::CalculateHourMinSecCurren()
{
	hoursCurrent = timeCurrent / 3600;
	minutesCurrent = (timeCurrent - hoursCurrent * 3600) / 60;
	secondsCurrent = timeCurrent - hoursCurrent * 3600 - minutesCurrent * 60;
}

float Clock::TimePassed()
{
	auto timeCountLast = timeCountCurrent;
	timeCountCurrent = std::chrono::steady_clock::now();
	std::chrono::duration<float> timeDuration = timeCountCurrent - timeCountLast;
	return timeDuration.count();
}

int Clock::GetTimeCurrent() const
{
	return timeCurrent;
}

int Clock::GetHoursCurrent() const
{
	return hoursCurrent;
}

int Clock::GetMinutesCurrent() const
{
	return minutesCurrent;
}

int Clock::GetSecondsCurrent() const
{
	return secondsCurrent;
}
