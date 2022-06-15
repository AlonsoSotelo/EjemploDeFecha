#pragma once
#include <iostream>
#include <conio.h>
#include "Date.h"

using namespace std;

class InputManager
{
private:
	int inDay, inMonth, inYear;
	bool type, runControl, validation;
	char option;
	Date* date;
public:
	InputManager();
	void run();
	void OutputMenu();
	void setOption();
	void SetDay();
	void SetMonth();
	void SetYear();
	void SetType();
};
