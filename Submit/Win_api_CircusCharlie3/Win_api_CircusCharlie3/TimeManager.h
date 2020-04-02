#pragma once
#include "Mecro.h"
struct Time
{
	int hour;
	int min;
	int sec;
	int misec;
};

class TimeManager
{
private:
	static TimeManager* m_hThis;
public:
	static TimeManager* GetInstace()
	{
		if (m_hThis == NULL)
			m_hThis = new TimeManager;
		return m_hThis;
	}
	void NowTimeSet(Time& time);
	//void TimeSet(Time& time, int addhour, int addmin, int addsec, int addmisec);
	Time TimeMinus(Time objecttime, Time standardtime);
	void Timeadd(Time& time, int addhour, int addmin, int addsec, int addmisec);
	int InvertToMisec(Time time);
	bool TimeOverCheck(Time standard, Time timetmp);
	TimeManager();
	inline 	float DegreeToRadian(int degree)
	{
		return (M_PI * (float)degree / 180);
	}
	~TimeManager();
};
