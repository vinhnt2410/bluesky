#include <iostream>
#include <string.h>

#include "lambda_expression.hpp"


auto hello_lambda = [] (std::string s) {
	std::cout << "Hello " << s << " I am a lambda expression" << std::endl;
};

// CallbackCalculation::CalculateExec = [] (int, int) -> int {};

int main()
{
	hello_lambda("World!");
	hello_lambda("Vinh!");

	FuncObject HelloFuncObject;
	HelloFuncObject("Lambda!");

	int y = 5;
	auto lambda_exam = [&] (int x) {
		return x + y;
	};

	std::cout << "The result: " << lambda_exam(4) << std::endl;


	auto lsum = [] (int a, int b) {
		return a + b;
	};
	auto lsub = [] (int a, int b) {
		return a - b;
	};

	CallbackCalculation aCal(3, 5);
	aCal.SetCallback(lsum);
	std::cout << "Sum = " << aCal.Calculate() << std::endl;

	aCal.SetCallback(lsub);
	std::cout << "Sub = " << aCal.Calculate() << std::endl;

	std::cout << "Call lsum: sum = " << lsum(3, 5) << std::endl;

	return 0;
}