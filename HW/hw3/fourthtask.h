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
#include "functions.h"
#include <set>

extern std::set<int> mainsetA;
extern std::set<int> mainsetB;


void printSet(std::set<int> set) {
	for (auto elem : set) {
		std::cout << "| ";
		elem >= 10 ? std::cout << " " : std::cout << "  ";
		std::cout << elem << " |" << std::endl;
	}
}

void fillsets() {
	for (int i = 0; i < 20; i++) {
		mainsetA.insert(rand() % 50 + 1);
		mainsetB.insert(rand() % 50 + 1);
	}
	std::cout << "MainSetA = " << std::endl;
	printSet(mainsetA);
	std::cout << "MainSetB = " << std::endl;
	printSet(mainsetB);
}

std::set<int> intersectionOfSets() {
	std::set<int> temp;
	for (auto elemA : mainsetA) {
		for (auto elemB : mainsetB) {
			if (elemA == elemB) { temp.insert(elemA); break; }
		}
	}
	return temp;
}

std::set<int> unificationOfSets() {
	std::set<int> temp;
	for (auto &elem : mainsetA) { temp.insert(elem); }
	for (auto &elem : mainsetB) { temp.insert(elem); }
	return temp;
}

std::set<int> differenceOfSets() {
	std::set<int> temp;
	for (auto elemA : mainsetA) {
		bool wasIt = false;
		for (auto elemB : mainsetB) {
			if (elemA == elemB) { wasIt++; break; }
		}
		if (!wasIt) temp.insert(elemA);
	}
	return temp;
}

std::set<int> choose_set() {
	int KEYINPUT;
	std::set<int> set;
	while (true) {
		std::cout
			<< "For which one exactly?" << std::endl
			<< "1 - to use MainSetA" << std::endl
			<< "2 - to use MainSetB" << std::endl;
		KEYINPUT = _getch();
		if (KEYINPUT == 49) { return mainsetA; }
		if (KEYINPUT == 50) { return mainsetB; }
	}
}
std::set<int> additionOfSet() {
	std::set<int> set = choose_set();
	std::set<int> temp;
	for (int i = 0; i < 51; i++) {
		bool wasIt = false;
		for (auto elem : set) {
			if (elem == i) { wasIt = true; }
		}
		if (!wasIt) { temp.insert(i); }
	}
	return temp;
}