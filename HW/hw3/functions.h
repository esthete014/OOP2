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
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include "firsttask.h"
#include "secondtask.h"
#include "thirdtask.h"
#include "fourthtask.h"

using namespace std::placeholders;



std::vector<std::function<void(int)>> functions1;
std::vector<std::function<void(int)>> functions2;
std::vector<std::function<void(int)>> functions3;
std::vector<std::function<void(int)>> functions4;

/// <summary>
/// MAIN vector which will be using in first task
/// </summary>
std::vector<int> mainvec(20, 0);
/// <summary>
/// MAIN list which will be using in second task
/// </summary>
std::list<int> mainlist;
/// <summary>
/// MAIN stack which will be using in trird task
/// </summary>
std::stack<__int64> mainstack;
/// <summary>
/// MAIN sets which will be using in fourth task
/// </summary>
std::set<int> mainsetA;
std::set<int> mainsetB;


void func1_1() { vectorElemToNULL(mainvec); Display(mainvec); }

void func1_2() { completion(mainvec); }

void func1_3() {
	if (mainvec.size() > 0) {
		std::cout << "Max elem: " << *max_element(mainvec.begin(), mainvec.end()) << std::endl;
		std::cout << "Min elem: " << *min_element(mainvec.begin(), mainvec.end()) << std::endl;
	}
	else { std::cout << red << "SIZE LESS THAN 1!!!"; }
}

void func1_4() { std::sort(mainvec.begin(), mainvec.end()); Display(mainvec); }

void func1_5() {
	std::vector<int> temp = { getRandom(), getRandom(), getRandom(), getRandom() };
	mainvec.insert(mainvec.end(), temp.begin(), temp.end());
	Display(mainvec);
}

void func1_6() { restructVec(mainvec); Display(mainvec); }

void func1_7() { selectionPrintVec(mainvec); }

void func1_8() { findParityToMultiplication(mainvec); Display(mainvec); }

void func1_9() { std::random_shuffle(mainvec.begin(), mainvec.end()); Display(mainvec); }

void func1_10() { selectionDeleteElemFromVec(mainvec); Display(mainvec); }

void func1_11() { Function11(mainvec); }

void func1_12() { mainvec.resize(0); Display(mainvec); }

void fillFunctions1() {
	functions1.emplace_back(std::bind(func1_1));
	functions1.emplace_back(std::bind(func1_2));
	functions1.emplace_back(std::bind(func1_3));
	functions1.emplace_back(std::bind(func1_4));
	functions1.emplace_back(std::bind(func1_5));
	functions1.emplace_back(std::bind(func1_6));
	functions1.emplace_back(std::bind(func1_7));
	functions1.emplace_back(std::bind(func1_8));
	functions1.emplace_back(std::bind(func1_9));
	functions1.emplace_back(std::bind(func1_10));
	functions1.emplace_back(std::bind(func1_11));
	functions1.emplace_back(std::bind(func1_12));
}




void func2_1() { mainlist.clear(); printList(mainlist); }

void func2_2() {
	std::list<int> temp = { getRandom(), getRandom(), getRandom(), getRandom(), getRandom() };
	mainlist.insert(mainlist.end(), temp.begin(), temp.end());
	printList(mainlist);
}

void func2_3() { std::cout << mainlist.front() << std::endl; }

void func2_4() { true ? mainlist.push_front(getRandom()), mainlist.push_front(getRandom()) : void(); printList(mainlist); } //da da ya

void func2_5() { if (mainlist.size() > 4) { mainlist.erase(++(++(++begin(mainlist)))); } else { message_list_havent_elem(4); } printList(mainlist); } //vo prikol

void func2_6() {
	if (mainlist.size() > 3) {
		auto s = --(--(mainlist.end()));
		int x = 3;
		for (auto e = mainlist.begin(); e != mainlist.end(); e++) {
			if (e == s) {
				size_t d = x;
				mainlist.insert(e, d, 15);
				break;
			}
			else if (rand() % 2 == 1 && x > 0) {
				x--;
				mainlist.insert(e, size_t(1), 15);
			}
		}
	}
	else {
		message_list_havent_elem(4);
	}
	printList(mainlist);
}

void func2_7() { if (mainlist.size() > 0) { mainlist.pop_back(); } else { message_list_havent_elem(1); } printList(mainlist); }

void func2_8() { if (mainlist.size() > 0) { mainlist.pop_front(); } else { message_list_havent_elem(1); } printList(mainlist); }

void func2_9() {
	int l = mainlist.size();
	auto e = mainlist.begin();
	for (int i = 0; i < l * 0.5; i++) e++;
	mainlist.insert(e, size_t(2), getRandom());
	printList(mainlist);
}

void func2_10() {
	mainlist.sort();
	mainlist.unique();
	printList(mainlist);
}

void func2_11() { mainlist.clear(); printList(mainlist); }

void func2_12() {
	if (mainlist.size() == 0) {
		std::cout << "LIST CLEAR" << std::endl;
	}
	else { std::cout << "<LIST SIZE: " << mainlist.size() << "!!!>" << std::endl; }
	printList(mainlist);
}

void fillFunctions2() {
	functions2.emplace_back(std::bind(func2_1));
	functions2.emplace_back(std::bind(func2_2));
	functions2.emplace_back(std::bind(func2_3));
	functions2.emplace_back(std::bind(func2_4));
	functions2.emplace_back(std::bind(func2_5));
	functions2.emplace_back(std::bind(func2_6));
	functions2.emplace_back(std::bind(func2_7));
	functions2.emplace_back(std::bind(func2_8));
	functions2.emplace_back(std::bind(func2_9));
	functions2.emplace_back(std::bind(func2_10));
	functions2.emplace_back(std::bind(func2_11));
	functions2.emplace_back(std::bind(func2_12));
}




void func3_1() { mainstack.push(enter_number()); elem_was_added_to_stack(mainstack.top()); }

void func3_2() { mainstack.size() > 0 ? deleteElemInStack(mainstack) : stack_is_empty(); }

void func3_3() { printStack(mainstack); }

void func3_4() { clear_stack(mainstack); std::cout << " Stack cleared!"; }

void fillFunctions3() {
	functions3.emplace_back(std::bind(func3_1));
	functions3.emplace_back(std::bind(func3_2));
	functions3.emplace_back(std::bind(func3_3));
	functions3.emplace_back(std::bind(func3_4));
}




void func4_1() { fillsets(); }

void func4_2() { mainsetA.size() != 0 && mainsetB.size() != 0 ? printSet(intersectionOfSets()) : setIsEmpty(); }

void func4_3() { mainsetA.size() != 0 && mainsetB.size() != 0 ? printSet(unificationOfSets()) : setIsEmpty(); }

void func4_4() { mainsetA.size() != 0 && mainsetB.size() != 0 ? printSet(differenceOfSets()) : setIsEmpty(); }

void func4_5() { mainsetA.size() != 0 && mainsetB.size() != 0 ? printSet(additionOfSet()) : setIsEmpty(); }

void fillFunctions4() {
	functions4.emplace_back(std::bind(func4_1));
	functions4.emplace_back(std::bind(func4_2));
	functions4.emplace_back(std::bind(func4_3));
	functions4.emplace_back(std::bind(func4_4));
	functions4.emplace_back(std::bind(func4_5));
}
