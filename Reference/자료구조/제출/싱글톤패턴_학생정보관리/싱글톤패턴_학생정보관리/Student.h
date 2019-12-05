#pragma once
#include"Mecro.h"

class Student
{
private:
	string name;
	int kor, eng, math, sum;
	float avg;
	int num;
	char Class;
public:
	Student();
	~Student();
	void SetStudent(int _num);
	void showStudent();
	int getnum()
	{
		return num;
	}
	string getname()
	{
		return name;
	}
	char getClass()
	{
		return Class;
	}
};

