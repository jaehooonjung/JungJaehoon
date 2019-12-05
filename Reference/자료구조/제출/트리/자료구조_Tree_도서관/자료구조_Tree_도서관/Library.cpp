#include "Library.h"



Library::Library()
{
	m_BookList = NULL;

	ifstream Load;
	Load.open("도서목록.txt");
	if (!Load.is_open())
		return;
	else
	{
		string BookName;
		string Author;
		int BookSerialNumber;
		string RentalPossibility;
		while (!Load.eof())
		{
			Book*NewBook = new Book;
			Load >> BookName;
			Load >> Author;
			Load >> BookSerialNumber;
			Load >> RentalPossibility;
			if (SerialNumberSerach(&m_BookList, BookSerialNumber) != NULL)
			{
				delete NewBook;
				continue;
			}
			NewBook->BookRegistration(BookName, Author, BookSerialNumber, RentalPossibility);
			Insert(&m_BookList, &NewBook);
		}
		Load.close();
	}
}

bool Library::NodeNullCheck(BookList*Node)
{
	if (Node->Root == NULL)
		return true;
	else
		return false;
}

BookList*Library::SerialNumberSerach(BookList**Node, int Num)
{
	if (*Node == NULL)
		return NULL;
	else if ((*Node)->Root->BookSerialNumberOutput() == Num)
	{
		(*Node)->Root->BookInfoDraw();
		return (*Node);
	}
	else if ((*Node)->Root->BookSerialNumberOutput() > Num)
		SerialNumberSerach(&(*Node)->Left, Num);
	else if ((*Node)->Root->BookSerialNumberOutput() < Num)
		SerialNumberSerach(&(*Node)->Right, Num);
}

void Library::SaveBook(BookList*Node, ofstream&Save)
{
	if (Node->Root == NULL)
		return;

	Save << Node->Root->BookNameOutput() << " " << Node->Root->AuthorOutput() << " " << Node->Root->BookSerialNumberOutput() << " " << Node->Root->RentalPossibilityOutput();
	if (Node->Left != NULL)
	{
		Save << endl;
		SaveBook(Node->Left, Save);
	}
	if (Node->Right != NULL)
	{
		Save << endl;

		SaveBook(Node->Right, Save);
	}
}

void Library::SaveNewBook()
{
	ofstream Save;
	Save.open("도서목록.txt");
	if (!Save.is_open())
	{
		system("cls");
		cout << "도서목록.txt 파일이 손상됬습니다." << endl;
		getch();
		return;
	}
	else
		SaveBook(m_BookList, Save);
	Save.close();
}

void Library::RegisterNewBook()
{
	ofstream Save;
	Save.open("도서목록.txt", ios::app);
	if (!Save.is_open())
	{
		system("cls");
		cout << "도서목록.txt 파일이 손상됬습니다." << endl;
		getch();
		return;
	}
	string BookName;
	string Author;
	int BookSerialNumber;
	string RentalPossibility;
	Book*NewBook = new Book;

	system("cls");
	cout << "책을 추가등록합니다." << endl;;
	cout << "등록할 책의 이름을 입력하세요 : ";
	cin >> BookName;
	cout << "등록할 책의 저자을 입력하세요 : ";
	cin >> Author;
	cout << "등록할 책의 시리얼넘버을 입력하세요 : ";
	while (1)
	{
		cin >> BookSerialNumber;
		if (SerialNumberSerach(&m_BookList, BookSerialNumber) == NULL)
			break;
		cout << "시리얼넘버가 중복되었습니다. 다시입력하세요 : ";
	}

	RentalPossibility = "X";

	Save << endl;
	Save << BookName << " " << Author << " " << BookSerialNumber << " " << RentalPossibility;
	Save.close();

	NewBook->BookRegistration(BookName, Author, BookSerialNumber, RentalPossibility);
	Insert(&m_BookList, &NewBook);
}

void Library::Insert(BookList**Node, Book**NewBook)
{
	if (*Node == NULL)
	{
		*Node = new BookList;
		(*Node)->Root = *NewBook;
		(*Node)->Left = NULL;
		(*Node)->Right = NULL;
	}
	else
	{
		if ((*Node)->Root == *NewBook)
		{
			cout << "중복된 데이터가 있습니다.";
			return;
		}
		else if ((*Node)->Root->BookSerialNumberOutput() > (*NewBook)->BookSerialNumberOutput())
		{
			Insert(&(*Node)->Left, &(*NewBook));
		}
		else if ((*Node)->Root->BookSerialNumberOutput() < (*NewBook)->BookSerialNumberOutput())
		{
			Insert(&(*Node)->Right, &(*NewBook));
		}
	}
}

void Library::MenuDraw()
{
	system("cls");
	cout << "\t도서관리프로그램" << endl;
	cout << "\t1. 도서등록" << endl;
	cout << "\t2. 도서목록" << endl;
	cout << "\t3. 도서검색" << endl;
	cout << "\t4. 도서삭제" << endl;
	cout << "\t5. 종료" << endl;
	cout << "입력 >>> ";
}

void Library::PreOrder(BookList**Node)
{
	if (*Node)
	{
		(*Node)->Root->BookInfoDraw();
		cout << endl;
		Sleep(300);
		PreOrder(&(*Node)->Left);
		PreOrder(&(*Node)->Right);
	}
}

