#pragma once

#include<chrono>

class Clock
{
public:
	Clock();
	void CalculateCurrentTime();
	void CalculateHourMinSecCurren();
	void CalculateHourMinSecRemain();
	float TimePassed();
	void SetAlarm(int DeltaTimeM);
	bool AlarmPlay() const;
	int GetHoursCurrent() const;
	int GetMinutesCurrent() const;
	int GetSecondsCurrent() const;
	int GetHoursAlarm() const;
	int GetMinutesAlarm() const;
	int GetSecondsAlarm() const;
	int GetHoursRemain() const;
	int GetMinutesRemain() const;
	int GetSecondsRemain() const;
private:
	static constexpr int timezone = 1;
	static constexpr long long timezoneCount = timezone * 36000000000;
	int daysSinceStart;
	int timeCurrent;
	int hoursCurrent;
	int minutesCurrent;
	int secondsCurrent;
	int timeAlarm;
	int hoursAlarm;
	int minutesAlarm;
	int secondsAlarm;
	int hoursRemain;
	int minutesRemain;
	int secondsRemain;
	int alarmDay;
	std::chrono::steady_clock::time_point timeCountCurrent;
};