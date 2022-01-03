#include <codecvt>
#include <iostream>

#pragma once
class Main
{
public:
	int main();

	~Main() {
		int leak = _CrtDumpMemoryLeaks();
		std::cout << "Leak: " << leak << std::endl;
	}
};
