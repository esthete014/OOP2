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


void printList(std::list<int> a) {
	std::cout << "=====" << std::endl;
	for (auto elem : a) {
		std::cout << elem << std::endl;
	}
	std::cout << "=====" << std::endl;
}

void message_list_havent_elem(int count) {
	std::cout << red << "LIST SIZE LESS THAN " << count << "!!!" << std::endl;
}
