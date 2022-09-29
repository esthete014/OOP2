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
#include <conio.h>
#include "functions.h"
#include "phrasessource.h"

class PHRASE {
private:
	std::vector<std::pair<std::string, std::vector<std::string>>> ALLPHRASES;
	void fillALLPHRASESvec(std::vector < std::pair<std::string, std::vector<std::string>>>& ALLPHRASES);
	void couttitle(std::string title);
public:
	std::vector<std::pair<std::string, std::vector<std::string>>> getALLPHRASES();
	PHRASE() { fillALLPHRASESvec(ALLPHRASES); }
	void phrase_high();
	void phrase_average(int numberoftask, int pos);
	void phrase_low(int numberoftask, int id);

	int TESTRETURNGAVNO(int numberoftask);
};

void PHRASE::fillALLPHRASESvec(std::vector < std::pair<std::string, std::vector<std::string>>> &ALLPHRASES) {
	ALLPHRASES = { {title1, phrase1source}, {title2, phrase2source}, {title3, phrase3source}, {title4, phrase4source} };
}

void PHRASE::couttitle(std::string title) {
	std::cout
		<< blue
		<< title
		<< std::endl;
}

std::vector<std::pair<std::string, std::vector<std::string>>> PHRASE::getALLPHRASES() {	return ALLPHRASES; }

void PHRASE::phrase_high() {
	system("cls");
	std::cout << blue << " <| TASKS |>" << green << std::endl;
	for (int i = 0; i < ALLPHRASES.size(); i++) {
		std::cout << " " << i + 1 << "." << ALLPHRASES[i].first << std::endl;
	}
	std::cout << white << std::endl;
}

int PHRASE::TESTRETURNGAVNO(int numberoftask) {
	return ALLPHRASES[numberoftask].second.size();
}

void PHRASE::phrase_average(int numberoftask, int pos) {
	system("cls");
	ALLPHRASES[numberoftask].first.size() != 0 ? couttitle(ALLPHRASES[numberoftask].first) : void();
	int n = 1;
	std::cout << green;
	if (TESTRETURNGAVNO(numberoftask) >= 10) {
		for (auto _this = begin(ALLPHRASES[numberoftask].second) + pos; _this != begin(ALLPHRASES[numberoftask].second) + pos + 9; _this++) {
			if (_this == ALLPHRASES[numberoftask].second.end()) break;
			std::cout << n << "." << *_this << std::endl;
			n++;
		}
	}
	else {
		for (auto _this = begin(ALLPHRASES[numberoftask].second); _this != end(ALLPHRASES[numberoftask].second); _this++) {
			if (_this == ALLPHRASES[numberoftask].second.end()) break;
			std::cout << n << "." << *_this << std::endl;
			n++;
		}
	}
	std::cout << white;
}

void PHRASE::phrase_low(int numberoftask, int id) {
	std::cout
		<< blue << id + 1 << "."
		<< green << ALLPHRASES[numberoftask].second[id] << azure << std::endl;
}
