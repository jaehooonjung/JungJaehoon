#pragma once
#include"Student.h"
class Std_manager
{
	Student* std[30];
	static Std_manager* m_hThis;
public:
	static Std_manager* GetInstace()
	{
		if (m_hThis == NULL)
			m_hThis = new Std_manager;
		return m_hThis;
	}
	Std_manager();
	void setStudent();
	void showStudent();
	void findNumber();
	void findname();
	void findClass();
	~Std_manager();
};

