#include <iostream>
#include <string.h>

auto hello_lambda = [] (std::string s) {
	std::cout << "Hello, " << s << std::endl;
};

int main()
{
	hello_lambda("World!");
	hello_lambda("Vinh!");

	return 0;
}