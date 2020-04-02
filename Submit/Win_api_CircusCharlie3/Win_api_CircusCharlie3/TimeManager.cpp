#include "TimeManager.h"
TimeManager* TimeManager::m_hThis = NULL;



TimeManager::TimeManager()
{
}

void TimeManager::NowTimeSet(Time& time)
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	time.hour = st.wHour;
	time.min = st.wMinute;
	time.sec = st.wSecond;
	time.misec = st.wMilliseconds;
}

/*
void TimeManager::TimeSet(Time& time, int addhour, int addmin, int addsec, int addmisec)
{
	time.hour = addhour;
	time.min = addmin;
	time.sec = addsec;
	time.misec = addmisec;
}
*/

Time TimeManager::TimeMinus(Time objecttime, Time standardtime)
{
	Time MinusTime;

	if (objecttime.misec <= standardtime.misec)
		MinusTime.misec = standardtime.misec - objecttime.misec;
	else
	{
		standardtime.sec--;
		standardtime.misec += 1000;
		MinusTime.misec = standardtime.misec - objecttime.misec;
	}

	if (standardtime.sec < 0) //초단위가 빌려줘서 0 미만이 된경우 분 단위에서 빌려준다
	{
		standardtime.min--;
		standardtime.sec = 60;
	}

	if (objecttime.sec <= standardtime.sec)
		MinusTime.sec = standardtime.sec - objecttime.sec;
	else
	{
		standardtime.min--;
		standardtime.misec += 60;
		MinusTime.sec = standardtime.sec - objecttime.sec;
	}

	if (standardtime.min < 0) //분단위가 빌려줘서 0 미만이 된경우 시간 단위에서 빌려준다
	{
		standardtime.hour--;
		standardtime.min = 60;
	}

	if (objecttime.min <= standardtime.min)
		MinusTime.min = standardtime.min - objecttime.min;
	else
	{
		standardtime.hour--;
		standardtime.min += 60;
		MinusTime.min = standardtime.min - objecttime.min;
	}

	if (objecttime.hour <= standardtime.hour)
		MinusTime.hour = standardtime.hour - objecttime.hour;
	else
	{
		standardtime.hour += 24;
		MinusTime.hour = standardtime.hour - objecttime.hour;
	}

	return MinusTime;
}

void TimeManager::Timeadd(Time& time, int addhour, int addmin, int addsec, int addmisec)
{
	if (addmisec != NULL)
		time.misec += addmisec;

	if (time.misec >= 1000)
	{
		time.misec = time.misec - 1000;
		time.sec += 1;
	}

	if (addsec != NULL)
		time.sec += addsec;

	if (time.sec >= 60)
	{
		time.sec = time.sec - 60;
		time.min += 1;
	}

	if (addmin != NULL)
		time.min += addmin;

	if (time.min >= 60)
	{
		time.min = time.min - 60;
		time.hour += 1;
	}

	if (addhour != NULL)
		time.hour += addhour;

}

int TimeManager::InvertToMisec(Time time)
{
	if (time.hour > 0)
		time.min += time.hour * 60;

	if (time.min > 0)
		time.sec += time.min* 60;

	if (time.sec > 0)
		time.misec += time.sec * 1000;

	return time.misec;
}

bool TimeManager::TimeOverCheck(Time standard, Time timetmp)
{
	if (standard.hour < timetmp.hour)
		return true;
	else if(standard.hour > timetmp.hour)
		return false;

	if (standard.min < timetmp.min)
		return true;
	else if (standard.min > timetmp.min)
		return false;

	if (standard.sec < timetmp.sec)
		return true;
	else if (standard.sec > timetmp.sec)
		return false;

	if (standard.misec < timetmp.misec)
		return true;
	else if (standard.misec > timetmp.misec)
		return false;

	return true;
}

TimeManager::~TimeManager()
{
}
