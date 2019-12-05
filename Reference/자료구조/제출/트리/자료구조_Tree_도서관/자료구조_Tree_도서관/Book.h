#pragma once
#include"Mecro.h"
class Book
{
private:
	string m_strBookName;
	string m_strAuthor;
	int m_iBookSerialNumber;
	string m_RentalPossibility;
public:
	void BookRegistration(string BookName, string Author, int BookSerialNumber, string RentalPossibility);
	void BookInfoDraw();
	bool BookInfoModify();
	Book();

	inline string BookNameOutput()
	{
		return m_strBookName;
	}
	inline string AuthorOutput()
	{
		return m_strAuthor;
	}
	inline int BookSerialNumberOutput()
	{
		return m_iBookSerialNumber;
	}
	inline string RentalPossibilityOutput()
	{
		return m_RentalPossibility;
	}
	~Book();
};

