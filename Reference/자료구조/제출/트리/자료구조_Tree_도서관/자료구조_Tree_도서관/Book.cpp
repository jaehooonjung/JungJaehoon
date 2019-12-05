#include "Book.h"



Book::Book()
{
}

void Book::BookRegistration(string BookName, string Author, int BookSerialNumber, string RentalPossibility)
{
	m_strBookName = BookName;
	m_strAuthor = Author;
	m_iBookSerialNumber = BookSerialNumber;
	if (RentalPossibility == "X")
		m_RentalPossibility = RentalPossibility;

}

void Book::BookInfoDraw()
{
	cout << "제목 : " << m_strBookName << endl;
	cout << "저자 : " << m_strAuthor << endl;
	cout << "시리얼넘버 : " << m_iBookSerialNumber << endl;
	cout << "대여가능여부 : " << m_RentalPossibility << endl;
}

bool Book::BookInfoModify()
{
	int Select;
	string tmp;
	bool UpdataFlag = false;
	while (1)
	{
		system("cls");
		BookInfoDraw();
		cout << endl;
		cout << "책의 정보를 수정합니다." << endl;
		cout << "1. 제목" << endl;
		cout << "2. 저자" << endl;
		cout << "3. 대여가능여부" << endl;
		cout << "4. 종료" << endl;
		cout << "입력 >>> ";
		cin >> Select;
		if (Select > 0 && Select < 4)
			UpdataFlag = true;

		switch (Select)
		{
		case 1:
			cout << "수정할 제목을 입력하세요";
			cin >> tmp;
			m_strBookName = tmp;
			break;
		case 2:
			cout << "저자를 수정합니다. 수정할 내용을 입력하세요";
			cin >> tmp;
			m_strAuthor = tmp;
		case 3:
			cout << "대여가능여부를 수정합니다.";
			if (m_RentalPossibility == "O")
				m_RentalPossibility = "X";
			else
				m_RentalPossibility = "O";
			break;
		case 4:
			return UpdataFlag;
		}
		cout << "수정완료" << endl;
		getch();
	}

}


Book::~Book()
{
}
