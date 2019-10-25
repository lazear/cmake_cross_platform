#include <iostream>

class Test {
public:
	Test() : drops(1) {}
	~Test() {
		std::cout << "drop!\n";
	}
	void bar();
private:
	int drops;
};