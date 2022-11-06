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
#include <vector>
#include <list>
#include <algorithm>
#include "additionalfunctions.h"


void enter(int& count) { std::cout << std::endl; count = 0; }
void space() { std::cout << "    "; }

void Display(std::vector<int>& temp) {
	std::cout << "=================" << std::endl;
	int count = 0;
	for (auto _this : temp) {
		std::cout << _this << std::endl;
		count++;
		//checkForSpace(_this, count);
	}
	std::cout << "=================" << std::endl;
}

void reverseDisplay(std::vector<int>& temp) {
	std::cout << "=================" << std::endl;
	for (auto _this = temp.crbegin(); _this != temp.crend(); _this++) {
		std::cout << *_this << std::endl;
	}
	std::cout << "=================" << std::endl;
}



//1
void vectorElemToNULL(std::vector<int>& temp) {
	std::vector<int> vec(20, 0);
	temp = vec;
}

//2
void completion(std::vector<int>& temp) {
	std::cout << "=================" << std::endl;
	for (auto _this = begin(temp); _this != end(temp); _this++) {
		(*_this) = getRandom();
		std::cout << *_this << std::endl;
	}
	std::cout << "=================" << std::endl;
}

//6
void restructVec(std::vector<int>& temp) {
	for (auto _this = begin(temp); _this != end(temp); _this++) {
		if (*_this < 10) { *_this = 0; }
	}
}

//7
void selectionPrintVec(std::vector<int>& temp) {
	std::cout << "=================" << std::endl;
	for (auto _this = begin(temp); _this != end(temp); _this++) {
		if (*_this > 20) {
			std::cout << *_this << std::endl;
		}
	}
	std::cout << "=================" << std::endl;
}

//8
void findParityToMultiplication(std::vector<int>& temp) {
	for (auto _this = begin(temp); _this != end(temp); _this++) {
		if (!(*_this & 1)) { *_this *= 3; }
	}
}

//10
void selectionDeleteElemFromVec(std::vector<int>& temp) {
	int n = 0;
	while (true) {
		for (auto _this = begin(temp); _this != end(temp); _this++) {
			if (*_this > 50) {
				temp.erase(_this);
				break;
			}
			n++;
		}
		if (n == temp.size()) { break; }
		n = 0;
	}
}

void function11iftrue(std::vector<int>& temp) {
	temp.pop_back();
	Display(temp);
}

//11
void Function11(std::vector<int>& temp) {
	std::cout << "=================" << std::endl;
	std::cout << "size : " << temp.size() << std::endl;
	temp.size() & 1 ? function11iftrue(temp) : reverseDisplay(temp);
}
