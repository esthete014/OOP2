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
	Coordinates<int, int> a;
	Coordinates<int, int> b;
	Coordinates<int, int> c;
	
	a = Coordinates<int, int>(3, 6.9);
	b = Coordinates<int, int>(7, 1);
	c = Coordinates<int, int>(2, 0);

	a = b + c;
	std::cout << a;
	a.Swap();
	std::cout << a;
	a.Swap(b);
	std::cout << b;

	return 0;
}