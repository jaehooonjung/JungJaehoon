#include "Gate.h"



Gate::Gate()
{
	m_CarListFront = NULL;
	m_CarListRear = NULL;
}

void Gate::CarCreate()
{
	Car*ListTmp = new Car;
	int CarNum = (rand() % 100);
	int CarXpos = CARXPOSDEFAULT;
	int CarYpos = CARYPOSDEFAULT;
	ListTmp->CarInformationSetting(CarNum, CarXpos, CarYpos);
	Enqueue(&ListTmp);
}

void Gate::Enqueue(Car**tmp)
{
	if (m_CarListFront == NULL)
	{
		m_CarListFront = *tmp;
		m_CarListRear = *tmp;
	}
	else
	{
		m_CarListRear->NewNodeSetting(*tmp);
		m_CarListRear = *tmp;
	}
}

void Gate::CurTimeSet()
{
	m_iCurTime = clock();
}


void Gate::TimeSet()
{
	m_iCarDrawTime = clock();
	m_iCarSpeed = 500;
}

void Gate::AllCarDraw()
{

	if (m_iCurTime - m_iCarDrawTime> m_iCarSpeed)
	{
		m_iCarDrawTime = m_iCurTime;

		Car*Tmp;
		if (m_CarListFront == NULL)
			return;
		Tmp = m_CarListFront;
		do
		{
			Tmp->CarMove();
			Tmp->CarDraw();
			Tmp = Tmp->NewNodeNullCheck();
		} while (Tmp != NULL);
		//차 생성과 차 이동 
	}
}

void Gate::Dequeue()
{
	Car*Tmp;
	while (1)
	{
		if (m_CarListFront == NULL)
			return;
		Tmp = m_CarListFront;
		m_CarListFront = m_CarListFront->NewNodeNullCheck();
		cout << Tmp->CarNumber() << endl;
		delete Tmp;


	}
}


Gate::~Gate()
{
}
