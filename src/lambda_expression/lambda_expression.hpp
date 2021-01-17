#include <iostream>
#include <string>
#include <functional>

class FuncObject
{
public:
	int operator() (std::string s) {
		std::cout << "Hello " << s << ", I am a function object" << std::endl;
		return 0;
	}
};


class CallbackCalculation
{
public:
	CallbackCalculation(int x, int y) : x_(x), y_(y) {}

	using functioner_t = std::function< int(int, int) >;

	functioner_t CalculateExec = [] (int , int) -> int {};

	void SetCallback(functioner_t f)
	{
		CalculateExec = std::move(f);
	}
	int Calculate()
	{
		return CalculateExec(x_, y_);
	}
private:
	int x_;
	int y_;
};