void Library::InOrder(BookList**Node)
{
	if (*Node)
	{
		InOrder(&(*Node)->Left);
		(*Node)->Root->BookInfoDraw();
		cout << endl;
		Sleep(300);
		InOrder(&(*Node)->Right);
	}

}

void Library::PostOrder(BookList**Node)
{
	if (*Node)
	{
		PostOrder(&(*Node)->Left);
		PostOrder(&(*Node)->Right);
		(*Node)->Root->BookInfoDraw();
		cout << endl;
		Sleep(300);
	}
}

void Library::ShowBookListMenu()
{
	int Select;
	while (1)
	{
		system("cls");
		cout << "\t※도서정렬방법을 선택하세요." << endl;
		cout << "\t1. 전위순회(PreOrder)" << endl;
		cout << "\t2. 중위순회(InOrder)" << endl;
		cout << "\t3. 후위순회(PostOrder)" << endl;
		cout << "\t4. 종료" << endl;
		cout << "입력 >>> ";
		cin >> Select;
		system("cls");
		switch (Select)
		{
		case 1:
			PreOrder(&m_BookList);
			break;
		case 2:
			InOrder(&m_BookList);
			break;
		case 3:
			PostOrder(&m_BookList);
			break;
		case 4:
			return;
		}
		system("pause");
	}
}

void Library::SerachMenu()
{
	system("cls");
	int Num;
	Book*Tmp;
	cout << "검색할 도서의 시리얼넘버을 입력하세요 : ";
	cin >> Num;
	Tmp = SerialNumberSerach(&m_BookList, Num)->Root;
	if (Tmp == NULL)
	{
		cout << "해당 시리얼넘버가 없습니다." << endl;
		return;
	}
	else
	{
		system("cls");
		Tmp->BookInfoModify();//정보수정 및 책의 정보 업데이트
		SaveNewBook();
	}
}

void Library::DeleteAll(BookList*Node)
{
	if (NodeNullCheck(Node) == true)
		return;
	else
	{
		if (Node->Left != NULL)
			DeleteAll(Node->Left);
		if (Node->Right != NULL)
			DeleteAll(Node->Right);
		delete Node;
		Node = NULL;
	}
}

BookList* Library::FindMinNode(BookList**Node)
{
	if ((*Node)->Left == NULL)
	{
		BookList*Tmp = (*Node);
		(*Node) = (*Node)->Right;
		return Tmp;
	}
	return FindMinNode(&(*Node)->Left);
}

void Library::NextLink(BookList**Node)
{
	if ((*Node)->Left != NULL && (*Node)->Right != NULL)
	{
		BookList*Tmp = (*Node);
		(*Node) = FindMinNode(&(*Node)->Right);
	}
	else if ((*Node)->Left != NULL)
	{
		(*Node) = (*Node)->Left;
	}
	else if ((*Node)->Right != NULL)
	{
		(*Node) = (*Node)->Right;
	}
	else
		return;
}

bool Library::Delete(BookList**Node, int data)
{
	if (NodeNullCheck(*Node) == true)
		return false;
	else if ((*Node)->Root->BookSerialNumberOutput() > data)
	{
		if(Delete(&(*Node)->Left, data) == true)
			(*Node)->Right = NULL;
	}
	else if ((*Node)->Root->BookSerialNumberOutput() < data)
	{
		if (Delete(&(*Node)->Right, data) == true)
			(*Node)->Right = NULL;
	}
	else
	{
		BookList*Tmp = (*Node);
		NextLink(Node);
		(*Node)->Left = Tmp->Left;
		(*Node)->Right = Tmp->Right;
		delete Tmp;
		Tmp = NULL;
		return true;
	}

	if (NodeNullCheck(*Node) == true)
		return false;
	else if ((*Node)->Root->BookSerialNumberOutput() > data)
	{
		SerialNumberSerach(&(*Node)->Left, data);

	}

}

/*
BookList*Library::SerialNumberSerach(BookList**Node, int Num)
{
	if (*Node == NULL)
		return NULL;
	else if ((*Node)->Root->BookSerialNumberOutput() == Num)
	{
		(*Node)->Root->BookInfoDraw();
		return (*Node)->Root;
	}
	else if ((*Node)->Root->BookSerialNumberOutput() > Num)
		SerialNumberSerach(&(*Node)->Left, Num);
	else if ((*Node)->Root->BookSerialNumberOutput() < Num)
		SerialNumberSerach(&(*Node)->Right, Num);
}
*/

void Library::DeleteMenu()
{
	int data;
	system("cls");
	cout << "삭제할 책의 시리얼넘버를 입력하세요 :";
	cin >> data;

	if (SerialNumberSerach(&m_BookList, data) != NULL)
	{
		Delete(&m_BookList, data);
		cout << endl << "삭제완료" << endl;
		SaveNewBook();
	}
	else
	{
		cout << endl << "해당 시리얼넘버의 책이 없습니다." << endl;
	}
	getch();
	return;
}

void Library::LibraryMain()
{
	int Select;
	while (1)
	{
		MenuDraw();
		cin >> Select;

		switch (Select)
		{
		case 1: //도서등록 
			RegisterNewBook();
			break;
		case 2: //도서목록 
			ShowBookListMenu();
			break;
		case 3: //도서검색
			SerachMenu();
			break;
		case 4: // 도서삭제
			DeleteMenu();
			break;
		case 5:
			return;

		}
		system("pause");
	}

}

Library::~Library()
{
	DeleteAll(m_BookList);
}


