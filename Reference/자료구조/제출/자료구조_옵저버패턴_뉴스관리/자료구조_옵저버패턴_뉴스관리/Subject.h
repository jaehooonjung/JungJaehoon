#pragma once
#include"Observer.h"
class Subject
{
public:
	virtual void NotifyObserver() = 0;
	virtual void AddObserver(string name) = 0;
	Subject();
	~Subject();
};

