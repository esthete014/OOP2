// / ============================= \
// | -------  esthete014  -------- |
// | ============================= |
// |     || copyright 2022 ||      |
// |     || Nikolay        ||      |
// |     || Kochetov       ||      |
// | _____________________________ |
// | https://github.com/esthete014 |
// \ ============================= /


#include "Header.h"


int main() {
	Coordinates a;
	Coordinates b;
	Coordinates c;

	a = Coordinates(3, 6);
	b = Coordinates(7, 1);
	c = Coordinates(2, 0);

	a = b + c;
	a.Swap();
	std::cout << a;
	a.Swap(b);
	std::cout << b;

	return 0;
}