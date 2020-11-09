#include "Clock.h"

Clock::Clock()
	:
	timeCountCurrent(std::chrono::steady_clock::now())
{
}

void Clock::CalculateCurrentTime()
{
	const auto now = std::chrono::system_clock::now();
	const auto timeSinceEpoch = now.time_since_epoch();
	const auto timeSinEpTimezoneAdjusted = timeSinceEpoch.count() + timezoneCount;
	//auto timeSinceY2019M09D03 = what.count() / 10000000 - 1567461601;
	daysSinceStart = int(timeSinEpTimezoneAdjusted / 864000000000);
	timeCurrent = int(timeSinEpTimezoneAdjusted / 10000000 - daysSinceStart * 86400);
}

void Clock::CalculateHourMinSecCurren()
{
	hoursCurrent = timeCurrent / 3600;
	minutesCurrent = (timeCurrent - hoursCurrent * 3600) / 60;
	secondsCurrent = timeCurrent - hoursCurrent * 3600 - minutesCurrent * 60;
}

void Clock::CalculateHourMinSecRemain()
{
	const int timeRemain = timeAlarm - timeCurrent + (alarmDay - daysSinceStart) * 24 * 3600;
	hoursRemain = timeRemain / 3600;
	minutesRemain = (timeRemain - hoursRemain * 3600) / 60;
	secondsRemain = timeRemain - hoursRemain * 3600 - minutesRemain * 60;
}

float Clock::TimePassed()
{
	const auto timeCountLast = timeCountCurrent;
	timeCountCurrent = std::chrono::steady_clock::now();
	std::chrono::duration<float> timeDuration = timeCountCurrent - timeCountLast;
	return timeDuration.count();
}

void Clock::SetAlarm(int DeltaTimeM)
{
	timeAlarm = timeCurrent + DeltaTimeM * 60;
	alarmDay = daysSinceStart;
	while (timeAlarm >= 24 * 3600)
	{
		timeAlarm -= 24 * 3600;
		++alarmDay;
	}
	hoursAlarm = timeAlarm / 3600;
	minutesAlarm = (timeAlarm - hoursAlarm * 3600) / 60;
	secondsAlarm = timeAlarm - hoursAlarm * 3600 - minutesAlarm * 60;
}

bool Clock::AlarmPlay() const
{
	return alarmDay == daysSinceStart && timeCurrent >= timeAlarm || alarmDay < daysSinceStart;
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

int Clock::GetHoursAlarm() const
{
	return hoursAlarm;
}

int Clock::GetMinutesAlarm() const
{
	return minutesAlarm;
}

int Clock::GetSecondsAlarm() const
{
	return secondsAlarm;
}

int Clock::GetHoursRemain() const
{
	return hoursRemain;
}

int Clock::GetMinutesRemain() const
{
	return minutesRemain;
}

int Clock::GetSecondsRemain() const
{
	return secondsRemain;
}
