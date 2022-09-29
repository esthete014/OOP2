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
#include "color.h"
#include <Windows.h>
#include "phrases.h"
#include <conio.h>
#include <ctime>
#include "functions.h"


PHRASE phrase;
std::vector<std::vector<std::function<void(int)>>> FUNCTIONS;

class MENU {
public:
	MENU();
private:
	int id = 0;
	int pos = 0;
	void fillFUNCTIONS(std::vector<std::vector<std::function<void(int)>>>& FUNCTIONS);
	enum keyreturn;
	keyreturn GetKEY(int count);
	void bordMenu();
	void menu_high();

	void menu_average(int task);
	void menu_average_function(int numberoftask, int id);

	void menu_low(int task, int id);


};

MENU::MENU() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	fillKEYS();
	Blinking(false);
	fillFunctions1();
	fillFunctions2();
	fillFunctions3();
	fillFunctions4();
	fillFUNCTIONS(FUNCTIONS);
	phrase = PHRASE();
	bordMenu();
}

void MENU::fillFUNCTIONS(std::vector<std::vector<std::function<void(int)>>>& FUNCTIONS) {
	FUNCTIONS = { functions1, functions2, functions3, functions4 };
}

enum MENU::keyreturn {
	type_high,
	type_average,
	type_low
};

MENU::keyreturn MENU::GetKEY(int count) {
	count -= 9;
	while (true) {
		filmSteal();
		_getch();
		if ((GetAsyncKeyState('S') || GetAsyncKeyState('D')) && pos < count) {
			pos++; return MENU::keyreturn::type_average;
		}
		else if ((GetAsyncKeyState('S') || GetAsyncKeyState('D')) && pos == count) {
			pos = 0; return MENU::keyreturn::type_average;
		}
		else if ((GetAsyncKeyState('W') || GetAsyncKeyState('A')) && pos > 0) {
			pos--; return MENU::keyreturn::type_average;
		}
		else if ((GetAsyncKeyState('W') || GetAsyncKeyState('A')) && pos == 0) {
			pos = count; return MENU::keyreturn::type_average;
		}
		for (int i = 1; i < count + 10; i++) {
			if (GetAsyncKeyState(char(i + 48))) {
				id = i + pos;
				return MENU::keyreturn::type_low;
			}
		}
		if (GetAsyncKeyState(VK_SPACE)) { return MENU::keyreturn::type_high; }
	}
}

void MENU::bordMenu() {
	std::cout
		<< azure
		<< "  / ============================= \\ " << std::endl
		<< "  | -------  esthete014  -------- | " << std::endl
		<< "  | ============================= | " << std::endl
		<< "  |     || copyright 2022 ||      | " << std::endl
		<< "  |     || Nikolay        ||      | " << std::endl
		<< "  |     || Kochetov       ||      | " << std::endl
		<< "  | _____________________________ | " << std::endl
		<< "  | https://github.com/esthete014 | " << std::endl
		<< "  \\ ============================= / " << std::endl
		<< std::endl
		<< blue
		<< "  (press 'E' to go to website or Space to continue)" << white << std::endl;
	_getch();
	GetAsyncKeyState('E') ? system("start https://github.com/esthete014") : NULL;
	menu_high();
};

void MENU::menu_high() {
	phrase.phrase_high();
	id, pos = 0;
	filmSteal();
	_getch();//universal
	GetAsyncKeyState('1') ? menu_average(0)
		: GetAsyncKeyState('2') ? menu_average(1)
		: GetAsyncKeyState('3') ? menu_average(2)
		: GetAsyncKeyState('4') ? menu_average(3)
		: exit(NULL);
}

void MENU::menu_average(int task) {
	id = 0;
	phrase.phrase_average(task, pos);
	keyreturn _return = GetKEY(phrase.getALLPHRASES()[task].second.size());
	_return == keyreturn::type_high ? menu_high() : _return == keyreturn::type_average ? menu_average(task) : menu_low(task, id);
}

void MENU::menu_average_function(int numberoftask, int id) {
	int i = 0;
	for (const auto& fn : FUNCTIONS[numberoftask]) {
		if (i == id) { fn(id); break; }
		i++;
	}
	std::cout << white;
	_getch();
}

void MENU::menu_low(int task, int id) {
	system("cls");
	phrase.phrase_low(task, id - 1);
	menu_average_function(task, id - 1);
	filmSteal();
	menu_average(task);
}
