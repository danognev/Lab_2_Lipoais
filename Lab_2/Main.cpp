#pragma once
#include "Menu.h"
#include <Windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251 > nul");
	Greeting();
	return 0;
}
