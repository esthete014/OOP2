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
#include "matrix.h"
#include "color.h"
#include <functional>
#include <ctime>
using namespace std::placeholders;


int getRandom() { return -100 + rand() % 201; }

struct ENGINE {
	std::vector<MATRIX> usersMatrixes;
	std::vector<std::function<void()>> functions;

	void fillFunctions();

	bool PrintAllMatrixes();
	void PrintMatrix(MATRIX &matrix);
	int chooseMatrixX1();
	std::pair<int, int> chooseMatrixX2();

	void func_1();
	void func_2();
	void func_3();
	void func_4();
	void func_5();
	void func_6();
};
void ENGINE::fillFunctions() {
	this->functions.emplace_back(std::bind(func_1));
	this->functions.emplace_back(std::bind(func_2));
	this->functions.emplace_back(std::bind(func_3));
	this->functions.emplace_back(std::bind(func_4));
	this->functions.emplace_back(std::bind(func_5));
	this->functions.emplace_back(std::bind(func_6));
}
bool ENGINE::PrintAllMatrixes() {
	if (usersMatrixes.size() == 0) { std::cout << red << "You didn't create nomatrix!!!"; return false; }
	else {
		int i = 0;
		for (auto& elem : usersMatrixes) { i++; std::cout << "<" << i << ">" << std::endl; PrintMatrix(elem); }
		return true;
	}
}
void ENGINE::PrintMatrix(MATRIX &matrix) {
	//for (int i = 0; i < matrix.maxsize(); i++) { std::cout << "-"; }
	std::cout << "====================";
	for (auto& line : matrix.matrix) {
		for (auto &elem : line) {
			std::cout << elem;
		}
	}
	std::cout << "====================";
}
int ENGINE::chooseMatrixX1() {
	int temp;
	std::cout << green << "Which matrix you want to use?" << std::endl;
	std::cin >> temp;
	return temp;
}
std::pair<int, int> ENGINE::chooseMatrixX2() {
	std::pair<int, int> temp;
	std::cout << green << "Which two matrixes you want to use?" << std::endl << "First: ";
	std::cin >> temp.first;
	std::cout << "Second: ";
	std::cin >> temp.second;
	return temp;
}
void ENGINE::func_1() {
	usersMatrixes.push_back(MATRIX());
}
void ENGINE::func_2() {
	PrintAllMatrixes();
	std::pair<int, int> choose = chooseMatrixX2();
	usersMatrixes[choose.first] += usersMatrixes[choose.second];
	PrintMatrix(usersMatrixes[choose.first]);
}
void ENGINE::func_3() {
	PrintAllMatrixes();
	std::pair<int, int> choose = chooseMatrixX2();
	usersMatrixes[choose.first] -= usersMatrixes[choose.second];
	PrintMatrix(usersMatrixes[choose.first]);
}
void ENGINE::func_4() {
	PrintAllMatrixes();
	std::pair<int, int> choose = chooseMatrixX2();
	usersMatrixes[choose.first] *= usersMatrixes[choose.second];
	PrintMatrix(usersMatrixes[choose.first]);
}
void ENGINE::func_5() {
	PrintAllMatrixes();
	int choose = chooseMatrixX1();
	std::vector<long long> tempvec = { getRandom(), getRandom(), getRandom(), getRandom(), getRandom() };
	usersMatrixes[choose] *= tempvec;
	PrintMatrix(usersMatrixes[choose]);
}
void ENGINE::func_6() {
	PrintAllMatrixes();
	int choose = chooseMatrixX1();
	usersMatrixes[choose].transpose();
	PrintMatrix(usersMatrixes[choose]);
}
