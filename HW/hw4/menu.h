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
#include "engine.h"
#include <conio.h>

void Blinking(bool flag) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	flag == false ? structCursorInfo.bVisible = FALSE : structCursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

std::vector<int> KEYS;
void fillKEYS() { for (int i = 0; i < 10; i++) { KEYS.push_back(i + 48); } }


class MENU {
public:
	MENU();
private:
	ENGINE engine;
	void PrintTasks();
	int chooseTask(int count);
	void runFunction(int N);
};
MENU::MENU() {
	Blinking(false);
	srand(time(0));
	fillKEYS();
	engine = ENGINE();
	engine.fillFunctions();
	PrintTasks();
}
void MENU::PrintTasks() {
	/*bool matrixExist;
	engine.usersMatrixes.size() == 0 ? matrixExist = false : matrixExist = true;*/
	std::cout << green << " 1. Create new matrix" << std::endl;
	//engine.usersMatrixes.size() == 0 ? std::cout << red : std::cout << green;
	engine.usersMatrixes.size() < 2 ? std::cout << red : std::cout << green;
	std::cout << " 2. Addition" << std::endl;
	std::cout << " 3. Subtraction" << std::endl;
	std::cout << " 4. Multiply by matrix" << std::endl;
	engine.usersMatrixes.size() == 0 ? std::cout << red : std::cout << green;
	std::cout << " 5. Multiply by vector" << std::endl;
	std::cout << " 6. Transpose" << azure << std::endl;
	int choose = chooseTask(engine.usersMatrixes.size());
	choose == 0 ? exit(NULL) : runFunction(choose);
}
int MENU::chooseTask(int count) {
	while (true) {
		int KEYINPUT = _getch();
		if (count == 0 && KEYINPUT == KEYS[1]) {
			return 1;
		}
		if (count > 0) {
			if (KEYINPUT == KEYS[1] || KEYINPUT == KEYS[5] || KEYINPUT == KEYS[6]) {
				return KEYINPUT;
			}
		}
		if (count > 1) {
			for (int i = 1; i < 7; i++) {
				if (KEYINPUT == KEYS[i]) { return i; }
			}
		}
		if (KEYINPUT == VK_SPACE) { return 0; }
	}
}
void MENU::runFunction(int N) {
	int i = 0;
	for (const auto& fn : engine.functions) {
		if (i == N - 1) { fn(); break; }
		i++;
	}
	_getch();
}
