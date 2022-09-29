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
#include "additionalfunctions.h"
#include "color.h"
#include <iostream>
#include <stack>
#include <conio.h>


#define key_E 69
#define key_e 101
#define keyENTER 13
#define keyBACKSPACE 8


//1
__int64 enter_number() {
	__int64 number = 0;
	int KEYINPUT;
	while (true) {
		system("cls");
		std::cout
			<< violet << " Use keyboard to enter numbers and \"E\" or ENTER to confirm number" << std::endl
			<< "!!!pay attention, it only works on the English layout!!!" << std::endl // i know how to do for Ru layout. I don't want to do this
			<< azure << number << white << std::endl;
		KEYINPUT = _getch();
		if (KEYINPUT == keyBACKSPACE) {
			number /= 10;
		}
		if (number < 99999999999999999) {
			for (auto key : KEYS) { key == KEYINPUT ? (number *= 10), (number += (key - 48)) : NULL; }
		}
		if (KEYINPUT == key_E || KEYINPUT == key_e || KEYINPUT == keyENTER) { system("cls"); return number; }
	}
}

//2
void deleteElemInStack(std::stack<__int64>& mainstack) {
	std::cout << mainstack.top() << red << " - was deleted";
	mainstack.pop();
}

int getMaxLenOfNumberInStack(std::stack<__int64> stack) {
	__int64 maxinstack = 0;
	__int64 len = stack.size();
	for (int i = 0; i < len; i++) { if (maxinstack < stack.top()) maxinstack = stack.top();	stack.pop(); }
	int maxlen = 0;
	while (maxinstack > 0) { maxinstack /= 10; maxlen++; }
	return maxlen;
}
//3
void printStack(std::stack<__int64> mainstack) {
	if (mainstack.size() > 0) {
		std::stack<__int64> temp;
		temp = mainstack;
		int MaxLenOfNumberInStack = getMaxLenOfNumberInStack(temp);
		std::cout << "| ";
		for (int i = 0; i < MaxLenOfNumberInStack; i++) { std::cout << " "; }
		if (MaxLenOfNumberInStack == 0) std::cout << " ";
		std::cout << " |" << std::endl;
		__int64 len = mainstack.size();
		for (int i = 0; i < len; i++) {
			temp.push(mainstack.top());
			__int64 tempNum = mainstack.top();
			std::cout << "| ";
			int lenNum = 0;
			if (tempNum == 0) {
				lenNum = 1;
			}
			else {
				while (tempNum > 0) {
					tempNum /= 10;
					lenNum++;
				}
			}
			for (int i = 0; i < MaxLenOfNumberInStack - lenNum; i++) {
				std::cout << " ";
			}
			std::cout << mainstack.top();
			std::cout << " |" << std::endl;
			mainstack.pop();

		}
		for (int i = 0; i < MaxLenOfNumberInStack + 5; i++) {
			std::cout << "-";
		}
	}
	else {
		stack_is_empty();
	}

}

//4
void clear_stack(std::stack<__int64>& mainstack) {
	__int64 len = mainstack.size();
	for (__int64 i = 0; i < len; i++) {
		mainstack.pop();
	}
}