#pragma once
#include"Subject.h"
#include"Observer.h"
#include"DataTable.h"
#include<vector>
class Data : public Subject
{
	static Data* m_hThis;

private:
	
	vector<Observer*> observerList;
	string m_strcontents;
public:
	static Data* GetInstace()
	{
		if (m_hThis == NULL)
			m_hThis = new Data;
		return m_hThis;
	}
	virtual void NotifyObserver();
	virtual void AddObserver(string name);
	void SetData(string contents);
	void Print();
	Data();
	~Data();
};

