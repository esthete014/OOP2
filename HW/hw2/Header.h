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
