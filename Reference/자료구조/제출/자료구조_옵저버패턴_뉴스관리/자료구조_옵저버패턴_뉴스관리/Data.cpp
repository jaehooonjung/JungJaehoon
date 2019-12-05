#include "Data.h"

Data* Data::m_hThis = NULL;


Data::Data()
{
}

void Data::NotifyObserver()
{
	for (auto iter = observerList.begin(); iter != observerList.end(); iter++)
	{
		(*iter)->Updata(m_strcontents);
	}
}

void Data::AddObserver(string name)
{
	DataTable*Tmp = new DataTable;
	Tmp->NameSet(name);
	observerList.push_back(Tmp);
}

void Data::SetData(string contents)
{
	m_strcontents = contents;
}

void Data::Print()
{
	for (auto iter = observerList.begin(); iter != observerList.end(); iter++)
	{
		(*iter)->Print();
	}

}

Data::~Data()
{
	for (auto iter = observerList.begin(); iter != observerList.end(); iter++)
	{
		delete (*iter);
	}
	observerList.clear();

}
