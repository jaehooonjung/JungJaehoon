#include "DataTable.h"



DataTable::DataTable()
{
}

void DataTable::Updata(string contents)
{
	m_strContents = contents;
}


void DataTable::NameSet(string strName)
{
	m_strName = strName;

}

void DataTable::Print()
{
	cout << m_strContents << endl << endl;
	cout << m_strName << " °í°´´Ô" << endl << endl;
}




DataTable::~DataTable()
{
}
