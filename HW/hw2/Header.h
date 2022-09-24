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
#include <stdlib.h>

enum class status {
	_public,
	_protected,
	_private
};

std::vector<std::pair<float, status>> mainvec = {
	{134.0, status::_protected},
	{157454.0, status::_private},
	{32.0, status::_private},
	{234.32, status::_public}
};

void completion() {
	for (auto _this = begin(mainvec); _this != end(mainvec); _this++) {
		(*_this).first = rand() % 10;
		int statusRand = rand() % 3;
		if (statusRand == 0) { (*_this).second = status::_public; }
		else if (statusRand == 1) { (*_this).second = status::_protected; }
		else { (*_this).second = status::_private; }
	}
}

std::string StatusEnumToStr(status s) {
	return s == status::_public ? "public" : s == status::_protected ? "protected" : "private";
}

void print() {
	std::cout << "==================================" << std::endl;
	for (auto n : mainvec) {
		std::cout << "Number: " << n.first << " | Status: " << StatusEnumToStr(n.second) << std::endl;
	}
	std::cout << "==================================" << std::endl;
}

void rebuildVec() {
	auto rebuild = [](auto& _this) {
		if (_this.second == status::_public) {
			_this.first = 0;
		}
		else if (_this.second == status::_protected) {
			_this.second = status::_private;
		}
	};
	for (auto& _this : mainvec) { rebuild(_this); }
}
