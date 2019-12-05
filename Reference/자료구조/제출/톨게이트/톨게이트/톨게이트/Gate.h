#pragma once
#include"Mecro.h"
#include"Car.h"

class Gate
{
private:
	int m_iCurTime;
	int m_iCarDrawTime;
	int m_iCarSpeed; 
	Car* m_CarListFront;
	Car* m_CarListRear;
public:
	void CarCreate();
	void Enqueue(Car**tmp);
	void CurTimeSet();
	void TimeSet();
	void AllCarDraw();
	void Dequeue();
	Gate();
	~Gate();
};
