#pragma once
#include"Observer.h"
class DataTable : public Observer
{

private:
	string m_strName;
	string m_strContents;
public:
	virtual void Updata(string contents);
	virtual void Print();
	void NameSet(string strName);
	DataTable();
	~DataTable();
};

