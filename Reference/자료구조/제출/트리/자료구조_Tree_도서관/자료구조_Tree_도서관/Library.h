#pragma once
#include"Book.h"
struct BookList
{
	Book*Root;
	BookList*Left;
	BookList*Right;
};

class Library
{
private:
	BookList*m_BookList;
	Book m_BookTool;
public:
	void MenuDraw();
	void LibraryMain();
	void RegisterNewBook();
	void Insert(BookList**Node, Book**NewBook);
	BookList*SerialNumberSerach(BookList**Node, int Num);
	bool NodeNullCheck(BookList*Node);
	void SerachMenu();
	void SaveNewBook();
	void SaveBook(BookList*Node, ofstream&Save);
	void ShowBookListMenu();
	void PreOrder(BookList**Node);
	void InOrder(BookList**Node);
	void PostOrder(BookList**Node);
	void DeleteAll(BookList*Node);
	bool Delete(BookList**Node, int data);
	void NextLink(BookList**Node);
	BookList* FindMinNode(BookList**Node);
	void DeleteMenu();
	Library();
	~Library();
};

