#pragma once
#include<string>
#include<iostream>
using namespace std;
class Observer
{
public:
	virtual void Updata(string contents) = 0;
	virtual void Print() = 0;
	Observer();
	~Observer();
};

