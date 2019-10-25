#include <iostream>
#include "testfile.h"


void Test::bar() {
	std::cout << "Test::bar()\n";
}

int Test::get_drops() {
	return drops;
}