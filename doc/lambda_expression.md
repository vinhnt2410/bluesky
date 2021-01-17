## Lambda Expression

Lambda Expression hay còn gọi là Lambda (từ C++ 11), là một cách thuận tiện để tạo ra một anonymous function object.
Function object này có thể được sử dụng tại local hoặc có thể được pass như một đối số cho các functions hay methods

### Cách hay sử dụng nhất của lambda là như sau:

```
int y = 5;
auto lambda_exam = [&] (int x) {
	// Do somethings
	return x + y;
}
```

Ký hiệu `[&]` sẽ pass các tham số của hàm như là một tham chiếu.


Lambda làm giảm các dòng code, thay vì khai báo và sử dụng một function object thì có thể sử dụng lambda

```
// Sử dụng function object
class FuncObject
{
public:
	int operator() (std::string s) {
		std::cout << "Hello " << s << ", I am a function object" << std::endl;
		return 0;
	}
};
FuncObject HelloFuncObject;
HelloFuncObject("world!");

// Sử dụng lambda
auto hello_lambda = [] (std::string s) {
	std::cout << "Hello " << s << " I am a lambda expression" << std::endl;
};
hello_lambda("world!");
```

### Lambda sử dụng như một đối số function object để pass vào hàm hoặc method

