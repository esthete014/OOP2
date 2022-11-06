// / ============================= \
// | -------  esthete014  -------- |
// | ============================= |
// |     || copyright 2022 ||      |
// |     || Nikolay        ||      |
// |     || Kochetov       ||      |
// | _____________________________ |
// | https://github.com/esthete014 |
// \ ============================= /

#pragma once
#include <iostream>
#include <ctime>


std::vector<int> KEYS;

void fillKEYS() { for (int i = 0; i < 10; i++) { KEYS.push_back(i + 48); } }

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void Blinking(bool flag) {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	flag == false ? structCursorInfo.bVisible = FALSE : structCursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

void filmSteal() {//yes, it's easter egg)))))))
	GetAsyncKeyState('1') || GetAsyncKeyState('2')
		|| GetAsyncKeyState('3') || GetAsyncKeyState('4')
		|| GetAsyncKeyState('5') || GetAsyncKeyState('6')
		|| GetAsyncKeyState('7') || GetAsyncKeyState('8')
		|| GetAsyncKeyState('9') || GetAsyncKeyState(VK_SPACE) ? NULL : NULL;
}

int getRandom() { return -100 + rand() % 201; }

int getRandom(int min, int max) {
	return min + rand() % (max - min);
}

void clearCin() {
	//clear cin
	if (char(std::cin.peek()) == '\n')
		std::cin.ignore();
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}
}

void stack_is_empty() {
	std::cout << red << "  STACK IS EMPTY!!!";
}

void elem_was_added_to_stack(__int64 elem) {
	std::cout << azure << elem << " - was added to stack";
}

void setIsEmpty() {
	std::cout << red << " SET IS EMPTY!!!";
}
